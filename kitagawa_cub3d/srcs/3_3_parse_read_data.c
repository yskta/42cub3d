/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_parse_read_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:22:36 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/28 15:59:23 by yokitaga         ###   ########.fr       */
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

bool	check_line(char	**map)
{
	size_t	i;
	size_t	j;
	size_t	left_end_wall_index;
	//size_t	right_end_wall_index;

	i = 0;
	j = 0;
	//左端を見ていく。
	int	k = 0;
	while (map[k] != NULL)
	{
		printf("%s\n", map[k]);
		k++;
	}
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
				if (map[i][left_end_wall_index - 1] == '1')
					left_end_wall_index--;
				else
					break ;
			}
			printf("left_end_wall_index = %zu\n", left_end_wall_index);
			//ここの時点で、left_end_wall_indexは左端の壁のindexになっている。
			if (map[i + 1][left_end_wall_index] != '1')
			{
				printf("invalid_map\n");
				return (false);
			}
			else
				i++;
		}
		else if (map[i + 1][left_end_wall_index] == 'X')
		{
			printf("map[i]: %s\n", map[i]);
			printf("map[i + 1]: %s\n", map[i + 1]);
			while(map[i][left_end_wall_index + 1] == '1')
				left_end_wall_index++;
			if (map[i + 1][left_end_wall_index] != '1')
			{
				printf("invalid_map\n");
				return (false);
			}
			else
				i++;
		}
		else
			i++;
	}
	printf("valid_map\n");
	return (true);
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
	if (check_line(copied_map) == false)
	{
		free_two_dimensional_array(copied_map);
		return (false);
	}
	free_two_dimensional_array(copied_map);
	return (true);
}