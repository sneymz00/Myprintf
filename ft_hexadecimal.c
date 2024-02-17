/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:07:13 by camurill          #+#    #+#             */
/*   Updated: 2024/02/17 20:08:03 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned int hexa, const char places)
{
	char	tab[17];
	char	tab2[17];

	tab[17] = "0123456789ABCDEF";
	tab2[17] = "0123456789abcdef";
	if (hexa > 15)
		ft_hexadecimal(hexa / 16, places);
	if (places == 'X')
		ft_characther(tab[hexa % 16]);
	else if (places == 'x')
		ft_characther(tab2[hexa % 16]);
	return (1);
}

int	ft_voidpointer(unsigned long n, char i)
{
	char	tab[17];

	tab[17] = "0123456789abcdef";
	if (i == 'a')
	{
		ft_string("0x");
		i++;
	}
	if (n > 15)
		ft_voidpointer(n / 16, i);
	ft_characther(tab[n % 16]);
	return (1);
}
/*
int main()
{
    int decimalValue = 255;

    ft_hexadecimal(decimalValue, 'U');
    printf("\n");

    return 0;
}
*/
