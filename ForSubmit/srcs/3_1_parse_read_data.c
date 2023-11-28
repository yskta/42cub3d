/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:12:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/28 15:10:51 by yokitaga         ###   ########.fr       */
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
			while (data->map_data.read_data[i][j] == ' ')
				j++;
			if (data->map_data.read_data[i][j] == '\0')
				break ;
			if (juduge_identifer(&data->map_data.read_data[i][j]) > 0)
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
	while (line[i] == ' ' || line[i] == '1')
		i++;
	if (line[i] == '\0')
		return (true);
	else
		return (false);
}

void	parse_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map_data.read_data[i] != NULL)
	{
		if (judge_space_or_wall(data->map_data.read_data[i]) == true)
		{
			data->map_data.map_height = data->map_data.read_data_height - i;
			data->map_data.map = malloc(sizeof(char *) * \
				(data->map_data.map_height + 1));
			j = 0;
			while (data->map_data.read_data[i] != NULL)
			{
				data->map_data.map[j] = ft_strdup(data->map_data.read_data[i]);
				i++;
				j++;
			}
			data->map_data.map[j] = NULL;
			break ;
		}
		i++;
	}
}

void	init_data_for_parse(t_data *data)
{
	data->north_path = NULL;
	data->south_path = NULL;
	data->west_path = NULL;
	data->east_path = NULL;
	data->map_data.map = NULL;
	data->map_data.map_height = 0;
	data->num_of_id = 0;
	data->ceiling.done_flag = false;
	data->floor.done_flag = false;
}
