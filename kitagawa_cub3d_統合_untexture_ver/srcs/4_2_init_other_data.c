/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_init_other_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:04:18 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/18 16:17:34 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//レイキャスティング用のデータを初期化する
bool	init_pos_dir_plane(t_data *data)
{
	size_t	i;
	size_t	j;

	data->first_player_pos = (t_first_player_pos *)malloc(sizeof(t_first_player_pos));
	data->dir = (t_dir *)malloc(sizeof(t_dir));
	data->plane = (t_plane *)malloc(sizeof(t_plane));
	if (data->first_player_pos == NULL || data->dir == NULL || data->plane == NULL)
		return (false);
	i = 0;
	while (data->map_data.map[i] != NULL)
	{
		j = 0;
		while (data->map_data.map[i][j] != '\0')
		{
			if (data->map_data.map[i][j] == 'N' || data->map_data.map[i][j] == 'S' || \
			data->map_data.map[i][j] == 'E' || data->map_data.map[i][j] == 'W')
			{
				data->first_player_pos->pos_x = (double)i;
				data->first_player_pos->pos_y = (double)j;
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
	data->map_data.map[i][j] == '0';
	printf("for debug in init_pos_dir_plane\n");
	printf("data->first_player_pos->pos_x = %f\n", data->first_player_pos->pos_x);
	printf("data->first_player_pos->pos_y = %f\n", data->first_player_pos->pos_y);
	int k = 0;
	while (data->map_data.map[k] != NULL)
	{
		printf("%s\n", data->map_data.map[k]);
		k++;
	}
	return (true);
}