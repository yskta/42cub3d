/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_init_other_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:04:18 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/19 03:20:53 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//レイキャスティング用のデータを初期化する
bool	init_pos_dir_plane(t_data *data)
{
	size_t	i;
	size_t	j;

	data->cur_pos = (t_cur_pos *)malloc(sizeof(t_cur_pos));
	data->dir = (t_dir *)malloc(sizeof(t_dir));
	data->plane = (t_plane *)malloc(sizeof(t_plane));
	if (data->cur_pos == NULL || data->dir == NULL || data->plane == NULL)
		return (false);
	i = 0;
	while (data->map_data.map[i] != NULL)
	{
		j = 0;
		while (data->map_data.map[i][j] != '\0')
		{
			if (data->map_data.map[i][j] == 'N' || data->map_data.map[i][j] == 'S' ||
			data->map_data.map[i][j] == 'E' || data->map_data.map[i][j] == 'W')
			{
				data->cur_pos->pos_x = (double)i;
				data->cur_pos->pos_y = (double)j;
				if (data->map_data.map[i][j] == 'N')
				{
					data->dir->dir_x = -1;
					data->dir->dir_y = 0;
					data->plane->plane_x = 0;
					data->plane->plane_y = 0.66;
				}
				// else if (data->map_data.map[i][j] == 'S')
				// {
				// 	data->dir->dir_x = 1;
				// 	data->dir->dir_y = 0;
				// 	data->plane->plane_x = 0;
				// 	data->plane->plane_y = -0.66;
				// }
				// else if (data->map_data.map[i][j] == 'E')
				// {
				// 	data->dir->dir_x = 0;
				// 	data->dir->dir_y = 1;
				// 	data->plane->plane_x = 0.66;
				// 	data->plane->plane_y = 0;
				// }
				// else if (data->map_data.map[i][j] == 'W')
				// {
				// 	data->dir->dir_x = 0;
				// 	data->dir->dir_y = -1;
				// 	data->plane->plane_x = -0.66;
				// 	data->plane->plane_y = 0;
				// }
				break;
			}
			j++;
		}
		i++;
	}
	// printf("for debug in init_pos_dir_plane\n");
	// printf("data->dir->dir_x = %f\n", data->dir->dir_x);
	// printf("data->dir->dir_y = %f\n", data->dir->dir_y);
	// printf("data->plane->plane_x = %f\n", data->plane->plane_x);
	// printf("data->plane->plane_y = %f\n", data->plane->plane_y);
	//TODO：外す必要あるかも
	data->map_data.map[(int)data->cur_pos->pos_x][(int)data->cur_pos->pos_y] = '0';
	return (true);
}