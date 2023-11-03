/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:26:47 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/28 15:50:14 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	juduge_identifer(char *str)
{
	if (ft_strncmp(str, "NO", 2) == 0)
		return (true);
	else if (ft_strncmp(str, SO, 2) == 0)
		return (true);
	else if (ft_strncmp(str, WE, 2) == 0)
		return (true);
	else if (ft_strncmp(str, EA, 2) == 0)
		return (true);
	else if (ft_strncmp(str, F, 1) == 0)
		return (true);
	else if (ft_strncmp(str, C, 1) == 0)
		return (true);
	else
		return (false);
}

bool	parse_texture(t_data *data, size_t i, size_t j)
{
	if (data->map_data.read_data[i][j] == 'N')
	{
		while (data->map_data.read_data[i][j] != '.')
			j++;
		data->north.path = ft_strdup(&data->map_data.read_data[i][j]);
		//printf("north.path: %s\n", data->north.path);
	}
	else if (data->map_data.read_data[i][j] == 'S')
	{
		while (data->map_data.read_data[i][j] != '.')
			j++;
		data->south.path = ft_strdup(&data->map_data.read_data[i][j]);
		//printf("south.path: %s\n", data->south.path);
	}
	else if (data->map_data.read_data[i][j] == 'W')
	{
		while (data->map_data.read_data[i][j] != '.')
			j++;
		data->west.path = ft_strdup(&data->map_data.read_data[i][j]);
		//printf("west.path: %s\n", data->west.path);
	}
	else if (data->map_data.read_data[i][j] == 'E')
	{
		while (data->map_data.read_data[i][j] != '.')
			j++;
		data->east.path = ft_strdup(&data->map_data.read_data[i][j]);
		//printf("east.path: %s\n", data->east.path);
	}
	else
		return (false);
	return (true);
}

bool	parse_floor_or_ceiling(t_data *data, size_t i, size_t j)
{
	if (data->map_data.read_data[i][j] == 'F')
	{
		j++;
		while (data->map_data.read_data[i][j] == 'X')
			j++;
		data->floor.before_split = ft_strdup(&data->map_data.read_data[i][j]);
		data->floor.after_split = ft_split(data->floor.before_split, ',');
		data->floor.r = ft_atoi(data->floor.after_split[0]);
		data->floor.g = ft_atoi(data->floor.after_split[1]);
		data->floor.b = ft_atoi(data->floor.after_split[2]);
		free_two_dimensional_array(data->floor.after_split);
		free(data->floor.before_split);
		if (data->floor.r < 0 || data->floor.r > 255 || data->floor.g < 0 || data->floor.g > 255 || data->floor.b < 0 || data->floor.b > 255)
			return (false);
	}
	else if (data->map_data.read_data[i][j] == 'C')
	{
		j++;
		while (data->map_data.read_data[i][j] == 'X')
			j++;
		data->ceiling.before_split = ft_strdup(&data->map_data.read_data[i][j]);
		data->ceiling.after_split = ft_split(data->ceiling.before_split, ',');
		data->ceiling.r = ft_atoi(data->ceiling.after_split[0]);
		data->ceiling.g = ft_atoi(data->ceiling.after_split[1]);
		data->ceiling.b = ft_atoi(data->ceiling.after_split[2]);
		free_two_dimensional_array(data->ceiling.after_split);
		free(data->ceiling.before_split);
		if (data->ceiling.r < 0 || data->ceiling.r > 255 || data->ceiling.g < 0 || data->ceiling.g > 255 || data->ceiling.b < 0 || data->ceiling.b > 255)
			return (false);
	}
	return (true);
}

bool	parse_each_identifier(t_data *data, size_t i, size_t j)
{
	if (data->map_data.read_data[i][j] == 'N' || data->map_data.read_data[i][j] == 'S' || data->map_data.read_data[i][j] == 'W' || data->map_data.read_data[i][j] == 'E')
		return (parse_texture(data, i, j));
	else if (data->map_data.read_data[i][j] == 'F' || data->map_data.read_data[i][j] == 'C')
		return (parse_floor_or_ceiling(data, i, j));
	return (true);
}