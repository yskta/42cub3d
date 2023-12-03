/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:22:36 by yokitaga          #+#    #+#             */
/*   Updated: 2023/12/03 17:06:59 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	convert_space_to_x(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == ' ')
				map[i][j] = 'X';
			j++;
		}
		i++;
	}
}

char	**copy_map_contents(t_data *data)
{
	char	**copied_map;
	size_t	i;

	i = 0;
	copied_map = malloc(sizeof(char *) * (data->map_data.map_height + 1));
	while (i < data->map_data.map_height)
	{
		copied_map[i] = ft_strdup(data->map_data.map[i]);
		i++;
	}
	copied_map[i] = NULL;
	convert_space_to_x(copied_map);
	return (copied_map);
}

bool	check_top_line(char	**map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1' && map[i][j] != 'X')
			return (false);
		j++;
	}
	return (true);
}

bool	check_bottom_line(char	**map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i + 1] != NULL)
		i++;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1' && map[i][j] != 'X')
			return (false);
		j++;
	}
	return (true);
}

bool	check_valid_map(t_data *data)
{
	char	**copied_map;

	copied_map = copy_map_contents(data);
	if (data->map_data.map[0] == NULL)
		return (false);
	if (check_top_line(copied_map) == false || \
		check_bottom_line(copied_map) == false || \
		check_leftside_wall(copied_map) == false || \
		check_rightside_wall(copied_map) == false || \
		check_num_of_player_and_invalid_char(copied_map) == false || \
		check_playable_map(copied_map) == false || \
		check_inside_wall(copied_map) == false)
	{
		free_two_dimensional_array(copied_map);
		return (false);
	}
	free_two_dimensional_array(copied_map);
	return (true);
}
