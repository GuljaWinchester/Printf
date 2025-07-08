/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperedny <gperedny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:23:16 by gperedny          #+#    #+#             */
/*   Updated: 2025/07/08 16:33:01 by gperedny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *line, ...);
int	ft_putchar(char c);
int	ft_string(char *str);
int	ft_pointer(void *ptr);
int	ft_puthex(unsigned long nbr, const char *base);
int	ft_pointer(void *ptr);
int	ft_putnbr(int nbr);

#endif