/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:26:47 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/27 00:35:39 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	juduge_identifer(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		return (2);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		return (3);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		return (4);
	else if (ft_strncmp(str, "F ", 2) == 0)
		return (5);
	else if (ft_strncmp(str, "C ", 2) == 0)
		return (6);
	else
		return (0);
}

bool	parse_path(t_data *data, size_t i, size_t j, int id_num)
{
	while (data->map_data.read_data[i][j] != '.')
		j++;
	if (id_num == 1)
	{
		data->north_path = ft_strdup(&data->map_data.read_data[i][j]);
		printf("north_path = %s\n", data->north_path);
	}
	else if (id_num == 2)
	{
		data->south_path = ft_strdup(&data->map_data.read_data[i][j]);
		printf("south_path = %s\n", data->south_path);
	}
	else if (id_num == 3)
	{
		data->west_path = ft_strdup(&data->map_data.read_data[i][j]);
		printf("west_path = %s\n", data->west_path);
	}
	else if (id_num == 4 && data->east_path == NULL)
	{
		data->east_path = ft_strdup(&data->map_data.read_data[i][j]);
		printf("east_path = %s\n", data->east_path);
	}
	return (true);
}

bool	parse_floor(t_data *data, size_t i, size_t j)
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
	if (data->floor.r < 0 || data->floor.r > 255 || data->floor.g < 0 || \
		data->floor.g > 255 || data->floor.b < 0 || data->floor.b > 255)
		return (false);
	data->floor.color = data->floor.r << 16 | data->floor.g << 8 | \
						data->floor.b;
	return (true);
}

bool	parse_ceiling(t_data *data, size_t i, size_t j)
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
	if (data->ceiling.r < 0 || data->ceiling.r > 255 || \
		data->ceiling.g < 0 || data->ceiling.g > 255 || \
		data->ceiling.b < 0 || data->ceiling.b > 255)
		return (false);
	data->ceiling.color = data->ceiling.r << 16 | data->ceiling.g << 8 | \
						data->ceiling.b;
	return (true);
}

bool	parse_each_identifier(t_data *data, size_t i, size_t j)
{
	int		id_num;
	bool	valid_flag;

	id_num = juduge_identifer(&data->map_data.read_data[i][j]);
	printf("id_num = %d\n", id_num);
	valid_flag = true;
	if (1 <= id_num && id_num <= 4)
		valid_flag = parse_path(data, i, j, id_num);
	else if (id_num == 5)
		valid_flag = parse_floor(data, i, j);
	else if (id_num == 6)
		valid_flag = parse_ceiling(data, i, j);
	return (valid_flag);
}
