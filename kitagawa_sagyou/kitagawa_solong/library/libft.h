/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:38:52 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/21 14:59:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "stdarg.h"
# include <stddef.h>
# include <stdio.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_atoi(const char *nptr);
char			*ft_strdup(const char *src);
void			*ft_calloc(size_t number, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

int				ucntdigit(unsigned int n);
void			convert_uint_to_char(unsigned int n, char *num, int n_digit);
char			*ft_unsigneditoa(unsigned int n);
unsigned int	ft_hex_len(unsigned int u);
char			*ft_showhex(unsigned int u, int fmt);
char			*ft_showhex_forull(unsigned long long pointer);
unsigned int	ft_hex_plen(unsigned long long pointer);
int				ft_count_and_putchar(char c);
int				ft_count_and_putstr(char *s);
int				ft_count_and_putint(int i);
int				ft_cntputunsigned(unsigned int u);
int				ft_cntputhexa(unsigned int u, int fmt);
int				ft_cntputpointer(unsigned long long pointer);
int				ft_judge_and_output(va_list ap, int fmt);
int				ft_count(va_list ap, const char *fmt);
int				ft_printf(const char *fmt, ...);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*ft_strjoin_for_gnl(char *s1, char *s2);
char			*ft_free_for_gnl(char *str);
char			*ft_read_get_save(int fd, char *save);
char			*ft_get_outputline(char *save);
char			*ft_get_next_save(char *save);
char			*get_next_line(int fd);

#endif
