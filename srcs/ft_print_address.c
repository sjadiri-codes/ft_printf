/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojadiri <sojadiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:47:37 by sojadiri          #+#    #+#             */
/*   Updated: 2026/11/10 20:02:44 by sojadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_address(void *ptr)
{
	int				ret_value;
	unsigned long	addr;
	int				res;

	if (!ptr)
		return (ft_print_str("(nil)"));
	addr = (unsigned long)ptr;
	ret_value = ft_print_str("0x");
	if (ret_value == -1)
		return (-1);
	res = ret_value;
	ret_value = ft_print_hexadecimal(addr, 'x');
	if (ret_value == -1)
		return (-1);
	return (res + ret_value);
}
