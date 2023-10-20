/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:12:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/20 11:12:22 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	parse_all_identifier(t_data *data)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (data->map_data.read_data[i] != NULL)
	{
		j = 0;
		if (data->map_data.read_data[i][j] == '1')
		{
			i++;
			continue;
		}
		while (data->map_data.read_data[i][j] != '\0')
		{
			if (data->map_data.read_data[i][j] == ' ')
				j++;
			else if (juduge_identifer(&data->map_data.read_data[i][j]) == true)
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
	size_t	i;

	i = 0;
	while (data->map_data.read_data[i] != NULL)
	{
		if (ft_strchr(data->map_data.read_data[i], '1') != NULL)
		{
			data->map_data.map_height = data->map_data.read_data_height - i;
			data->map_data.map = malloc(sizeof(char *) * (data->map_data.map_height + 1));
			while (data->map_data.read_data[i] != NULL)
			{
				data->map_data.map[i] = ft_strdup(data->map_data.read_data[i]);
				i++;
			}
			data->map_data.map[i] = NULL;
			break ;
		}
		i++;
	}
	if (check_valid_map(data) == false)
		return (false);
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