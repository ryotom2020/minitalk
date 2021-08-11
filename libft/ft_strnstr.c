/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:35:47 by rtomiki           #+#    #+#             */
/*   Updated: 2021/04/13 13:08:31 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cnt;
	size_t	cnt_tmp;

	cnt = 0;
	if (little[cnt] == '\0')
		return ((char *)big + cnt);
	while (big[cnt] != '\0' && cnt < len)
	{
		cnt_tmp = 0;
		if (big[cnt] == little[cnt_tmp])
		{
			while (big[cnt + cnt_tmp] == little[cnt_tmp]
				&& (big[cnt + cnt_tmp] != '\0' && little[cnt_tmp] != '\0')
				&& cnt + cnt_tmp < len)
			{
				cnt_tmp++;
			}
			if (little[cnt_tmp] == '\0')
				return ((char *)big + cnt);
		}
		cnt++;
	}
	return (NULL);
}
