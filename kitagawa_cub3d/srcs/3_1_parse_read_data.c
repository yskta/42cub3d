/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:12:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/28 15:31:56 by yokitaga         ###   ########.fr       */
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
				if (parse_each_identifier(data, i, j) == false)
					return (false);
				break ;
			}
			else
				break ;
		}
		i++;
	}
	return (true);
}

bool	judge_space_or_wall(char *line)
{
	size_t	i;

	i = 0;
	printf("line:%s\n", line);
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '1'))
		i++;
	if (line[i] == '\0')
		return (true);
	else
		return (false);
}

bool	parse_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map_data.read_data[i] != NULL)
	{
		if (judge_space_or_wall(data->map_data.read_data[i]) == true)
		{
			data->map_data.map_height = data->map_data.read_data_height - i;
			data->map_data.map = malloc(sizeof(char *) * (data->map_data.map_height + 1));
			j = 0;
			while (data->map_data.read_data[i] != NULL)
			{
				printf("data->map_data.read_data[i]:%s\n", data->map_data.read_data[i]);
				data->map_data.map[j] = ft_strdup(data->map_data.read_data[i]);
				printf("data->map_data.map[j]:%s\n", data->map_data.map[j]);
				i++;
				j++;
			}
			data->map_data.map[j] = NULL;
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