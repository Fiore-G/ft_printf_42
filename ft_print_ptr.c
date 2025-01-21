/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:45:35 by figarcia          #+#    #+#             */
/*   Updated: 2025/01/06 18:33:25 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	aux_hex(unsigned long long nb, int uppercase)
{
	char	*base;
	int		count;
	int		temp;

	count = 0;
	if (uppercase == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb >= 16)
	{
		temp = aux_hex(nb / 16, uppercase);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (write(1, &base[nb % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int	printed_chars;
	int	temp;

	printed_chars = 0;
	if (ptr == NULL)
	{
		temp = ft_print_str("(nil)");
		if (temp == -1)
			return (-1);
		printed_chars += temp;
	}
	else
	{
		temp = ft_print_str("0x");
		if (temp == -1)
			return (-1);
		printed_chars += temp;
		temp = aux_hex((unsigned long long)ptr, 0);
		if (temp == -1)
			return (-1);
		printed_chars += temp;
	}
	return (printed_chars);
}
