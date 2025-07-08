/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperedny <gperedny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:17:01 by gperedny          #+#    #+#             */
/*   Updated: 2025/07/08 16:39:58 by gperedny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	check_conversion(const char sign, va_list args)
{
	if (sign == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (sign == 's')
		return (ft_string(va_arg(args, char *)));
	else if (sign == 'p')
		return (ft_pointer(va_arg(args, void *)));
	else if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (sign == 'u')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789"));
	else if (sign == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (sign == 'u')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (sign == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *line, ...)
{
	va_list	args;
	int		i;
	int		to_print;

	i = 0;
	to_print = 0;
	if (line == NULL || !line)
		return (-1);
	va_start(args, line);
	while (line[i])
	{
		if (line[i] == '%' && line[i + 1])
		{
			i++;
			to_print += check_conversion(line[i], args);
		}
		else
			to_print += ft_putchar(line[i]);
		i++;
	}
	va_end(args);
	return (to_print);
}

int	main(void)
{
	int count;
	void *p = &count;

	count = ft_printf("Hi %citch!\n", 'B');
	printf("we should get %d characters\n", count);
	count = ft_printf("Hi %s!\n", "Bitch");
	printf("we should get %d characters\n", count);
	count = ft_printf("address is %p\n", p);
	printf("we should get %d characters\n", count);
	count = ft_printf("2%i is %d too\n", 2, 20);
	printf("we should get %d characters\n", count);
	count = ft_printf("Unsigned: %u\n", 123456);
	printf("Printed %d chars\n", count);
	count = ft_printf("Hex lower: %x\n", 0xabc123);
	printf("Printed %d chars\n", count);
	count = ft_printf("Hex upper: %X\n", 0xabc123);
	printf("Printed %d chars\n", count);
	count = ft_printf("100%% sure this works!\n");
	printf("we should get %d characters\n", count);
	return (0);
}