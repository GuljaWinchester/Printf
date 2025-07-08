/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperedny <gperedny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:38:04 by gperedny          #+#    #+#             */
/*   Updated: 2025/07/08 16:33:09 by gperedny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
int	ft_puthex(unsigned long nbr, const char *base)
{
	unsigned int	len;
	int				count;

	len = 0;
	count = 0;
	while (base[len])
		len++;
	if (nbr >= len)
		count += ft_puthex(nbr / len, base);
	count += ft_putchar(base[nbr % len]);
	return (count);
}
int	ft_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "0x0", 3));
	count += ft_string("0x");
	count += ft_puthex((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
int	ft_putnbr(int nbr)
{
	long nb;
	int count;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}