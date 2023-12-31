/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:11:37 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/09 07:44:11 by hmoukit          ###   ########.fr       */
/*       
                                                                     */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkformat(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		i = ft_putstr(va_arg(ap, char *));
	else if (c == 'p')
		i = ft_putptr(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		i = ft_putuns(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		i = ft_puthexa(va_arg(ap, unsigned int), c);
	else if (c == '%')
		i = ft_putchar('%');
	else if (c != '\0')
		i = ft_putchar(c);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(ap, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '%')
			count += ft_putchar(s[i]);
		else
		{
			i++;
			count += checkformat(s[i], ap);
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	va_end(ap);
	return (count);
}
