/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_free_and_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:43:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/19 00:03:56 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_two_dimensional_array(char **array)
{
	size_t i;

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
	if (data->north.path != NULL)
		free(data->north.path);
	if (data->south.path != NULL)
		free(data->south.path);
	if (data->west.path != NULL)
		free(data->west.path);
	if (data->east.path != NULL)
		free(data->east.path);
}

void	destroy_textures(t_data *data)
{
	if (data->north.texture_ptr != NULL)
		mlx_destroy_image(data->mlx, data->north.texture_ptr);
	if (data->south.texture_ptr != NULL)
		mlx_destroy_image(data->mlx, data->south.texture_ptr);
	if (data->west.texture_ptr != NULL)
		mlx_destroy_image(data->mlx, data->west.texture_ptr);
	if (data->east.texture_ptr != NULL)
		mlx_destroy_image(data->mlx, data->east.texture_ptr);
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