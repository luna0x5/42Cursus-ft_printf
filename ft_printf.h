/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:12:01 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/09 08:00:25 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *s);
int	ft_puthexa(unsigned int n, char c);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putuns(unsigned int n);
int	ft_putptr(void *ptr);
int	ft_printf(const char *s, ...);

#endif