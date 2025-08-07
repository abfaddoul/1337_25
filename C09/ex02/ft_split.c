/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:22:14 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/08/04 16:22:21 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int i, (in), (count);
	i = 0;
	in = 0;
	count = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
		{
			if (in == 0)
			{
				in = 1;
				count++;
			}
		}
		else
			in = 0;
		i++;
	}
	return (count);
}

char	*word_up(char *str, int start, int end)
{
	int		i;
	int		len;
	char	*res;

	len = end - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (start < end)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;

	int i, (j), (start), (count);
	i = 0;
	j = 0;
	count = count_words(str, charset);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (0);
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_sep(str[i], charset))
			i++;
		if (i > start)
		{
			strs[j] = word_up(str, start, i);
			j++;
		}
	}
	strs[j] = NULL;
	return (strs);
}
