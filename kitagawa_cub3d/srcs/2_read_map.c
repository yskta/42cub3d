/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:43:39 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/09 21:03:27 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool    read_map(char *argv, t_data *data)
{
    data->map_data->fd = open(argv, O_RDONLY);
    if (data->map_data->fd == -1)
        return (false);
    return (true);
}