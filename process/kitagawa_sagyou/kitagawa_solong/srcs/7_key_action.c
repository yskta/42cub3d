/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_key_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:34 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/18 15:45:07 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_action(int key, t_data *data)
{
	if (key == KEY_UP || key == KEY_W)
		updata_and_render_map(data, data->map.player.x, data->map.player.y - 1);
	else if (key == KEY_DOWN || key == KEY_S)
		updata_and_render_map(data, data->map.player.x, data->map.player.y + 1);
	else if (key == KEY_RIGHT || key == KEY_D)
		updata_and_render_map(data, data->map.player.x + 1, data->map.player.y);
	else if (key == KEY_LEFT || key == KEY_A)
		updata_and_render_map(data, data->map.player.x - 1, data->map.player.y);
	else if (key == KEY_ESC)
		close_game(data);
	return (0);
}

void	process_1(t_data *data)
{
	data->map.steps++;
	ft_printf("%d\n", data->map.steps);
	win_game(data);
}

void	process_2(t_data *data, size_t update_x, size_t update_y)
{
	data->map.steps++;
	ft_printf("%d\n", data->map.steps);
	data->map.player.x = update_x;
	data->map.player.y = update_y;
	data->map.map[update_y][update_x] = PLAYER;
	render_map(data);
}

void	process_3(t_data *data, size_t update_x, size_t update_y)
{
	if (data->map.map[update_y][update_x] == COLLECTIBLE)
			data->map.n_collectibel -= 1;
	data->map.steps++;
	ft_printf("%d\n", data->map.steps);
	data->map.player.x = update_x;
	data->map.player.y = update_y;
	data->map.map[update_y][update_x] = PLAYER;
	render_map(data);
}

void	updata_and_render_map(t_data *data, size_t update_x, size_t update_y)
{
	size_t	current_x;
	size_t	current_y;

	current_x = data->map.player.x;
	current_y = data->map.player.y;
	if (data->map.map[update_y][update_x] == EXIT && \
			data->map.n_collectibel == 0)
		process_1(data);
	else if (data->map.map[update_y][update_x] == EXIT && \
			data->map.n_collectibel != 0)
	{
		data->map.map[current_y][current_x] = SPACE;
		process_2(data, update_x, update_y);
	}
	else if (data->map.map[update_y][update_x] == SPACE || \
			data->map.map[update_y][update_x] == COLLECTIBLE)
	{
		if (current_y == data->map.exit.y && current_x == data->map.exit.x)
			data->map.map[current_y][current_x] = EXIT;
		else
			data->map.map[current_y][current_x] = SPACE;
		process_3(data, update_x, update_y);
	}
}
