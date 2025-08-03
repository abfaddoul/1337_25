/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:07:42 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/08/02 18:24:46 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_invalid(char *base)
{
	int i, (j);
	i = 0;
	j = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32)
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	nbr_len(int nbr, int base_len)
{
	int		len;
	long	nb;

	len = 0;
	nb = nbr;
	if (nb < 0)
		len++;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int nbr, char *base)
{
	long	nb;
	char	*res;

	int base_len, (len), (neg);
	base_len = ft_strlen(base);
	len = nbr_len(nbr, base_len);
	nb = nbr;
	res = malloc((len + 1) * sizeof(char));
	neg = 0;
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	res[len] = '\0';
	while (len > neg)
	{
		res[--len] = base[nb % base_len];
		nb /= base_len;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
