/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojadiri <sojadiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:46:03 by sojadiri          #+#    #+#             */
/*   Updated: 2026/11/10 20:02:56 by sojadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_u_decimal(unsigned int u_dec)
{
	int		res;
	int		ret_value;

	res = 0;
	if (u_dec >= 10)
	{
		res = ft_print_u_decimal(u_dec / 10);
		if (res == -1)
			return (-1);
	}
	ret_value = ft_putchar(u_dec % 10 + 48);
	if (ret_value == -1)
		return (-1);
	return (res + 1);
}
