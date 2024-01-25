/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:55:08 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/25 10:14:46 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	set_pos(t_data *data, int x, int y)
{
	if (x >= data->width)
		x = data->width - 1;
	else if (x < 0)
		x = 0;
	if (y >= data->height)
		y = data->height - 1;
	else if (y < 0)
		y = 0;
	if (data->map[y][x] == '1')
	{
		x = data->player.x;
		y = data->player.y;
	}
	if (data->player.x != x || data->player.y != y)
	{
		data->player.x = x;
		data->player.y = y;
		if (data->n)
			printf("count: %d\n", data->n);
		if (data->map[y][x] == 'C')
			data->map[y][x] = '0';
		data->n++;
	}
}
