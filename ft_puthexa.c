/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit < hmoukit@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:12:53 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/13 12:24:07 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	char	*s;
	int		i;

	i = 0;
	if (c == 'x')
		s = "0123456789abcdef";
	else if (c == 'X')
		s = "0123456789ABCDEF";
	if (n < 16)
		i += write(1, &s[n], 1);
	else
	{
		i += ft_puthexa(n / 16, c);
		i += ft_putchar(s[n % 16]);
	}
	return (i);
}
