/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:21:50 by yokitaga          #+#    #+#             */
/*   Updated: 2023/10/20 11:35:00 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 100

#include <stddef.h>
#include <limits.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(const char	*str);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_free_for_gnl(char *str);
char	*ft_strjoin_for_gnl(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
