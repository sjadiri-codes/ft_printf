/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojadiri <sojadiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:59:38 by sojadiri          #+#    #+#             */
/*   Updated: 2026/11/10 20:02:32 by sojadiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *fmt, ...);
int	ft_print_decimal(int dec);
int	ft_putchar(char c);
int	ft_print_str(const char *str);
int	ft_print_u_decimal(unsigned int u_dec);
int	ft_print_hexadecimal(unsigned long dec, char c);
int	ft_print_address(void *ptr);

#endif
