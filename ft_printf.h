/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperedny <gperedny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:23:16 by gperedny          #+#    #+#             */
/*   Updated: 2025/07/09 13:42:17 by gperedny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *line, ...);
int	ft_putchar(char c);
int	ft_string(char *str);
int	ft_pointer(void *ptr);
int	ft_puthex(unsigned long nbr, const char *base);
int	ft_pointer(void *ptr);
int	ft_putnbr(int nbr);

#endif