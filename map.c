/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:32:03 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/14 15:45:19 by aschmitt         ###   ########.fr       */
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

int	nb_line(int fd)
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
	return (n);
}

void	check_map(t_data *data)
{
	int	width;
	int	y;

	y = 0;
	width = size_line(data->map[0]);
	while (data->map[++y])
	{
		if (size_line(data->map[y]) != width)
			ft_error("Error\nMap error",data);
	}
	data->height = y;
	data->width = width;
}

void	init_map(t_data *data, char **argv)
{
	int		fd;
	int		lines;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_error("Error\nWrong file\n", data);
	lines = nb_line(fd);
	close(fd);
	data->map = (char **)malloc(sizeof(char *) * (lines + 1));
	fd = open(argv[1], O_RDONLY);
	i = -1;
	while (++i < lines)
	{
		data->map[i] = get_next_line(fd);
	}
	data->map[lines] = 0;
	check_map(data);
	close(fd);
}
