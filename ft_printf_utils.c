/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:26:45 by figarcia          #+#    #+#             */
/*   Updated: 2025/01/06 18:32:05 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	i;

	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_print_char(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_int(int n)
{
	int	count;
	int	temp;

	count = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 0)
	{
		temp = ft_print_unsigned((unsigned int)n);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int		count;
	int		temp;
	char	c;

	count = 0;
	if (n >= 10)
	{
		temp = ft_print_unsigned(n / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	char	*base;
	int		count;
	int		temp;

	count = 0;
	if (uppercase == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		temp = ft_print_hex(n / 16, uppercase);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	count++;
	return (count);
}
