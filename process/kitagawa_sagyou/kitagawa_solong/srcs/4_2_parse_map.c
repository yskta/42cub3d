/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:22 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/15 22:59:44 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_parm(t_data *data)
{
	if (data->map.n_collectibel == 0)
		put_error_and_exit("INVALID MAP7", data);
	else if (data->map.n_exit != 1)
		put_error_and_exit("INVALID MAP8", data);
	else if (data->map.n_player != 1)
		put_error_and_exit("INVALID MAP9", data);
}

void	copy_map_data(t_data *data, t_map *copy_map)
{
	copy_map->height = data->map.height;
	copy_map->width = data->map.width;
	copy_map->n_collectibel = data->map.n_collectibel;
	copy_map->n_exit = data->map.n_exit;
	copy_map->player.x = data->map.player.x;
	copy_map->player.y = data->map.player.y;
}

void	free_copied_map_puterror(char **copied_map, t_data *data)
{
	size_t	i;

	i = 0;
	while (copied_map[i] != NULL)
	{
		free(copied_map[i]);
		i++;
	}
	free(copied_map);
	put_error_and_exit("COPY MAP ERROR", data);
}

char	**copy_map_contents(t_data *data, t_map *copy_map)
{
	char	**copied_map;
	size_t	y;

	copied_map = (char **)malloc(sizeof(char *) * data->map.height);
	if (copied_map == NULL)
	{
		free(copy_map);
		put_error_and_exit("MALLOC ERROR AT COPY MAP", data);
	}
	y = 0;
	while (y < data->map.height)
	{
		copied_map[y] = ft_strdup(data->map.map[y]);
		if (copied_map[y] == NULL)
			free_copied_map_puterror(copied_map, data);
		y++;
	}
	return (copied_map);
}
