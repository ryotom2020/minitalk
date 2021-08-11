/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:22:11 by rtomiki           #+#    #+#             */
/*   Updated: 2021/04/17 16:08:25 by rtomiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	judge(char str, char c)
{
	if (str == c)
		return (1);
	if (str == '\0')
		return (1);
	return (0);
}

static int	count_word(char *str, char c)
{
	int	cnt;
	int	words;

	cnt = 0;
	words = 0;
	while (str[cnt])
	{
		if (judge(str[cnt + 1], c) && !judge(str[cnt], c))
			words++;
		cnt++;
	}
	return (words);
}

static void	copy_word(char *dest, char *from, char c)
{
	int	i;

	i = 0;
	while (judge(from[i], c) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	write_word(char **ft_split, char *str, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (judge(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (judge(str[i + j], c) == 0)
				j++;
			ft_split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(ft_split[word]))
				return (word + 1);
			copy_word(ft_split[word], str + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char *str, char c)
{
	int		num_word;
	char	**ft_split;
	int		flag;

	if (!str)
		return (NULL);
	num_word = count_word(str, c);
	ft_split = (char **)malloc(sizeof(char *) * (num_word + 1));
	if (!(ft_split))
		return (NULL);
	flag = write_word(ft_split, str, c);
	if (flag)
	{
		flag -= 1;
		while (--flag >= 0)
			free(ft_split[flag]);
		free(ft_split);
		return (NULL);
	}
	ft_split[num_word] = 0;
	return (ft_split);
}
