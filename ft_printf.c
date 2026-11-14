/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojadiri <sojadiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 20:02:08 by sojadiri          #+#    #+#             */
/*   Updated: 2026/11/10 20:02:11 by sojadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	perform_format(char c, va_list ap)
{
	if (c == '%')
		return (ft_putchar(c));
	else if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_print_address(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_decimal(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_print_u_decimal(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hexadecimal(va_arg(ap, unsigned int), c));
	else
		return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret_value;
	int		count_bytes;

	count_bytes = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			ret_value = (perform_format(*(++fmt), ap));
		else
			ret_value = ft_putchar(*fmt);
		if (ret_value == -1)
		{
			va_end(ap);
			return (-1);
		}
		count_bytes += ret_value;
		fmt++;
	}
	va_end(ap);
	return (count_bytes);
}
