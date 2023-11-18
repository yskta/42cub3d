/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:27:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/11/19 02:48:36 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycaster.h"

static void	key_draw_clear(t_vars *var)
{
	unsigned int	row;
	unsigned int	col;

	row = 0;
	while (row < SCREEN_W)
	{
		col = 0;
		while (col < SCREEN_H)
		{
			mlx_pixel_put(var->mlx, var->win, row, col, BLACK);
			++col;
		}
		++row;
	}
}

static void	key_w_s(t_vars *var, int keycode)
{
	double	sign;
	double	move;

	sign = 1;
	move = 1;
	if (keycode == KEY_S)
		sign = -1;
	if (map[(int)(var->cur_pos->pos_x + sign * var->dir->dir_x * move)][(int)var->cur_pos->pos_y] == 0)
		var->cur_pos->pos_x += sign * var->dir->dir_x * move;
	if (map[(int)var->cur_pos->pos_x][(int)(var->cur_pos->pos_y + sign * var->dir->dir_y * move)] == 0)
		var->cur_pos->pos_y += sign * var->dir->dir_y * move;
}

static void	key_a_d(t_vars *var, int keycode)
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
	old_dir_x = var->dir->dir_x;
	angle_x = var->dir->dir_x * cos(M_PI / 2) - var->dir->dir_y * sin(M_PI / 2);
	angle_y = old_dir_x * sin(M_PI / 2) + var->dir->dir_y * cos(M_PI / 2);
	if (keycode == KEY_D)
		sign = -1;
	if (map[(int)(var->cur_pos->pos_x + angle_x * sign * move)][(int)var->cur_pos->pos_y] == 0)
		var->cur_pos->pos_x += angle_x * sign * move;
	if (map[(int)var->cur_pos->pos_x][(int)(var->cur_pos->pos_y + angle_y * sign * move)] == 0)
		var->cur_pos->pos_y += angle_y * sign * move;
}

static void	key_l_r(t_vars *var, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	old_dir_x = var->dir->dir_x;
	old_plane_x = var->plane->plane_x;
	rot = M_PI / ANGLE;
	if (keycode == KEY_RIGHT)
		rot *= -1;
	var->dir->dir_x = var->dir->dir_x * cos(rot) - var->dir->dir_y * sin(rot);
	var->dir->dir_y = old_dir_x * sin(rot) + var->dir->dir_y * cos(rot);
	var->plane->plane_x = var->plane->plane_x * cos(rot) - var->plane->plane_y * sin(rot);
	var->plane->plane_y = old_plane_x * sin(rot) + var->plane->plane_y * cos(rot);
}

int	key_hook(int keycode, t_vars *var)
{
	if (keycode == KEY_W || keycode == KEY_S)
		key_w_s(var, keycode);
	else if (keycode == KEY_A || keycode == KEY_D)
		key_a_d(var, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		key_l_r(var, keycode);
	else
		return (0);
	key_draw_clear(var);
	return (0);
}
