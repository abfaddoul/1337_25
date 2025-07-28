/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:12:34 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/07/27 12:22:36 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	j;

	i = 0;
	j = nb - 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (i < j)
	{
		nb = nb * j;
		j--;
	}
	return (nb);
}
