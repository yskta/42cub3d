/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:26:47 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/27 20:39:11 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	parse_path(t_data *data, size_t i, size_t j, int id_num)
{
	ssize_t	fd;

	while (data->map_data.read_data[i][j] != '\0' && \
		data->map_data.read_data[i][j] != '.')
		j++;
	if (data->map_data.read_data[i][j] == '\0')
		return (false);
	fd = open(&data->map_data.read_data[i][j], O_RDONLY);
	if (fd == -1)
		return (false);
	if (id_num == 1 && data->north_path == NULL)
		data->north_path = ft_strdup(&data->map_data.read_data[i][j]);
	else if (id_num == 2 && data->south_path == NULL)
		data->south_path = ft_strdup(&data->map_data.read_data[i][j]);
	else if (id_num == 3 && data->west_path == NULL)
		data->west_path = ft_strdup(&data->map_data.read_data[i][j]);
	else if (id_num == 4 && data->east_path == NULL)
		data->east_path = ft_strdup(&data->map_data.read_data[i][j]);
	else
		return (false);
	close(fd);
	return (true);
}

bool	set_and_check_color(t_floor_or_ceiling *floor_or_ceiling)
{
	int		size_of_after_split;

	size_of_after_split = 0;
	while (floor_or_ceiling->after_split[size_of_after_split] != NULL)
		size_of_after_split++;
	if (size_of_after_split != 3)
		return (false);
	floor_or_ceiling->r = ft_atoi(floor_or_ceiling->after_split[0]);
	floor_or_ceiling->g = ft_atoi(floor_or_ceiling->after_split[1]);
	floor_or_ceiling->b = ft_atoi(floor_or_ceiling->after_split[2]);
	if (floor_or_ceiling->r < 0 || floor_or_ceiling->r > 255 || \
		floor_or_ceiling->g < 0 || floor_or_ceiling->g > 255 || \
		floor_or_ceiling->b < 0 || floor_or_ceiling->b > 255)
		return (false);
	else
		floor_or_ceiling->color = floor_or_ceiling->r << 16 | \
									floor_or_ceiling->g << 8 | \
									floor_or_ceiling->b;
	return (true);
}

bool	parse_floor(t_data *data, size_t i, size_t j)
{
	bool	valid_flag;

	valid_flag = true;
	j++;
	while (data->map_data.read_data[i][j] == ' ')
		j++;
	if (data->map_data.read_data[i][j] == '\0')
		return (false);
	data->floor.before_split = ft_strdup(&data->map_data.read_data[i][j]);
	data->floor.after_split = ft_split(data->floor.before_split, ',');
	if (set_and_check_color(&data->floor) == false)
		valid_flag = false;
	free_two_dimensional_array(data->floor.after_split);
	free(data->floor.before_split);
	return (valid_flag);
}

bool	parse_ceiling(t_data *data, size_t i, size_t j)
{
	bool	valid_flag;

	valid_flag = true;
	j++;
	while (data->map_data.read_data[i][j] == ' ')
		j++;
	if (data->map_data.read_data[i][j] == '\0')
		return (false);
	data->ceiling.before_split = ft_strdup(&data->map_data.read_data[i][j]);
	data->ceiling.after_split = ft_split(data->ceiling.before_split, ',');
	if (set_and_check_color(&data->ceiling) == false)
		valid_flag = false;
	free_two_dimensional_array(data->ceiling.after_split);
	free(data->ceiling.before_split);
	return (valid_flag);
}

bool	parse_each_identifier(t_data *data, size_t i, size_t j)
{
	int		id_num;
	bool	valid_flag;

	data->num_of_id++;
	id_num = juduge_identifer(&data->map_data.read_data[i][j]);
	valid_flag = true;
	if (1 <= id_num && id_num <= 4)
		valid_flag = parse_path(data, i, j, id_num);
	else if (id_num == 5 && data->floor.done_flag == false)
	{
		data->floor.done_flag = true;
		valid_flag = parse_floor(data, i, j);
	}
	else if (id_num == 6 && data->ceiling.done_flag == false)
	{
		data->ceiling.done_flag = true;
		valid_flag = parse_ceiling(data, i, j);
	}
	return (valid_flag);
}
