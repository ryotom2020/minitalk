/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:45:26 by rtomiki           #+#    #+#             */
/*   Updated: 2021/08/03 22:15:42 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define BUFF 1024

struct s_info
{
	char	message[BUFF];
	int		bytes;
	int		bits;
	int		received_all;
	int		received_remained;

	int		pid;
};

struct s_info	g_signal_info;

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

void	setbit_one(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)context;
	(void)siginfo;
	if (!g_signal_info.bits)
	{
		g_signal_info.bits = 1 << 6;
		g_signal_info.bytes ++;
	}
	g_signal_info.message[g_signal_info.bytes] += g_signal_info.bits;
	g_signal_info.bits = g_signal_info.bits >> 1;
	if (g_signal_info.bytes == BUFF - 1 && !g_signal_info.bits)
	{
		g_signal_info.received_remained = 1;
		g_signal_info.bytes = 0;
	}
}

void	setbit_zero(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)context;
	if (!g_signal_info.bits)
	{
		g_signal_info.bits = 1 << 6;
		g_signal_info.bytes ++;
	}
	g_signal_info.bits = g_signal_info.bits >> 1;
	if (g_signal_info.message[g_signal_info.bytes] == '\0'
		&& g_signal_info.bits == 0)
	{
		g_signal_info.received_all = 1;
		kill(siginfo->si_pid, SIGUSR1);
	}
	else if (g_signal_info.bytes == BUFF - 1 && !g_signal_info.bits)
	{
		g_signal_info.received_remained = 1;
		g_signal_info.bytes = 0;
	}
}

void	run_server(void)
{
	g_signal_info.bits = 1 << 6;
	g_signal_info.bytes = 0;
	g_signal_info.received_all = 0;
	g_signal_info.received_remained = 0;
	ft_bzero(g_signal_info.message, BUFF);
	while (1)
	{
		pause();
		if (g_signal_info.received_all || g_signal_info.received_remained)
		{
			ft_putstr_fd(g_signal_info.message, 1);
			if (g_signal_info.received_all)
				write(1, "\n", 1);
			g_signal_info.bits = 1 << 6;
			g_signal_info.bytes = 0;
			g_signal_info.received_all = 0;
			g_signal_info.received_remained = 0;
			ft_bzero(g_signal_info.message, BUFF);
		}
	}
}

int	main(void)
{
	struct sigaction	sa_sigusr1;
	struct sigaction	sa_sigusr2;

	print_pid();
	sa_sigusr1.sa_sigaction = setbit_one;
	sa_sigusr2.sa_sigaction = setbit_zero;
	sa_sigusr1.sa_flags = SA_SIGINFO;
	sa_sigusr2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_sigusr1, NULL);
	sigaction(SIGUSR2, &sa_sigusr2, NULL);
	run_server();
	return (0);
}
