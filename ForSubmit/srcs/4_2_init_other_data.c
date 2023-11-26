/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_init_other_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:04:18 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/26 13:01:46 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_data_pos_dir_plane_north_or_south(t_data *data, int i, int j)
{
	data->cur_pos->x = i;
	data->cur_pos->y = j;
	if (data->map_data.map[(int)data->cur_pos->x][(int)data->cur_pos->y] \
		== 'N')
	{
		data->dir->x = -1.0;
		data->dir->y = 0.0;
		data->plane->x = 0.0;
		data->plane->y = 0.66;
	}
	else if (data->map_data.map[(int)data->cur_pos->x][(int)data->cur_pos->y] \
		== 'S')
	{
		data->dir->x = 1.0;
		data->dir->y = 0.0;
		data->plane->x = 0.0;
		data->plane->y = -0.66;
	}
}

void	init_data_pos_dir_plane_east_or_west(t_data *data, int i, int j)
{
	data->cur_pos->x = i;
	data->cur_pos->y = j;
	if (data->map_data.map[(int)data->cur_pos->x][(int)data->cur_pos->y] \
		== 'E')
	{
		data->dir->x = 0.0;
		data->dir->y = 1.0;
		data->plane->x = 0.66;
		data->plane->y = 0.0;
	}
	else if (data->map_data.map[(int)data->cur_pos->x][(int)data->cur_pos->y] \
		== 'W')
	{
		data->dir->x = 0.0;
		data->dir->y = -1.0;
		data->plane->x = -0.66;
		data->plane->y = 0.0;
	}
}

void	init_data_pos_dir_plane(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map_data.map[i] != NULL)
	{
		j = 0;
		while (data->map_data.map[i][j] != '\0')
		{
			if (data->map_data.map[i][j] == 'N' || \
				data->map_data.map[i][j] == 'S')
			{
				init_data_pos_dir_plane_north_or_south(data, (int)i, (int)j);
				break ;
			}
			else if (data->map_data.map[i][j] == 'E' || \
				data->map_data.map[i][j] == 'W')
			{
				init_data_pos_dir_plane_east_or_west(data, (int)i, (int)j);
				break ;
			}
			j++;
		}
		i++;
	}
}

bool	init_pos_dir_plane(t_data *data)
{
	data->cur_pos = (t_cur_pos *)malloc(sizeof(t_cur_pos));
	data->dir = (t_dir *)malloc(sizeof(t_dir));
	data->plane = (t_plane *)malloc(sizeof(t_plane));
	if (data->cur_pos == NULL || data->dir == NULL || data->plane == NULL)
		return (false);
	init_data_pos_dir_plane(data);
	data->map_data.map[(int)data->cur_pos->x][(int)data->cur_pos->y] \
		= '0';
	return (true);
}
