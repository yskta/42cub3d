/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_end_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:43:56 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/24 23:56:15 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_program(t_data *data)
{
	free_and_destroy_all(data);
	printf("CLOSED\n");
	exit (1);
}