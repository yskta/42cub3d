/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parse_read_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:12:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/14 17:28:02 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_read_data(t_data *data)
{
	parse_identifier_and_path(data);
}

void	parse_identifier_and_path(t_data *data)
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
				j++;
			else if (data->map_data.read_data[i][j] == 'N')
			{
				parse_texture(data, identifier, i, j);
				break ;
			}
			else if (data->map_data.read_data[i][j] == 'S')
			{
				parse_texture(data, identifier, i, j);
				break ;
			}
			else if (data->map_data.read_data[i][j] == 'W')
			{
				parse_texture(data, identifier, i, j);
				break ;
			}
			else if (data->map_data.read_data[i][j] == 'E')
			{
				parse_texture(data, identifier, i, j);
				break ;
			}
			else if (data->map_data.read_data[i][j] == 'F')
			{
				parse_floor(data, identifier, i, j);
				break ;
			}
		}
		i++;
	}
}	