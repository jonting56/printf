/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:19:38 by jting             #+#    #+#             */
/*   Updated: 2022/03/16 15:43:38 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		check_char(va_list input, const char spec);
int		ft_putchar(int c);
void	ft_putstr(char *s);
int		ft_printstr(char *s);
int		numlen(int n);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		hex_len(unsigned long n);
void	ft_putchar_fd(char c, int fd);
int		ft_puthex(unsigned long n, const char spec);
char	*ft_itoa(int n);

#endif
