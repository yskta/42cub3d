/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:06 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/15 17:54:01 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(int argc, char *argv[], t_data *data)
{
	if (argc != 2)
		put_error_and_exit("ARG ERROR1", data);
	check_extention(argv[1], data);
}

void	check_extention(char *argv, t_data *data)
{
	char	*extention;
	size_t	argv_len;
	size_t	ext_len;

	extention = ".ber";
	ext_len = 4;
	argv_len = ft_strlen(argv);
	if (ft_strchr(argv, '.') == NULL || argv_len <= ext_len)
		put_error_and_exit("ARG ERROR2", data);
	while (ext_len)
	{
		ext_len--;
		argv_len--;
		if (argv[argv_len] != extention[ext_len])
			put_error_and_exit("ARG ERROR3", data);
	}
}
