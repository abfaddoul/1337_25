/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:07:32 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/07/16 21:54:31 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	array_creation(int *comb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
	}
}

void	printarr(int *comb, int n, char c, int i)
{
	while (i < n)
	{
		c = comb[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	c;
	int		comb[10];

	c = '0';
	array_creation(comb, n);
	while (1)
	{
		i = 0;
		printarr(comb, n, c, i);
		if (comb[0] == 10 - n)
			break ;
		write (1, ", ", 2);
		i = n - 1;
		while (i >= 0 && comb[i] == 10 - (n - i))
			i--;
		if (i < 0)
			break ;
		comb[i]++;
		while (++i < n)
			comb[i] = comb[i - 1] + 1;
	}
}
