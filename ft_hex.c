/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:19:32 by jting             #+#    #+#             */
/*   Updated: 2022/03/16 15:30:23 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char		*result;
	int			len;
	int long	long_n;
	int			i;

	len = numlen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	if (n == 0)
		result[0] = '0';
	long_n = n;
	i = 0;
	while (long_n)
	{
		result[len - i + 1] = '0' + (long_n % 10);
		long_n /= 10;
		i++;
	}
	result[len] = '\0';
	ft_putstr(result);
	return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	hex_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long n, const char spec)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, spec);
		ft_puthex(n % 16, spec);
	}
	if (n <= 9)
		ft_putchar_fd(n + '0' - 10, 1);
	else if (spec == 'x')
		ft_putchar_fd(n + 'a' - 10, 1);
	else if (spec == 'X')
		ft_putchar_fd(n + 'A' - 10, 1);
	return (hex_len(n));
}
