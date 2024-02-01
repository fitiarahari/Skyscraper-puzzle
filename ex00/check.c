/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:11:26 by fidrandr          #+#    #+#             */
/*   Updated: 2024/01/21 18:14:25 by fidrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	left_to_right_verify(int **array, int **solve_array, int pos[3])
{
	int	i;
	int	high;
	int	count;
	int	full;

	i = 0;
	high = 0;
	count = 0;
	full = 0;
	while (i < 4)
	{
		if (solve_array[pos[0]][i] == pos[2] && i != pos[1])
			return (1);
		if (solve_array[pos[0]][i] > high)
		{
			high = solve_array[pos[0]][i];
			count ++;
		}
		if (solve_array[pos[0]][i] == 0)
			full = 1;
		i++;
	}
	if (count != array[2][pos[0]] && full == 0)
		return (1);
	return (0);
}

int	up_to_down_verify(int **array, int **solve_array, int pos[3])
{
	int	i;
	int	high;
	int	count;
	int	full;

	i = 0;
	high = 0;
	count = 0;
	full = 0;
	while (i < 4)
	{
		if (solve_array[i][pos[1]] == pos[2] && i != pos[0])
			return (1);
		if (solve_array[i][pos[1]] > high)
		{
			high = solve_array[i][pos[1]];
			count++;
		}
		if (solve_array[i][pos[1]] == 0)
			full = 1;
		i++;
	}
	if (count != array[0][pos[1]] && full == 0)
		return (1);
	return (0);
}

int	right_to_left_verify(int **array, int **solve_array, int pos[3])
{
	int	i;
	int	high;
	int	count;
	int	full;

	i = 3;
	high = 0;
	count = 0;
	full = 0;
	while (i > -1)
	{
		if (solve_array[pos[0]][i] > high)
		{
			high = solve_array[pos[0]][i];
			count++;
		}
		if (solve_array[pos[0]][i] == 0)
			full = 1;
		i--;
	}
	if (count != array[3][pos[0]] && full == 0)
		return (1);
	return (0);
}

int	down_to_up_verify(int **array, int **solve_array, int pos[3])
{
	int	i;
	int	high;
	int	count;
	int	full;

	i = 3;
	high = 0;
	count = 0;
	full = 0;
	while (i > -1)
	{
		if (solve_array[i][pos[1]] > high)
		{
			high = solve_array[i][pos[1]];
			count++;
		}
		if (solve_array[i][pos[1]] == 0)
			full = 1;
		i--;
	}
	if (count != array[1][pos[1]] && full == 0)
		return (1);
	return (0);
}

int	pos_valide(int **array, int **solve_array, int pos[3])
{
	int	y;
	int	x;

	y = pos[0];
	x = pos[1];
	solve_array[y][x] = pos[2];
	if (left_to_right_verify(array, solve_array, pos) == 1)
		return (1);
	if (up_to_down_verify(array, solve_array, pos) == 1)
		return (1);
	if (right_to_left_verify(array, solve_array, pos) == 1)
		return (1);
	if (down_to_up_verify(array, solve_array, pos) == 1)
		return (1);
	return (0);
}
