/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:20:59 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/19 02:35:44 by yokitaga         ###   ########.fr       */
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
    ////
    printf ("data->cur_pos->pos_x in main= %f\n", data->cur_pos->pos_x);
	printf ("data->cur_pos->pos_y in main = %f\n", data->cur_pos->pos_y);
    int k = 0;
	while (data->map_data.map[k] != NULL)
	{
		printf("%s\n", data->map_data.map[k]);
		k++;
	}
    ////
    printf("start raycasting\n");
    mlx_key_hook(data->mlx_win, key_hook, data);
    mlx_loop_hook(data->mlx, key_draw, data);
	mlx_hook(data->mlx_win, DestroyNotify, ButtonPressMask, close_program, data);
	mlx_loop(data->mlx);
    free_and_destroy_all(data);

    return (0);
}

