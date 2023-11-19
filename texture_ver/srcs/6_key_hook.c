/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_key_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:42:40 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/19 03:41:57 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	key_draw_clear(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < SCREEN_W)
	{
		col = 0;
		while (col < SCREEN_H)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, row, col, BLACK);
			++col;
		}
		++row;
	}
}

static void	key_w_s(t_data *data, int keycode)
{
	double	sign;
	double	move;

	sign = 1;
	move = 1;
	if (keycode == KEY_S)
		sign = -1;
	if (data->map_data.map[(int)(data->cur_pos->pos_x + sign * data->dir->dir_x * move)][(int)data->cur_pos->pos_y] == '0')
		data->cur_pos->pos_x += sign * data->dir->dir_x * move;
	if (data->map_data.map[(int)data->cur_pos->pos_x][(int)(data->cur_pos->pos_y + sign * data->dir->dir_y * move)] == '0')
		data->cur_pos->pos_y += sign * data->dir->dir_y * move;
}

static void	key_a_d(t_data *data, int keycode)
{
	double	sign;
	double	move;
	double	angle_x;
	double	angle_y;
	double	old_dir_x;

	sign = 1;
	move = 1;
	angle_x = 1;
	angle_y = 1;
	old_dir_x = data->dir->dir_x;
	angle_x = data->dir->dir_x * cos(M_PI / 2) - data->dir->dir_y * sin(M_PI / 2);
	angle_y = old_dir_x * sin(M_PI / 2) + data->dir->dir_y * cos(M_PI / 2);
	if (keycode == KEY_D)
		sign = -1;
	if (data->map_data.map[(int)(data->cur_pos->pos_x + angle_x * sign * move)][(int)data->cur_pos->pos_y] == '0')
		data->cur_pos->pos_x += angle_x * sign * move;
	if (data->map_data.map[(int)data->cur_pos->pos_x][(int)(data->cur_pos->pos_y + angle_y * sign * move)] == '0')
		data->cur_pos->pos_y += angle_y * sign * move;
}

static void	key_l_r(t_data *data, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	old_dir_x = data->dir->dir_x;
	old_plane_x = data->plane->plane_x;
	rot = M_PI / ANGLE;
	if (keycode == KEY_RIGHT)
		rot *= -1;
	data->dir->dir_x = data->dir->dir_x * cos(rot) - data->dir->dir_y * sin(rot);
	data->dir->dir_y = old_dir_x * sin(rot) + data->dir->dir_y * cos(rot);
	data->plane->plane_x = data->plane->plane_x * cos(rot) - data->plane->plane_y * sin(rot);
	data->plane->plane_y = old_plane_x * sin(rot) + data->plane->plane_y * cos(rot);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_S)
		key_w_s(data, keycode);
	else if (keycode == KEY_A || keycode == KEY_D)
		key_a_d(data, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key_l_r(data, keycode);
	else
		return (0);
	key_draw_clear(data);
	//key_draw(data);
	return (0);
}
