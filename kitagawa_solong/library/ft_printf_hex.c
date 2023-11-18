/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:45:46 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/11 15:38:58 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_showhex(unsigned int u, int fmt)
{
	char			*num;
	unsigned int	i;
	unsigned int	u_mod;
	unsigned int	u_dev;

	i = ft_hex_len(u);
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (num == NULL)
		return (NULL);
	u_dev = u;
	num[i] = '\0';
	while (u_dev != 0)
	{
		i--;
		u_mod = u_dev % 16;
		if (u_mod <= 9)
			num[i] = u_mod + '0';
		else if (fmt == 'X')
			num[i] = u_mod - 10 + 'A';
		else if (fmt == 'x')
			num[i] = u_mod - 10 + 'a';
		u_dev /= 16;
	}
	return (num);
}

unsigned int	ft_hex_len(unsigned int u)
{
	unsigned int	u_len;

	u_len = 0;
	while (u != 0)
	{
		u_len++;
		u /= 16;
	}
	return (u_len);
}

int	ft_cntputhexa(unsigned int u, int fmt)
{
	int		add_count;
	char	*num;

	if (u == 0)
		return (ft_count_and_putchar('0'));
	num = ft_showhex(u, fmt);
	add_count = ft_count_and_putstr(num);
	free(num);
	return (add_count);
}
