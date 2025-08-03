/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:54:20 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/08/02 16:12:16 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	string_join(char *str, char *sep, int size, char **strs)
{
	int	i;
	int	k;
	int	s;
	int	j;

	k = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		s = 0;
		while (strs[j][i])
		{
			str[k] = strs[j][i];
			i++;
			k++;
		}
		while (sep[s] && j < size - 1)
		{
			str[k] = sep[s];
			k++;
			s++;
		}
		j++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		j;
	int		len;
	char	*str;

	j = 0;
	len = 0;
	if (size == 0)
	{
		str = malloc(1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	while (j < size)
	{
		len += ft_strlen(strs[j]);
		j++;
	}
	len += ft_strlen(sep) * (size - 1);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	string_join(str, sep, size, strs);
	str[len] = '\0';
	return (str);
}
