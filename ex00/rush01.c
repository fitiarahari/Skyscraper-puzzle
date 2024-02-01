/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fidrandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:12:23 by fidrandr          #+#    #+#             */
/*   Updated: 2024/01/23 09:27:35 by anrahari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		*index_init(int *tab, int nb, int to_initiate);
void	error(void);
void	ft_putchar(char c);
void	solve(int **input_array);

int	space(char *str, int *i)
{
	while (str[*i] != '\0' && str[*i] == ' ')
	{
		++*i;
	}
	return (*i);
}

int	count_input(char *str)
{
	int	i;
	int	count;

	i = 0;
	i = space(str, &i);
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9'
			&& (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			count++;
			i++;
			i = space(str, &i);
		}
		else
			return (1);
	}
	return (count);
}

int	input_to_array(char *str, int *incr, int **arr, int count)
{
	count = count_input(str);
	if (count != 1 && count == (4 * 4))
	{
		while (str[incr[0]] != '\0')
		{
			if (str[incr[0]] >= '1' && str[incr[0]] <= '9')
			{
				if (incr[1] == 4)
				{
					incr[1] = 0;
					incr[2] += 1;
				}
				arr[incr[2]][incr[1]] = str[incr[0]] - 48;
				incr[0]++;
				incr[1]++;
			}
			else if (str[incr[0]] == ' ')
				incr[0]++;
			else
				return (1);
		}
	}
	else
		return (1);
	return (0);
}

void	print_rep(int **arr)
{

	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(arr[i][j] + 48);
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	**input_array;
	int	incr[3];

	i = -1;
	input_array = malloc (4 * sizeof(int *));
	while (i++ < 4)
		input_array[i] = malloc (4 * sizeof(int *));
	if (argc == 2)
	{
		index_init(incr, 3, 0);
		if (input_to_array(argv[1], incr, input_array, 0) == 1)
		{
			error();
			return (0);
		}
		solve(input_array);
	}
	else
		error();
	return (0);
}
