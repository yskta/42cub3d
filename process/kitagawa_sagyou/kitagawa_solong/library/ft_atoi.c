/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:52:51 by yokitaga          #+#    #+#             */
/*   Updated: 2022/10/19 20:30:28 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_isspace(int c);
static const char	*ft_skipspace(const char *str);
static const char	*ft_flag(const char *str, int *sign);

static	unsigned int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static const char	*ft_skipspace(const char *str)
{
	while (ft_isspace(*str) == 1)
		str++;
	return (str);
}

static const char	*ft_flag(const char *str, int *sign)
{
	*sign = 1;
	if (*str == '-')
	{
		*sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

int	ft_atoi(const char	*str)
{
	size_t			n;
	int				flag;
	size_t			ov_dev;
	int				ov_mod;

	n = 0;
	str = ft_flag(ft_skipspace(str), &flag);
	ov_dev = LONG_MAX;
	ov_mod = ov_dev % 10;
	ov_dev = ov_dev / 10;
	while (ft_isdigit(*str) == 1)
	{
		if (n > ov_dev || (n == ov_dev && (*str - '0') > ov_mod))
		{
			if (flag == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		n = n * 10 + (*str++ - '0');
	}
	if (flag == -1)
		n *= -1;
	return ((int)n);
}
