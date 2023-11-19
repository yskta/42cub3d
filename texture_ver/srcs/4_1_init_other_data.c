/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_1_init_other_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:25:14 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/20 01:11:48 by yokitaga         ###   ########.fr       */
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
		//TODO：必要ならここにtexture関連のfreeを追加
		destroy_textures(data);
		free_map_data_and_texture(data);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (false);
	}
	if (init_pos_dir_plane(data) == false)
	{
		destroy_textures(data);
		free_map_data_and_texture(data);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_pos_dir_plane(data);
		return (false);
	}
	// printf("init_other_data success\n");
	return (true);
}

bool	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (false);
	data->mlx_win = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "cub3d");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		return (false);
	}
	return (true);
}

bool	init_texture(t_data *data)
{
	data->texture = (t_tex *)malloc(sizeof(t_tex));
	data->texture->tex_dir = (t_tex_dir *)malloc(sizeof(t_tex_dir));
	if (data->texture == NULL || data->texture->tex_dir == NULL)
		return (false);
	data->texture->tex_dir->north.texture_ptr = mlx_xpm_file_to_image(data->mlx, data->north_path, \
			&data->texture->tex_dir->north.x, &data->texture->tex_dir->north.y);
	data->texture->tex_dir->south.texture_ptr = mlx_xpm_file_to_image(data->mlx, data->south_path, \
			&data->texture->tex_dir->south.x, &data->texture->tex_dir->south.y);
	data->texture->tex_dir->west.texture_ptr = mlx_xpm_file_to_image(data->mlx, data->west_path, \
			&data->texture->tex_dir->west.x, &data->texture->tex_dir->west.y);
	data->texture->tex_dir->east.texture_ptr = mlx_xpm_file_to_image(data->mlx, data->east_path, \
			&data->texture->tex_dir->east.x, &data->texture->tex_dir->east.y);
	if (data->texture->tex_dir->north.texture_ptr == NULL || data->texture->tex_dir->south.texture_ptr == NULL || \
			data->texture->tex_dir->west.texture_ptr == NULL || data->texture->tex_dir->east.texture_ptr == NULL)
		return (false);
	return (true);
}