/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:03:05 by yousenna          #+#    #+#             */
/*   Updated: 2025/07/20 09:09:47 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_rec(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (x != 1 && y != 1 && i == y - 1 && j == x -1))
		ft_putchar('/');
	else if ((x != 1 && y != 1 && i == 0 && j == x - 1)
		|| (x != 1 && y != 1 && i == y - 1 && j == 0)
		|| (y == 1 && x != 1 && i == 0 && j == x - 1)
		|| (x == 1 && y != 1 && i == y - 1 && j == 0))
		ft_putchar('\\');
	else if (((i >= 1 && i <= y - 1) && (j == 0 || j == x - 1))
		|| ((j >= 1 && j <= x - 1) && (i == 0 || i == y - 1)))
		ft_putchar('*');
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
		ft_putchar('/');
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
