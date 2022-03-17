/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:19:38 by jting             #+#    #+#             */
/*   Updated: 2022/03/17 15:27:29 by jting            ###   ########.fr       */
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
int		ft_printpercent(void);
void	ft_putstr(char *s);
int		ft_printstr(char *s);
int		num_len(int n);
int		unsign_len(unsigned int n);
int		ft_putnbr(int n);
int		ft_putunsign(unsigned int n);
int		hex_len(unsigned int n);
void	ft_putchar_fd(char c, int fd);
int		ft_puthex(unsigned int n, const char spec);
char	*ft_itoa(int n);
void	ft_putptr(unsigned long long n);
int		ptr_len(unsigned long long n);
int		ft_printptr(unsigned long long n);

#endif
