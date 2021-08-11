/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:06:48 by rtomiki           #+#    #+#             */
/*   Updated: 2021/08/03 22:15:28 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	end_success(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)siginfo;
	(void)context;
	ft_putstr_fd("Message has been successfully sent\n", 1);
}

void	send_character(int pid, char character)
{
	int	i;

	i = 1 << 6;
	while (i > 0)
	{
		if (character & i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("error: invalid PID\n", 1);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("error: invalid PID\n", 1);
				exit(1);
			}
		}
		i = i >> 1;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_client;
	int					pid;
	int					cnt;

	if (argc != 3)
	{
		ft_putstr_fd("error: invalid arguments\n", 1);
		exit(1);
	}
	sa_client.sa_sigaction = end_success;
	sa_client.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_client, NULL);
	pid = ft_atoi(argv[1]);
	cnt = 0;
	while (argv[2][cnt] != '\0')
	{
		send_character(pid, argv[2][cnt]);
		cnt++;
	}
	send_character(pid, '\0');
	return (0);
}
