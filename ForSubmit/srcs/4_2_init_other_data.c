/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_init_other_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:04:18 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/24 19:37:04 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
				data->cur_pos->x = (double)i;
				data->cur_pos->y = (double)j;
				if (data->map_data.map[i][j] == 'N')
				{
					data->dir->x = -1;
					data->dir->y = 0;
					data->plane->x = 0;
					data->plane->y = 0.66;
				}
				// else if (data->map_data.map[i][j] == 'S')
				// {
				// 	data->dir->x = 1;
				// 	data->dir->y = 0;
				// 	data->plane->x = 0;
				// 	data->plane->y = -0.66;
				// }
				// else if (data->map_data.map[i][j] == 'E')
				// {
				// 	data->dir->x = 0;
				// 	data->dir->y = 1;
				// 	data->plane->x = 0.66;
				// 	data->plane->y = 0;
				// }
				// else if (data->map_data.map[i][j] == 'W')
				// {
				// 	data->dir->x = 0;
				// 	data->dir->y = -1;
				// 	data->plane->x = -0.66;
				// 	data->plane->y = 0;
				// }
				break;
			}
			j++;
		}
		i++;
	}
	data->map_data.map[(int)data->cur_pos->x][(int)data->cur_pos->y] = '0';
	return (true);
}