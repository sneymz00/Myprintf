/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:07:13 by camurill          #+#    #+#             */
/*   Updated: 2024/02/20 21:08:24 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counthexa(unsigned long n)
{
	int count;

	count = 0;
	while(n)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

int	ft_hexadecimal(unsigned int hexa, const char places)
{
	char	*tab;
	char	*tab2;
	int		count;

	tab = "0123456789ABCDEF";
	tab2 = "0123456789abcdef";
	count = ft_counthexa(hexa);
	if (hexa > 15)
		ft_hexadecimal(hexa / 16, places);
	if (places == 'X')
		ft_characther(tab[hexa % 16]);
	else if (places == 'x')
		ft_characther(tab2[hexa % 16]);
	return (count);
}

int	ft_voidpointer(unsigned long n, char i)
{
	char	*tab;
	int		count;

	tab = "0123456789ABCDEF";
	count = ft_counthexa(n) + 2;
	if (i == 'a')
	{
		ft_string("0x");
		i++;
	}
	if (n > 15)
	{
		ft_voidpointer(n / 16, i);
	}
	ft_characther(tab[n % 16]);
	return (count);
}
/*
int main()
{
    int decimalValue;
	int x;
	unsigned long n = -1;

    x = ft_hexadecimal(decimalValue, 'X');
	//x = ft_voidpointer(n, 'a');
    printf("\n%i\n", x);

    return 0;
}
*/
