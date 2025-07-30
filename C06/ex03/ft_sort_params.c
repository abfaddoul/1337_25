/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:51:13 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/07/28 19:41:09 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	print_av(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			write(1, &av[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	if (ac > 1)
	{
		while (j < ac - 1)
		{
			i = 1;
			while (i < ac -1)
			{
				if (ft_strcmp(av[i], av[i + 1]) > 0)
					ft_swap(&av[i], &av[i + 1]);
				i++;
			}
			j++;
		}
	}
	print_av(av, ac);
	return (0);
}
