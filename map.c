/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:32:03 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/21 12:50:28 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	size_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i ++;
	return (i);
}

int	nb_line(int fd, t_data *data)
{
	int		res;
	int		n;
	char	buff[1];

	buff[0] = '\0';
	n = 1;
	res = read(fd, buff, 1);
	while (res > 0) 
	{
		if (buff[0] == '\n')
			n++;
		res = read(fd, buff, 1);
	}
	if (res == -1)
		ft_error("Error\nWrong file\n", data);
	return (n);
}

void	check_min(t_data *data)
{
	int	y;
	int	x;
	int	c;
	int	p;
	int	e;

	y = -1;
	c = 0;
	p = 0;
	e = 0;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][++x] && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'C')
				c++;
			else if (data->map[y][x] == 'P')
				p++;
			else if (data->map[y][x] == 'E')
				e++;
		}
	}
	if (c == 0 || p != 1 || e != 1)
		ft_error("Error\nMap error",data);
}

void	check_walls(t_data *data)
{
	int	width;
	int	y;
	int	x;

	y = 0;
	width = size_line(data->map[0]);
	while (data->map[++y])
	{
		if (size_line(data->map[y]) != width)
			ft_error("Error\nMap error",data);
	}
	data->height = y;
	data->width = width;
	y = -1;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][x] && data->map[y][x] != '\n')
		{
			if ((y == 0 || y == data->height -1 || x == 0 || x == data->width - 1) && data->map[y][x] != '1')
				ft_error("Error\nMap error",data);
			x++;
		}
	}
	
}

void	check_map(t_data *data)
{
	check_walls(data);
	check_min(data);
	check_solution(data);
}


void	init_map(t_data *data, char **argv)
{
	int		fd;
	int		lines;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_error("Error\nOpen fail\n", data);
	lines = nb_line(fd, data);
	close(fd);
	data->map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!data->map)
		ft_error("Error\nMalloc fail\n", data);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_error("Error\nOpen fail\n", data);
	i = -1;
	while (++i < lines)
	{
		data->map[i] = get_next_line(fd, data);
		if (!data->map[i])
		{
			printf("%d\n", i);	
			ft_error("Error\nMalloc fail\n", data);
			
		}
	}
	data->map[lines] = 0;
	check_map(data);
	close(fd);
}
