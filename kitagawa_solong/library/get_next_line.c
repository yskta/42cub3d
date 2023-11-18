/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:18:56 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/20 18:25:26 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_for_gnl(char *s1, char *s2)
{
	char	*p;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == NULL)
		return (ft_free_for_gnl(s1));
	ft_strlcpy(p, s1, len_s1 + 1);
	ft_strlcpy(p + len_s1, s2, len_s2 + 1);
	free(s1);
	return (p);
}

char	*ft_read_get_save(int fd, char *save)
{
	char	*read_result;
	ssize_t	read_size;

	read_result = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (read_result == NULL)
		return (ft_free_for_gnl(save));
	read_size = 1;
	while (read_size != 0 && ft_strchr(save, '\n') == NULL)
	{
		read_size = read(fd, read_result, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(read_result);
			return (ft_free_for_gnl(save));
		}
		read_result[read_size] = '\0';
		save = ft_strjoin_for_gnl(save, read_result);
		if (save == NULL)
			break ;
	}
	free(read_result);
	return (save);
}

char	*ft_get_outputline(char *save)
{
	size_t	i;
	char	*output_line;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	output_line = (char *)malloc(sizeof(char) * (i + 2));
	if (output_line == NULL)
		return (ft_free_for_gnl(save));
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		output_line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		output_line[i] = save[i];
		i++;
	}
	output_line[i] = '\0';
	return (output_line);
}

char	*ft_get_next_save(char *save)
{
	size_t	i;
	size_t	j;
	size_t	save_len;
	char	*next_save;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		return (ft_free_for_gnl(save));
	save_len = ft_strlen(save);
	next_save = (char *)malloc(sizeof(char) * (save_len - i + 1));
	if (next_save == NULL)
		return (ft_free_for_gnl(save));
	i++;
	j = 0;
	while (save[i] != '\0')
		next_save[j++] = save[i++];
	next_save[j] = '\0';
	free(save);
	return (next_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*output_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || INT_MAX < BUFFER_SIZE)
		return (NULL);
	if (save == NULL)
	{
		save = (char *)malloc(sizeof(char) * 1);
		if (save == NULL)
			return (NULL);
		*save = '\0';
	}
	save = ft_read_get_save(fd, save);
	if (save == NULL)
		return (NULL);
	output_line = ft_get_outputline(save);
	save = ft_get_next_save(save);
	return (output_line);
}
