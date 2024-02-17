/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:47:53 by camurill          #+#    #+#             */
/*   Updated: 2024/02/17 20:07:35 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_number(int n)
{
	char	index;

	index = 0;
	if (n == 0)
		return (ft_characther('0'));
	else if (n == -2147483648)
		return (ft_string("-2147483648"));
	if (n < 0)
	{
		index += ft_characther('-');
		n *= (-1);
	}
	if (n / 10)
		ft_number(n / 10);
	index += n % 10 + '0';
	ft_characther(index);
	return (index);
}

int	ft_unsigned_number(unsigned int n)
{
	int	index;

	index = 0;
	if (n == 0)
		return (ft_characther('0'));
	if (n > 10)
		ft_unsigned_number(n / 10);
	index = n % 10 + '0';
	write (1, &index, 1);
	return (index);
}
