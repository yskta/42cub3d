/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:12:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/20 00:44:59 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	parse_texture(t_data *data, size_t i, size_t j)
{
	if (data->map_data.read_data[i][j] == 'N' && data->map_data.read_data[i][j+1] == 'O')
	{
		while (data->map_data.read_data[i][j] != 't')
			j++;
		data->north.path = ft_strdup(&data->map_data.read_data[i][j]);
	}
	else if (data->map_data.read_data[i][j] == 'S' && data->map_data.read_data[i][j+1] == 'O')
	{
		while (data->map_data.read_data[i][j] != 't')
			j++;
		data->south.path = ft_strdup(&data->map_data.read_data[i][j]);
	}
	else if (data->map_data.read_data[i][j] == 'W' && data->map_data.read_data[i][j+1] == 'E')
	{
		while (data->map_data.read_data[i][j] != 't')
			j++;
		data->west.path = ft_strdup(&data->map_data.read_data[i][j]);
	}
	else if (data->map_data.read_data[i][j] == 'E' && data->map_data.read_data[i][j+1] == 'A')
	{
		while (data->map_data.read_data[i][j] != 't')
			j++;
		data->east.path = ft_strdup(&data->map_data.read_data[i][j]);
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
		while (data->map_data.read_data[i][j] == ' ')
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
		while (data->map_data.read_data[i][j] == ' ')
			j++;
		data->ceiling.before_split = ft_strdup(&data->map_data.read_data[i][j]);
		data->ceiling.after_split = ft_split(data->floor.before_split, ',');
		data->ceiling.r = ft_atoi(data->floor.after_split[0]);
		data->ceiling.g = ft_atoi(data->floor.after_split[1]);
		data->ceiling.b = ft_atoi(data->floor.after_split[2]);
		free_two_dimensional_array(data->floor.after_split);
		free(data->floor.before_split);
		if (data->ceiling.r < 0 || data->ceiling.r > 255 || data->ceiling.g < 0 || data->ceiling.g > 255 || data->ceiling.b < 0 || data->ceiling.b > 255)
			return (false);
	}
	return (true);
}

bool	parse_each_identifer(t_data *data, size_t i, size_t j)
{
	if (data->map_data.read_data[i][j] == 'N' || data->map_data.read_data[i][j] == 'S' || data->map_data.read_data[i][j] == 'W' || data->map_data.read_data[i][j] == 'E')
		return (parse_texture(data, i, j));
	else if (data->map_data.read_data[i][j] == 'F' || data->map_data.read_data[i][j] == 'C')
		return (parse_floor_or_ceiling(data, i, j));
}

bool	parse_all_identifier(t_data *data)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (data->map_data.read_data[i] != NULL)
	{
		j = 0;
		while (data->map_data.read_data[i][j] != '\0')
		{
			if (data->map_data.read_data[i][j] == ' ' || data->map_data.read_data[i][j] == '1')
				j++;
			else if (data->map_data.read_data[i][j] == 'N' || data->map_data.read_data[i][j] == 'S' || data->map_data.read_data[i][j] == 'W' || data->map_data.read_data[i][j] == 'E' || data->map_data.read_data[i][j] == 'F' || data->map_data.read_data[i][j] == 'C')
			{
				parse_each_identifier(data, i, j);
				break ;
			}
			else
				return (false);
		}
		i++;
	}
	return (true);
}

bool	parse_map(t_data *data)
{
	return (true);
}

bool	parse_read_data(t_data *data)
{
	if (parse_all_identifier(data) == false)
	{	
		//t_data *data以外でmallocしたものをfreeする
		free_two_dimensional_array(data->map_data.read_data);
		//ここのファイルでmallocしたものをfreeする
		if (data->north.path)
			free(data->north.path);
		if (data->south.path)
			free(data->south.path);
		if (data->west.path)
			free(data->west.path);
		if (data->east.path)
			free(data->east.path);
		return (false);
	}
	if (parse_map(data) == false)
	{
		//t_data *data以外でmallocしたものをfreeする
		free_two_dimensional_array(data->map_data.read_data);
		free_two_dimensional_array(data->map_data.map);
		//ここのファイルでmallocしたものをfreeする
		free(data->north.path);
		free(data->south.path);
		free(data->west.path);
		free(data->east.path);
		return (false);
	}
	return (true);
}