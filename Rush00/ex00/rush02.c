/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:16:03 by aelbadao          #+#    #+#             */
/*   Updated: 2025/07/20 17:16:32 by aelbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_rec(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (i == 0 && j == x - 1))
		ft_putchar('A');
	else if ((i == y - 1 && j == 0) || (i == y - 1 && j == x - 1))
		ft_putchar('C');
	else if (((i >= 1 && i <= y - 1) && (j == 0 || j == x - 1))
		|| ((j >= 1 && j <= x - 1) && (i == 0 || i == y - 1)))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
		return ;
	}
	if (x <= 0 || y <= 0)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			print_rec(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
