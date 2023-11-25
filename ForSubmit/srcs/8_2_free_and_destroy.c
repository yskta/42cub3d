/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_2_free_and_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:49:56 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/25 16:50:17 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_and_destroy_all(t_data *data)
{
	destroy_textures(data);
	free_map_data_and_path(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free_texture(data);
	free(data->mlx);
	free_pos_dir_plane(data);
	free(data);
}
