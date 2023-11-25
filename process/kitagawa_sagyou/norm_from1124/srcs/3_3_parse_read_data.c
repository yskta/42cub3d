/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:22:36 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/25 00:21:39 by yokitaga         ###   ########.fr       */
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

bool	check_leftside_wall(char	**map)
{
	size_t	i;
	size_t	j;
	size_t	left_end_wall_index;

	i = 0;
	j = 0;
	while (map[0][j] == 'X')
		j++;
	left_end_wall_index = j;
	while (map[i + 1] != NULL)
	{
		if (map[i + 1][left_end_wall_index] == '0')
		{
			while (left_end_wall_index > 0)
			{
				if (map[i][left_end_wall_index - 1] == '1' && \
					map[i + 1][left_end_wall_index] == '0')
					left_end_wall_index--;
				else
					break ;
			}
			if (map[i + 1][left_end_wall_index] != '1')
				return (false);
			else
				i++;
		}
		else if (map[i + 1][left_end_wall_index] == 'X')
		{
			while (map[i][left_end_wall_index + 1] == '1' && \
				map[i + 1][left_end_wall_index] == 'X')
				left_end_wall_index++;
			if (map[i + 1][left_end_wall_index] != '1')
				return (false);
			else
				i++;
		}
		else
			i++;
	}
	return (true);
}

bool	check_rightside_wall(char	**map)
{
	size_t	i;
	size_t	j;
	size_t	right_end_wall_index;
	size_t	next_len;

	i = 0;
	j = 0;
	while (map[0][j] != '\0')
		j++;
	j--;
	while (map[0][j] == 'X')
		j--;
	right_end_wall_index = j;
	while (map[i + 1] != NULL)
	{
		next_len = ft_strlen(map[i + 1]);
		if (right_end_wall_index + 1 > next_len)
		{
			while (right_end_wall_index > 0)
			{
				if (map[i][right_end_wall_index - 1] == '1')
					right_end_wall_index--;
				else
					break ;
			}
			if (right_end_wall_index + 1 > next_len)
				return (false);
		}
		if (map[i + 1][right_end_wall_index] == 'X')
		{
			while (right_end_wall_index > 0 && \
				map[i][right_end_wall_index - 1] == '1' \
				&& map[i + 1][right_end_wall_index] == 'X')
				right_end_wall_index--;
			if (map[i + 1][right_end_wall_index] != '1')
				return (false);
			else
				i++;
		}
		else if (map[i + 1][right_end_wall_index] == '0')
		{
			while (map[i][right_end_wall_index + 1] == '1' && \
				map[i + 1][right_end_wall_index] == '0')
				right_end_wall_index++;
			if (map[i + 1][right_end_wall_index] != '1')
				return (false);
			else
				i++;
		}
		else
			i++;
	}
	return (true);
}

bool	check_num_of_player_and_invalid_char(char	**map)
{
	size_t	i;
	size_t	j;
	size_t	num_of_player;

	i = 0;
	num_of_player = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
				num_of_player++;
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'X')
				return (false);
			j++;
		}
		i++;
	}
	if (num_of_player == 1)
		return (true);
	else
		return (false);
}

bool	check_playable_map(char **map)
{
	size_t	i;
	size_t	j;
	size_t	player_pos_x;
	size_t	player_pos_y;
	size_t	above_line_len;
	size_t	under_line_len;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
			{
				player_pos_x = j;
				player_pos_y = i;
			}
			j++;
		}
		i++;
	}
	above_line_len = ft_strlen(map[player_pos_y - 1]);
	under_line_len = ft_strlen(map[player_pos_y + 1]);
	if ((above_line_len > player_pos_x + 1) && \
		(map[player_pos_y - 1][player_pos_x] == '1' || \
			map[player_pos_y - 1][player_pos_x] == '0'))
	{
		if ((under_line_len > player_pos_x + 1) && \
			(map[player_pos_y + 1][player_pos_x] == '1' || \
				map[player_pos_y + 1][player_pos_x] == '0'))
		{
			if (map[player_pos_y][player_pos_x - 1] == '1' || \
				map[player_pos_y][player_pos_x - 1] == '0')
			{
				if (map[player_pos_y][player_pos_x + 1] == '1' || \
					map[player_pos_y][player_pos_x + 1] == '0')
					return (true);
			}
		}
	}
	return (false);
}

bool	check_valid_map(t_data *data)
{
	char	**copied_map;

	copied_map = copy_map_contents(data);
	if (data->map_data.map[0] == NULL)
		return (false);
	if (check_top_line(copied_map) == false)
	{
		free_two_dimensional_array(copied_map);
		return (false);
	}
	if (check_bottom_line(copied_map) == false)
	{
		free_two_dimensional_array(copied_map);
		return (false);
	}
	if (check_leftside_wall(copied_map) == false)
	{
		free_two_dimensional_array(copied_map);
		return (false);
	}
	if (check_rightside_wall(copied_map) == false)
	{
		free_two_dimensional_array(copied_map);
		return (false);
	}
	if (check_num_of_player_and_invalid_char(copied_map) == false)
	{
		free_two_dimensional_array(copied_map);
		return (false);
	}
	if (check_playable_map(copied_map) == false)
	{
		free_two_dimensional_array(copied_map);
		return (false);
	}
	free_two_dimensional_array(copied_map);
	return (true);
}
