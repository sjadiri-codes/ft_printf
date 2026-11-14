/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojadiri <sojadiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:46:23 by sojadiri          #+#    #+#             */
/*   Updated: 2026/11/10 20:02:50 by sojadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hexadecimal(unsigned long dec, char c)
{
	char	*upper_hex;
	char	*lower_hex;
	int		ret_value;
	int		res;

	upper_hex = "0123456789ABCDEF";
	lower_hex = "0123456789abcdef";
	res = 0;
	if (dec >= 16)
	{
		res = ft_print_hexadecimal(dec / 16, c);
		if (res == -1)
			return (-1);
	}
	if (c == 'x')
		ret_value = ft_putchar(lower_hex[dec % 16]);
	else
		ret_value = ft_putchar(upper_hex[dec % 16]);
	if (ret_value == -1)
		return (-1);
	return (res + 1);
}
