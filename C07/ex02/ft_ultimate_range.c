/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:35:06 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/07/30 16:52:28 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	diff;

	diff = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * diff);
	if (!(*range))
		return (-1);
	while (i < diff)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (diff);
}
