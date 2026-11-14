/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojadiri <sojadiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:45:54 by sojadiri          #+#    #+#             */
/*   Updated: 2026/11/10 20:02:47 by sojadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_decimal(int dec)
{
	int		ret_value;
	int		res;

	if (dec == -2147483648)
		return (write(1, "-2147483648", 11));
	if (dec < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		ret_value = ft_print_decimal(-dec);
		if (ret_value == -1)
			return (-1);
		return (ret_value + 1);
	}
	res = 0;
	if (dec >= 10)
	{
		res = ft_print_decimal(dec / 10);
		if (res == -1)
			return (-1);
	}
	ret_value = ft_putchar(dec % 10 + '0');
	if (ret_value == -1)
		return (-1);
	return (res + 1);
}
