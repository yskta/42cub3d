/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_other_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:25:14 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/20 23:57:32 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	init_other_data(t_data *data)
{
	if (init_mlx(data) == false)
	{
		free_map_data_and_texture(data);
		return (false);
	}
	if (init_texture(data) == false)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free_map_data_and_texture(data);
		return (false);
	}
	return (true);
}

bool	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (false);
	//TODO：多分これ引数修正する
	data->mlx_win = mlx_new_window(data->mlx, data->map.width * IMG_WIDTH, \
			data->map.height * IMG_HEIGHT, "cub3d");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		return (false);
	}
	return (true);
}

t_texture xpm_file_to_texture(void *mlx, char *path, t_data *data)
{
	t_texture	texture;

	texture.texture_ptr = mlx_xpm_file_to_image(mlx, path, &texture.x, &texture.y);
	return (texture);
}

bool	init_texture(t_data *data)
{
	data->north = xpm_file_to_texture(data->mlx, data->north.path, data);
	data->south = xpm_file_to_texture(data->mlx, data->south.path, data);
	data->west = xpm_file_to_texture(data->mlx, data->west.path, data);
	data->east = xpm_file_to_texture(data->mlx, data->east.path, data);
	if (data->north.texture_ptr == NULL || data->south.texture_ptr == NULL || \
			data->west.texture_ptr == NULL || data->east.texture_ptr == NULL)
	{
		destroy_textures(data);
		return (false);
	}
	return (true);
}