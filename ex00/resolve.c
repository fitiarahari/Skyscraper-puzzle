/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:12:00 by fidrandr          #+#    #+#             */
/*   Updated: 2024/01/21 18:12:11 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		rec_solve(int **array,
			int **solve_array, int y, int x);
int		rec_condition(int **array,
			int **solve_array, int pos[3], int *val);
void	ft_putchar(char c);
void	print_rep(int **arr);
int		pos_valide(int **array,
			int **solve_array, int pos[3]);
void	init_array(int **arr);
void	error(void);

int	rec_condition(int **array,
		int **solve_array, int pos[3], int *val)
{
	int	y;
	int	x;

	y = pos[0];
	x = pos[1];
	while (*val < 5)
	{
		pos[2] = *val;
		if (pos_valide(array, solve_array, pos) == 0)
		{
			if (rec_solve(array, solve_array, y, x + 1) == 0)
				return (0);
			solve_array[y][x] = 0;
		}
		solve_array[y][x] = 0;
		++*val;
	}
	return (1);
}

int	rec_solve(int **array,
		int **solve_array, int y, int x)
{
	int	val;
	int	pos[3];

	val = 1;
	pos[0] = y;
	pos[1] = x;
	if (y == 4)
		return (0);
	else if (x == 4)
		return (rec_solve(array, solve_array, y + 1, 0));
	else if (solve_array[y][x] != 0)
		return (rec_solve(array, solve_array, y, x + 1));
	else
	{
		if (rec_condition(array, solve_array, pos, &val) == 0)
			return (0);
		else
			return (1);
	}
}

void	solve(int **array)
{
	int	i;
	int	**solve_array;
	int	resp;

	i = -1;
	solve_array = malloc (4 * sizeof(int *));
	while (i++ < 4)
		solve_array[i] = malloc (4 * sizeof(int *));
	init_array(solve_array);
	resp = rec_solve(array, solve_array, 0, 0);
	if (resp == 0)
	{
		print_rep(solve_array);
		free(solve_array);
		free(array);
	}
	else
		error();
}
