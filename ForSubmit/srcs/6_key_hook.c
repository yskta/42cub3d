/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_key_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:42:40 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/26 13:55:28 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	key_w_s(t_data *data, int keycode)
{
	double	sign;
	double	move;

	sign = 1.0;
	move = 1.0;
	if (keycode == KEY_S)
		sign = -1.0;
	if (data->map_data.map[(int)(data->cur_pos->x + sign * \
		data->dir->x * move)][(int)data->cur_pos->y] == '0')
		data->cur_pos->x += sign * data->dir->x * move;
	if (data->map_data.map[(int)data->cur_pos->x] \
		[(int)(data->cur_pos->y + sign * data->dir->y * move)] == '0')
		data->cur_pos->y += sign * data->dir->y * move;
}

static void	key_a_d(t_data *data, int keycode)
{
	double	sign;
	double	move;
	double	angle_x;
	double	angle_y;
	double	old_dir_x;

	sign = 1.0;
	move = 1.0;
	angle_x = 1.0;
	angle_y = 1.0;
	old_dir_x = data->dir->x;
	angle_x = data->dir->x * cos(M_PI / 2.0) - data->dir->y * sin(M_PI / 2.0);
	angle_y = old_dir_x * sin(M_PI / 2.0) + data->dir->y * cos(M_PI / 2.0);
	if (keycode == KEY_D)
		sign = -1.0;
	if (data->map_data.map[(int)(data->cur_pos->x + angle_x * sign * move)] \
		[(int)data->cur_pos->y] == '0')
		data->cur_pos->x += angle_x * sign * move;
	if (data->map_data.map[(int)data->cur_pos->x] \
		[(int)(data->cur_pos->y + angle_y * sign * move)] == '0')
		data->cur_pos->y += angle_y * sign * move;
}

static void	key_l_r(t_data *data, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	old_dir_x = data->dir->x;
	old_plane_x = data->plane->x;
	rot = M_PI / 16.0;
	if (keycode == KEY_RIGHT)
		rot *= -1.0;
	data->dir->x = data->dir->x * cos(rot) - data->dir->y * sin(rot);
	data->dir->y = old_dir_x * sin(rot) + data->dir->y * cos(rot);
	data->plane->x = data->plane->x * cos(rot) - data->plane->y * sin(rot);
	data->plane->y = old_plane_x * sin(rot) + data->plane->y * cos(rot);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_S)
		key_w_s(data, keycode);
	else if (keycode == KEY_A || keycode == KEY_D)
		key_a_d(data, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key_l_r(data, keycode);
	else if (keycode == KEY_ESC)
		close_program(data);
	return (0);
}
