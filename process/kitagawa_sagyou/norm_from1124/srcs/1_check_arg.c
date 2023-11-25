/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:41:13 by yokitaga          #+#    #+#             */
/*   Updated: 2023/11/24 23:47:47 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_arg(int argc, char **argv)
{
	char	*ext;
	size_t	ext_len;
	size_t	arg_len;

	if (argc != 2)
		return (false);
	ext = ".cub";
	ext_len = 4;
	arg_len = ft_strlen(argv[1]);
	if (ft_strchr(argv[1], '.') == NULL || arg_len <= ext_len)
		return (false);
	while (ext_len)
	{
		ext_len--;
		arg_len--;
		if (argv[1][arg_len] != ext[ext_len])
			return (false);
	}
	return (true);
}
