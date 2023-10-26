/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:12:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/27 00:12:29 by yokitaga         ###   ########.fr       */
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
		printf("index: %zu\n", i);
		if (data->map_data.read_data[i][j] == '1')
		{
			i++;
			printf("2\n");
			continue;
		}
		while (data->map_data.read_data[i][j] != '\0')
		{
			if (data->map_data.read_data[i][j] == ' ')
			{
				while (data->map_data.read_data[i][j] == ' ')
					j++;
				if (data->map_data.read_data[i][j] == '\0')
					break ;
			}
			if (juduge_identifer(&data->map_data.read_data[i][j]) == true)
			{
				printf("1\n");
				if (parse_each_identifier(data, i, j) == false)
					return (false);
				break ;
			}
			else if (data->map_data.read_data[i][j] != '1')
				break ;
		}
		i++;
	}
	return (true);
}

//要修正
bool	parse_map(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map_data.read_data[i] != NULL)
	{
		if (ft_strchr(data->map_data.read_data[i], '1') != NULL)
		{
			data->map_data.map_height = data->map_data.read_data_height - i;
			printf("map_height: %ld\n", data->map_data.map_height);
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
		free_map_data_and_texture(data);
		return (false);
	}
	else if (parse_map(data) == false)
	{
		free_map_data_and_texture(data);
		return (false);
	}
	return (true);
}