/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:49:02 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/26 16:50:59 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	move_valid(t_data *data, char **map, int row, int col)
{
	return (row >= 0 && row < data->height && col >= 0 && col < data->width
		&& map[row][col] != '1' && map[row][col] != 'X');
}

t_Point	new_point(int i, int j)
{
	t_Point	a;

	a.col = j;
	a.row = i;
	return (a);
}

void	*to_img(t_data *data, char *s)
{
	int	w;
	int	h;

	return (mlx_xpm_file_to_image(data->mlx_ptr, s, &w, &h));
}

void	ft_error(char *str, t_data *data)
{
	int	i;

	ft_putstr_fd(str, 1);
	i = -1;
	if (data->map)
	{
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	free_mlx(data);
	exit(1);
}

void	*n_w(t_data *d)
{
	return (mlx_new_window(d->mlx_ptr, d->width * S, d->height * S, "MARGE"));
}
