/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:21:55 by rtomiki           #+#    #+#             */
/*   Updated: 2021/04/13 13:16:04 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	dstsize;

	if (!s1 || !s2)
		return (NULL);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(sizeof(char) * dstsize);
	if (!(ptr))
		return (NULL);
	ptr[0] = '\0';
	ft_strlcat(ptr, s1, dstsize);
	ft_strlcat(ptr, s2, dstsize);
	return (ptr);
}
