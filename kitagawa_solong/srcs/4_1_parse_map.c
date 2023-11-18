/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_1_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:18 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/15 22:59:32 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_data *data)
{
	check_line(data);
	check_column(data);
	check_inside(data);
	check_parm(data);
	check_playable(data);
}

void	check_line(t_data *data)
{
	size_t	y;
	size_t	width;

	y = 0;
	width = ft_strlen(data->map.map[0]);
	while (y < data->map.height)
	{
		if (ft_strlen(data->map.map[y]) != width)
			put_error_and_exit("INVARID MAP3", data);
		if (data->map.map[y][0] != WALL || data->map.map[y][width - 1] != WALL)
			put_error_and_exit("INVARID MAP4", data);
		y++;
	}
	data->map.width = width;
}

void	check_column(t_data *data)
{
	size_t	x;

	x = 0;
	while (x < data->map.width)
	{
		if (data->map.map[0][x] != WALL || \
				data->map.map[data->map.height - 1][x] != WALL)
			put_error_and_exit("INVARID MAP5", data);
		x++;
	}
}

void	set_player_col_exit_data(t_data *data, size_t x, size_t y)
{
	if (data->map.map[y][x] == PLAYER)
	{
		data->map.n_player++;
		data->map.player.x = x;
		data->map.player.y = y;
	}
	else if (data->map.map[y][x] == COLLECTIBLE)
		data->map.n_collectibel++;
	else if (data->map.map[y][x] == EXIT)
	{
		data->map.n_exit++;
		data->map.exit.x = x;
		data->map.exit.y = y;
	}
	else if (ft_strchr("C01PE", data->map.map[y][x]) == NULL)
		put_error_and_exit("INVALID MAP6", data);
}

void	check_inside(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			set_player_col_exit_data(data, x, y);
			x++;
		}
		y++;
	}
}
