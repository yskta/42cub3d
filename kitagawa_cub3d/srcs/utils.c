/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:32:13 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/09 19:36:09 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_error_and_exit(char *str, t_data *data)
{
	if (data && data->judge_valid_map == true)
		free_map(data);
	printf("%s\n", str);
	exit (1);
}