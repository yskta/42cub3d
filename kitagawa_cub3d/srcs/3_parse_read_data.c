/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parse_read_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:12:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/14 15:18:53 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_read_data(t_data *data)
{
	int i;
	
	i = 0;
	while (data->map_data->read_data[i])
	{
		printf("%s\n", data->map_data->read_data[i]);
		i++;
	}
}