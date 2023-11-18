/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_end_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:37 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/15 19:04:30 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_game(t_data *data)
{
	ft_printf("total steps: %d\n", data->map.steps);
	free_all(data);
	ft_printf("WIN\n");
	exit (1);
}

int	close_game(t_data *data)
{
	ft_printf("steps: %d\n", data->map.steps);
	free_all(data);
	ft_printf("CLOSED\n");
	exit (1);
}
