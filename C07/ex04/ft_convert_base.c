/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:35:08 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/08/02 18:42:33 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_invalid(char *base);
int		ft_strlen(char *base);
int		nbr_len(int nbr, int base_len);
char	*ft_itoa_base(int nbr, char *base);

void	norm(char *base, int j, int *index, char c)
{
	while (base[j])
	{
		if (c == base[j])
		{
			*index = j;
			break ;
		}
		j++;
	}
}

int	ft_base(char *str, char *base, int sign, int i)
{
	long	result;

	int index, (j), (len);
	result = 0;
	len = 0;
	while (base[len])
		len++;
	while (str[i])
	{
		index = -1;
		j = 0;
		norm(base, j, &index, str[i]);
		if (index == -1)
			break ;
		result = result * len + index;
		i++;
	}
	return (result * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int i, (sign);
	i = 0;
	sign = 1;
	if (ft_invalid(base) == 0)
		return (0);
	while (str[i] && str[i] <= 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (ft_base(str, base, sign, i));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (!nbr || !base_from || !base_to)
		return (NULL);
	if (!ft_invalid(base_from) || !ft_invalid(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to));
}
