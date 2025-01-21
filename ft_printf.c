/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:18:54 by figarcia          #+#    #+#             */
/*   Updated: 2025/01/06 18:04:53 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == 'c')
		size += ft_print_char((char)va_arg(argument, int));
	else if (word == 's')
		size += ft_print_str(va_arg(argument, char *));
	else if (word == 'p')
		size += ft_print_ptr(va_arg(argument, void *));
	else if (word == 'd' || word == 'i')
		size += ft_print_int(va_arg(argument, int));
	else if (word == 'u')
		size += ft_print_unsigned(va_arg(argument, unsigned int));
	else if (word == 'x' || word == 'X')
		size += ft_print_hex(va_arg(argument, unsigned int), word == 'X');
	else if (word == '%')
		size += ft_print_char('%');
	else
	{
		size += ft_print_char('%');
		size += ft_print_char(word);
	}
	return (size);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		size;
	va_list	argument;

	i = 0;
	size = 0;
	va_start(argument, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			size += ft_print_char('%');
			i += 2;
		}
		else if (str[i] == '%')
		{
			size += ft_select_format(argument, str[i + 1]);
			i += 2;
		}
		else
			size += ft_print_char(str[i++]);
	}
	va_end(argument);
	return (size);
}
