# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:45:48 by snemoto           #+#    #+#              #
#    Updated: 2023/11/28 14:57:45 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make all

# **************************************************************************** #

VAL=id_color_1.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_color_2.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_color_3.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_color_4.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_color_5.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_color_6.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

 VAL=id_color_7.cub
 echo ------------$VAL--------------
 ./cub3D map/invalid_map/$VAL

 VAL=id_color_8.cub
 echo ------------$VAL--------------
 ./cub3D map/invalid_map/$VAL

VAL=id_color_9.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_color_10.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

# **************************************************************************** #

VAL=id_dir_1.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_dir_2.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_dir_3.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_dir_4.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_dir_5.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_dir_6.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_dir_6.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

# **************************************************************************** #

VAL=id_duplicate_1.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_duplicate_2.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

# **************************************************************************** #

VAL=id_path_1.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_path_2.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=id_path_3.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

# **************************************************************************** #

VAL=no_access.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=no_ext.txt
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=no_id.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

# VAL=no_map.cub
# echo ------------$VAL--------------
# ./cub3D map/invalid_map/$VAL

# **************************************************************************** #

VAL=pos_invalidchar.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=pos_multiplayer.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=pos_notplayable.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=wall_bottomline.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

# **************************************************************************** #

VAL=wall_bottomline.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=wall_leftside_1.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=wall_leftside_2.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=wall_leftside_3.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=wall_rightside_1.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=wall_rightside_2.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=wall_rightside_3.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

VAL=wall_topline.cub
echo ------------$VAL--------------
./cub3D map/invalid_map/$VAL

# **************************************************************************** #

make fclean
