/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:46:05 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/14 00:20:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt(const char *s, char c);
static char		**ft_split_str(const char *s, char c, \
			char **split_str, size_t split_cnt);
static char		**ft_free(char **list);

static size_t	ft_cnt(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*(char *)s == c)
			s++;
		else
		{
			while (*s != '\0' && *(char *)s != c)
				s++;
			cnt++;
		}
	}
	return (cnt);
}

char	**ft_split_str(const char *s, char c, \
		char **split_str, size_t split_cnt)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	index = 0;
	while (s[i] != '\0' && index < split_cnt)
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
		{
			j = i + 1;
			while (s[j] != '\0' && s[j] != c)
				j++;
			split_str[index] = ft_substr(s, i, j - i);
			if (split_str[index] == NULL)
				return (ft_free(split_str));
			index++;
			i = j;
		}
	}
	split_str[split_cnt] = NULL;
	return (split_str);
}

static char	**ft_free(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	size_t	split_cnt;

	if (s == NULL)
		return (NULL);
	split_cnt = ft_cnt(s, c);
	split_str = (char **)malloc(sizeof(char *) * (split_cnt + 1));
	if (split_str == NULL)
		return (NULL);
	split_str = ft_split_str(s, c, split_str, split_cnt);
	return (split_str);
}
