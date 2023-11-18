/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:20:59 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/19 02:27:57 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char *argv[])
{
    t_data  *data;

    data = malloc(sizeof(t_data));
    if (!data)
        put_error_and_exit("malloc error in main", data);
    if (check_arg(argc, argv) == false)
        put_error_and_exit("invalid arg", data);
    if (read_map(argv[1], data) == false)
        put_error_and_exit("error in read map", data);
    if (parse_read_data(data) == false)
        put_error_and_exit("error in parse read data", data);
    if (init_other_data(data) == false)
        put_error_and_exit("error in init other data", data);
    //仮で4_2_init_other_data.cの処理をここで行う
    data->cur_pos = (t_cur_pos *)malloc(sizeof(t_cur_pos));
	data->dir = (t_dir *)malloc(sizeof(t_dir));
	data->plane = (t_plane *)malloc(sizeof(t_plane));
	if (data->cur_pos == NULL || data->dir == NULL || data->plane == NULL)
		return (false);
    data->cur_pos->pos_x = 22;
    data->cur_pos->pos_y = 12;
    data->dir->dir_x = -1;
    data->dir->dir_y = 0;
    data->plane->plane_x = 0;
    data->plane->plane_y = 0.66;
    printf("start raycasting\n");
    mlx_key_hook(data->mlx_win, key_hook, data);
    mlx_loop_hook(data->mlx, key_draw, data);
	mlx_hook(data->mlx_win, DestroyNotify, ButtonPressMask, close_program, data);
	mlx_loop(data->mlx);
    free_and_destroy_all(data);

    return (0);
}

