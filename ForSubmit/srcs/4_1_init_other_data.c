/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_1_init_other_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:25:14 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/27 00:26:17 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	init_other_data(t_data *data)
{
	if (init_mlx(data) == false)
	{
		free_map_data_and_path(data);
		return (false);
	}
	if (init_texture(data) == false || init_pos_dir_plane(data) == false)
	{
		destroy_textures(data);
		free_map_data_and_path(data);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free_texture(data);
		free(data->mlx);
		if (init_pos_dir_plane(data) == false)
			free_pos_dir_plane(data);
		return (false);
	}
	return (true);
}

bool	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (false);
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		return (false);
	}
	return (true);
}

bool	init_texture(t_data *data)
{
	data->tex = (t_tex *)malloc(sizeof(t_tex));
	data->tex->tex_dir = (t_tex_dir *)malloc(sizeof(t_tex_dir));
	if (data->tex == NULL || data->tex->tex_dir == NULL)
		return (false);
	data->tex->tex_dir->north.tex_ptr = \
		mlx_xpm_file_to_image(data->mlx, data->north_path, \
			&data->tex->tex_dir->north.x, &data->tex->tex_dir->north.y);
	data->tex->tex_dir->south.tex_ptr = \
		mlx_xpm_file_to_image(data->mlx, data->south_path, \
			&data->tex->tex_dir->south.x, &data->tex->tex_dir->south.y);
	data->tex->tex_dir->west.tex_ptr = \
		mlx_xpm_file_to_image(data->mlx, data->west_path, \
			&data->tex->tex_dir->west.x, &data->tex->tex_dir->west.y);
	data->tex->tex_dir->east.tex_ptr = \
		mlx_xpm_file_to_image(data->mlx, data->east_path, \
			&data->tex->tex_dir->east.x, &data->tex->tex_dir->east.y);
	if (data->tex->tex_dir->north.tex_ptr == NULL || \
		data->tex->tex_dir->south.tex_ptr == NULL || \
		data->tex->tex_dir->west.tex_ptr == NULL || \
		data->tex->tex_dir->east.tex_ptr == NULL)
		return (false);
	return (true);
}
