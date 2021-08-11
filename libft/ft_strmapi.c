/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:27:23 by rtomiki           #+#    #+#             */
/*   Updated: 2021/04/13 13:26:54 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	cnt;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(ptr))
		return (NULL);
	cnt = 0;
	while (s[cnt])
	{
		ptr[cnt] = f(cnt, s[cnt]);
		cnt++;
	}
	ptr[cnt] = '\0';
	return (ptr);
}
