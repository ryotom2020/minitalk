/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:36:01 by rtomiki           #+#    #+#             */
/*   Updated: 2021/04/13 13:32:11 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nb)
{
	if (nb == -2147483648)
		return (ft_abs(-2147483647));
	if (nb < 0)
		return (-1 * nb);
	return (nb);
}

static int	ft_intlen(int nb)
{
	int	cnt;

	cnt = 0;
	while (nb / 10 > 0)
	{
		nb /= 10;
		cnt++;
	}
	return (cnt + 1);
}

char	*ft_itoa(int nb)
{
	int		sign;
	int		len;
	char	*ptr;

	if (nb < 0)
		sign = 1;
	else
		sign = 0;
	len = ft_intlen(ft_abs(nb)) + sign;
	ptr = malloc(sizeof(char) * len + 1);
	if (!(ptr))
		return (NULL);
	ptr[len] = '\0';
	while (--len >= sign)
	{
		ptr[len] = ft_abs(nb % 10) + '0';
		nb /= 10;
	}
	if (len == 0)
		ptr[len] = '-';
	return (ptr);
}
