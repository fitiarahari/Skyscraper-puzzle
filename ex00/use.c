/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:12:41 by fidrandr          #+#    #+#             */
/*   Updated: 2024/01/21 18:12:44 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	error(void)
{
	write(1, "Error\n", 6);
}

int	*index_init(int *tab, int nb, int to_initiate)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		tab[i] = to_initiate;
		i++;
	}
	return (tab);
}

void	init_array(int **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			arr[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
