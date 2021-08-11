/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:01:06 by rtomiki           #+#    #+#             */
/*   Updated: 2021/04/13 13:27:50 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	cnt_src;

	cnt = 0;
	cnt_src = 0;
	while (dst[cnt])
		cnt++;
	if (dstsize < cnt)
	{
		while (src[cnt_src])
			cnt_src++;
		return (dstsize + cnt_src);
	}
	while (cnt < dstsize - 1 && src[cnt_src] != '\0' && dstsize > 0)
	{
		dst[cnt++] = src[cnt_src++];
	}
	dst[cnt] = '\0';
	while (src[cnt_src++] != '\0')
	{
		cnt++;
	}
	return (cnt);
}
