/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:46:05 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/08 23:02:14 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ucntdigit(unsigned int n)
{
	if ((n / 10) == 0)
		return (1);
	else
		return (1 + ucntdigit(n / 10));
}

void	convert_uint_to_char(unsigned int n, char *num, int n_digit)
{
	if (n >= 10)
		convert_uint_to_char((n / 10), num, (n_digit - 1));
	num[n_digit] = (n % 10) + '0';
}

char	*ft_unsigneditoa(unsigned int n)
{
	char	*num;
	int		n_digit;

	n_digit = ucntdigit(n);
	num = (char *)malloc(sizeof(char) * (n_digit + 1));
	if (num == NULL)
		return (NULL);
	num[n_digit] = '\0';
	n_digit -= 1;
	convert_uint_to_char(n, num, n_digit);
	return (num);
}

int	ft_cntputunsigned(unsigned int u)
{
	char	*num;
	int		add_count;

	num = ft_unsigneditoa(u);
	add_count = ft_count_and_putstr(num);
	free(num);
	return (add_count);
}
