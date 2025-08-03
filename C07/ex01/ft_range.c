/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdfaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:28:40 by abdfaddo          #+#    #+#             */
/*   Updated: 2025/07/30 16:34:22 by abdfaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;
	int	diff;

	if (min >= max)
		return (0);
	i = 0;
	diff = max - min;
	range = malloc(sizeof(int) * diff);
	if (!range)
		return (0);
	while (i < diff)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
