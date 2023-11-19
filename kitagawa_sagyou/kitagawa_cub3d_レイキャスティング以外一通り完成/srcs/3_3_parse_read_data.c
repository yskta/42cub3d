/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:22:36 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/28 18:10:45 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	convert_space_to_X(char **map)
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
	convert_space_to_X(copied_map);
	return (copied_map);
}

// bool	check_row(t_data *data)
// {
// 	size_t	i;

// 	i = 0;
// 	while (data->map_data.map[data->map_data.map_height - 1][i] != '\0')
// 	{
// 		if (data->map_data.map[data->map_data.map_height - 1][i] != '1' && data->map_data.map[data->map_data.map_height - 1][i] != ' ')
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

bool	check_top_line(char	**map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1' && map[i][j] != 'X')
		{
			printf("invalid_map in top_line\n");
			return (false);
		}
		j++;
	}
	printf("valid_map in top_line\n");
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
		{
			printf("invalid_map in bottom_line\n");
			return (false);
		}
		j++;
	}
	printf("valid_map in bottom_line\n");
	return (true);
}

bool	check_leftside_wall(char	**map)
{
	size_t	i;
	size_t	j;
	size_t	left_end_wall_index;
	//size_t	right_end_wall_index;

	i = 0;
	j = 0;
	//左端を見ていく。
	// int	k = 0;
	// while (map[k] != NULL)
	// {
	// 	printf("%s\n", map[k]);
	// 	k++;
	// }
	while (map[0][j] == 'X')//1行目の左端の壁のindexを探す。
		j++;
	left_end_wall_index = j;
	printf("left_end_wall_index = %zu\n", left_end_wall_index);
	while(map[i + 1] != NULL)//2行目以降の左端の壁
	{
		if (map[i + 1][left_end_wall_index] == '0')
		{
			printf("map[i]: %s\n", map[i]);
			printf("map[i + 1]: %s\n", map[i + 1]);
			//左橋の壁のindexを探す。
			while(left_end_wall_index > 0)
			{
				if (map[i][left_end_wall_index - 1] == '1' && map[i + 1][left_end_wall_index] == '0')
					left_end_wall_index--;
				else
					break ;
			}
			printf("left_end_wall_index = %zu\n", left_end_wall_index);
			//ここの時点で、left_end_wall_indexは左端の壁のindexになっている。
			if (map[i + 1][left_end_wall_index] != '1')
			{
				printf("invalid_map in leftsidewall\n");
				return (false);
			}
			else
				i++;
		}
		else if (map[i + 1][left_end_wall_index] == 'X')
		{
			printf("map[i]: %s\n", map[i]);
			printf("map[i + 1]: %s\n", map[i + 1]);
			while(map[i][left_end_wall_index + 1] == '1' && map[i + 1][left_end_wall_index] == 'X')
				left_end_wall_index++;
			if (map[i + 1][left_end_wall_index] != '1')
			{
				printf("invalid_map in leftsidewall\n");
				return (false);
			}
			else
				i++;
		}
		else
			i++;
	}
	printf("valid_map in leftsidewall\n");
	return (true);
}

bool	check_rightside_wall(char	**map)
{
	size_t	i;
	size_t	j;
	size_t	right_end_wall_index;

	i = 0;
	j = 0;
	//右端を見ていく。
	while (map[0][j] != '\0')//1行目の右端の壁のindexを探す。
		j++;
	j--;
	while (map[0][j] == 'X')//1行目の右端の壁のindexを探す。
		j--;
	right_end_wall_index = j;
	printf("right_end_wall_index = %zu\n", right_end_wall_index);
	while (map[i + 1] != NULL)
	{
		size_t next_len = ft_strlen(map[i + 1]);
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
			{
				printf("invalid_map in rightsidewall\n");
				return (false);
			}
		}
		if (map[i + 1][right_end_wall_index] == 'X')
		{
			printf("map[i]: %s\n", map[i]);
			printf("map[i + 1]: %s\n", map[i + 1]);
			//右端の壁のindexを探す。
			while(right_end_wall_index > 0 && map[i][right_end_wall_index - 1] == '1' && map[i + 1][right_end_wall_index] == 'X')
				right_end_wall_index--;
			//ここの時点で、right_end_wall_indexは右端の壁のindexになっている。
			if (map[i + 1][right_end_wall_index] != '1')
			{
				printf("invalid_map in rightsidewall\n");
				return (false);
			}
			else
				i++;
		}
		else if (map[i + 1][right_end_wall_index] == '0')
		{
			printf("map[i]: %s\n", map[i]);
			printf("map[i + 1]: %s\n", map[i + 1]);
			while(map[i][right_end_wall_index + 1] == '1' && map[i + 1][right_end_wall_index] == '0')
				right_end_wall_index++;
			if (map[i + 1][right_end_wall_index] != '1')
			{
				printf("invalid_map in rightsidewall\n");
				return (false);
			}
			else
				i++;
		}
		else
			i++;
	}
	printf("valid_map in rightsidewall\n");
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
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				num_of_player++;
			else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'X')
			{
				printf("invalid_map invalid_char\n");
				return (false);
			}
			j++;
		}
		i++;
	}
	if (num_of_player == 1)
		return (true);
	else
	{
		printf("invalid_map num_of_player\n");
		return (false);
	}
}

bool	check_playable_map(char **map)
{
	size_t	i;
	size_t	j;
	size_t	player_pos_x;
	size_t	player_pos_y;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				player_pos_x = j;
				player_pos_y = i;
			}
			j++;
		}
		i++;
	}
	//playerの周りが1か0かどうかだけみれば、playableかどうかわかる。
	size_t above_line_len = ft_strlen(map[player_pos_y - 1]);
	size_t under_line_len = ft_strlen(map[player_pos_y + 1]);
	if ((above_line_len > player_pos_x + 1) && (map[player_pos_y - 1][player_pos_x] == '1' || map[player_pos_y - 1][player_pos_x] == '0'))
	{
		if ((under_line_len > player_pos_x + 1) && (map[player_pos_y + 1][player_pos_x] == '1' || map[player_pos_y + 1][player_pos_x] == '0'))
		{
			if (map[player_pos_y][player_pos_x - 1] == '1' || map[player_pos_y][player_pos_x - 1] == '0')
			{
				if (map[player_pos_y][player_pos_x + 1] == '1' || map[player_pos_y][player_pos_x + 1] == '0')
					return (true);
			}
		}
	}
	printf("invalid_map in playable_map\n");
	return (false);
}

bool	check_valid_map(t_data *data)
{
	char **copied_map;
	
	copied_map = copy_map_contents(data);
	// int i = 0;
	// while (copied_map[i] != NULL)
	// {
	// 	printf("%s\n", copied_map[i]);
	// 	i++;
	// }
	if(data->map_data.map[0] == NULL)
		return (false);
	// if (check_row(data) == false)
	// 	return (false);
	// int k = 0;
	// while (data->map_data.read_data[k] != NULL)
	// {
	// 	printf("data->map_data.read_data[k]:%s\n", data->map_data.read_data[k]);
	// 	k++;
	// }
	// k = 0;
	// while (data->map_data.map[k] != NULL)
	// {
	// 	printf("data->map_data.map[k]:%s\n", data->map_data.map[k]);
	// 	k++;
	// }
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
	printf("valid_map\n");
	return (true);
}