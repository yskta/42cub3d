/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_other_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:25:14 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/20 12:30:25 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_other_data(t_data *data)
{
	init_mlx(data);
	init_texture(data);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		put_error_and_exit("MLX ERROR", data);
	data->mlx_win = mlx_new_window(data->mlx, data->map.width * IMG_WIDTH, \
			data->map.height * IMG_HEIGHT, "cub3d");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		put_error_and_exit("MLX_WIN ERROR", data);
	}
}

t_texture xpm_file_to_texture(void *mlx, char *path, t_data *data)
{
	t_texture	texture;

	texture.texture_ptr = mlx_xpm_file_to_image(mlx, path, &texture.x, &texture.y);
	if (texture.texture_ptr == NULL)
		put_error_and_exit("XPM_TO_IMAGE ERROR", data);
	return (texture);
}

void	init_texture(t_data *data)
{
	data->north = xpm_file_to_texture(data->mlx, data->north.path, data);
	data->south = xpm_file_to_texture(data->mlx, data->south.path, data);
	data->west = xpm_file_to_texture(data->mlx, data->west.path, data);
	data->east = xpm_file_to_texture(data->mlx, data->east.path, data);
}