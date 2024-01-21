/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:24:51 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/21 12:44:40 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void printMatrix(char **map) 
{
	int	i;

	i = -1;
	while (map[++i])
	{
		printf("%s", map[i]);
	}
	printf("\n");
}

void	ft_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	isValidMove(t_data *data, char **map, int row, int col) 
{
	return (row >= 0 && row < data->height && col >= 0 && col < data->width && map[row][col] != '1' && map[row][col] != 'X');
}

Point	new_point(int i, int j)
{
	Point a;

	a.col = j;
	a.row = i;
	return (a);
}

void	browse_map(t_data *data, char **map, int i, int j, Point *stack) 
{
	Point	start;
	Point	current;
	int top;

	top = -1;
	start = new_point(i, j);
	stack[++top] = start;
	while (top >= 0) {
		current = stack[top--];
		i = current.row;
		j = current.col;
		if (!isValidMove(data, map, i, j)) 
			continue;
		map[i][j] = 'X';
		if (isValidMove(data, map, i - 1, j))
			stack[++top] = new_point(i - 1, j);
		if (isValidMove(data, map, i + 1, j))
			stack[++top] = new_point(i + 1, j);
		if (isValidMove(data, map, i, j - 1))
			stack[++top] = new_point(i, j - 1);
		if (isValidMove(data, map, i, j + 1))
			stack[++top] = new_point(i, j + 1);
	}
	free(stack);
}

void	findPaths(t_data *data, char **map) 
{
	int		i;
	int		j;
	Point	*stack;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
			if (map[i][j] == 'P')
			{
				data->player.y = i;
				data->player.x = j;
				break;
			}
	}
	stack = (Point *)malloc(sizeof(Point) * data->height * data->width);
	if (!stack)
	{
		ft_free(map);
		ft_error("Error\nMalloc fail\n", data);
	}
	browse_map(data, map, data->player.y, data->player.x, stack);
}

int	map_valid(char **map)
{
	int	y;
	int	x;
	int	c;

	y = -1;
	c = 1;
	while (map[++y] && c)
	{
		x = 0;
		while (map[y][++x] && map[y][x] != '\n' && c)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				c = 0;
		}
	}
	ft_free(map);
	return (c);
}

void	check_solution(t_data *data)
{
	char	**map;
	int		y;

	map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!map)
		ft_error("Error\nMalloc fail\n", data);
	y = -1;
	while (++y < data->height)
		map[y] = ft_strdup(data->map[y]);
	map[y] = 0;
	findPaths(data, map);
	data->player.y = 0;
	if (!map_valid(map))
		ft_error("Error\nMap error\n", data);
}
	
