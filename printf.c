/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperedny <gperedny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:17:01 by gperedny          #+#    #+#             */
/*   Updated: 2025/07/03 16:34:01 by gperedny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

ft_putchar(va_arg *args)
{
}

check_conversion(unsigned char *sign, va_list *args)
{
	if (sign == "c")
		return (ft_putchar(va_arg(args, int)));
}

int	ft_printf(const char *line, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, line);
	if (line == NULL)
		return (-1);
	while (*line)
	{
		if (line[i] == '%')
		{
			i++;
			check_conversion(i, &args);
		}
	}
	va_end(args);
}
