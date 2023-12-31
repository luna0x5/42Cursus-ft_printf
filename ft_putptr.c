/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit < hmoukit@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:30:16 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/13 12:25:26 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printptr(size_t ptr)
{
	char	*s;
	int		i;

	i = 0;
	s = "0123456789abcdef";
	if (ptr < 16)
	{
		i += write(1, &s[ptr], 1);
	}
	else
	{
		i += printptr(ptr / 16);
		i += ft_putchar(s[ptr % 16]);
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	int		i;

	i = 0;
	i += write(1, "0x", 2);
	i += printptr((size_t)ptr);
	return (i);
}
