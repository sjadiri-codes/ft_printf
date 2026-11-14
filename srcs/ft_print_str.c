/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojadiri <sojadiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 09:45:28 by sojadiri          #+#    #+#             */
/*   Updated: 2026/11/10 20:02:53 by sojadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_str(const char *str)
{
	size_t	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}
