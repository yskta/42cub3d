/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_free_and_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:43:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/25 12:41:17 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_two_dimensional_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map_data_and_texture(t_data *data)
{
	if (data->map_data.read_data != NULL)
		free_two_dimensional_array(data->map_data.read_data);
	if (data->map_data.map != NULL)
		free_two_dimensional_array(data->map_data.map);
	if (data->north_path != NULL)
		free(data->north_path);
	if (data->south_path != NULL)
		free(data->south_path);
	if (data->west_path != NULL)
		free(data->west_path);
	if (data->east_path != NULL)
		free(data->east_path);
	if (data->tex->tex_dir != NULL)
		free(data->tex->tex_dir);
	if (data->tex != NULL)
		free(data->tex);
}

void	destroy_textures(t_data *data)
{
	if (data->tex->tex_dir != NULL)
	{
		if (data->tex->tex_dir->north.tex_ptr != NULL)
			mlx_destroy_image(data->mlx, \
				data->tex->tex_dir->north.tex_ptr);
		if (data->tex->tex_dir->south.tex_ptr != NULL)
			mlx_destroy_image(data->mlx, \
				data->tex->tex_dir->south.tex_ptr);
		if (data->tex->tex_dir->west.tex_ptr != NULL)
			mlx_destroy_image(data->mlx, \
				data->tex->tex_dir->west.tex_ptr);
		if (data->tex->tex_dir->east.tex_ptr != NULL)
			mlx_destroy_image(data->mlx, \
				data->tex->tex_dir->east.tex_ptr);
	}
}

void	free_pos_dir_plane(t_data *data)
{
	if (data->cur_pos != NULL)
		free(data->cur_pos);
	if (data->dir != NULL)
		free(data->dir);
	if (data->plane != NULL)
		free(data->plane);
}

void	free_and_destroy_all(t_data *data)
{
	destroy_textures(data);
	free_map_data_and_texture(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_pos_dir_plane(data);
	free(data);
}
