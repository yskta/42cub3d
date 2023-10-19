/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:58:57 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/14 17:26:02 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define KEY_LEFT        0xff51 
# define KEY_UP          0xff52  
# define KEY_RIGHT       0xff53  
# define KEY_DOWN        0xff54
# define KEY_ESC         0xff1b

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

typedef struct s_map{
	char	**read_data;
	char	**map;
	ssize_t	fd;
}t_map;

typedef struct s_texture{
	char	*path;
	void	*texture_ptr;
}t_texture;

typedef struct s_floor{
	int		r;
	int		g;
	int		b;
}t_floor;

typedef struct s_data{
	void		*mlx;
	void		*mlx_win;
	bool		judge_valid_map;
	t_map		map_data;
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_floor		floor;
}t_data;

bool	check_arg(int argc, char **argv);
bool	read_map(char *argv, t_data *data);
void	parse_read_data(t_data *data);

void	free_read_data(t_data *data);
void	put_error_and_exit(char *str, t_data *data);

#endif