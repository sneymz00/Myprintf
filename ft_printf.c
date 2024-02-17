/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:35:26 by camurill          #+#    #+#             */
/*   Updated: 2024/02/17 20:07:26 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_selector(va_list args, const char places)
{
	int	size;

	size = 0;
	if (places == 'c')
		size += ft_characther(va_arg(args, int));
	else if (places == 's')
		size += ft_string(va_arg(args, char *));
	else if (places == 'd' || places == 'i')
		size += ft_number(va_arg(args, int));
	else if (places == 'u')
		size += ft_unsigned_number(va_arg(args, unsigned int));
	else if (places == 'x' || places == 'X')
		size += ft_hexadecimal(va_arg(args, unsigned int), places);
	else if (places == 'p')
		size += ft_voidpointer(va_arg(args, unsigned long), 'a');
	else
		size += ft_characther(va_arg(args, int));
	return (size);
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		x;
	int		i;

	i = 0;
	va_start(args, placeholders);
	while (placeholders[i])
	{
		if (placeholders[i] == '%')
		{
			x += ft_selector(args, placeholders[i + 1]);
			i++;
		}
		else
			x += ft_characther(placeholders[i]);
		i++;
	}
	va_end(args);
	return (1);
}
/*
int main()
{
	unsigned long n = 78787255;
	ft_printf("Hola %p", n);
}
*/