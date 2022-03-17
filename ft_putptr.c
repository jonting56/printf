/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:24:24 by jting             #+#    #+#             */
/*   Updated: 2022/03/17 12:46:41 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long long n)
{
	if (n > 15)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd(n + 'A' - 10, 1);
	}
}

int	ptr_len(unsigned long long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_printptr(unsigned long long n)
{
	int	len;

	if (n == 0)
		len = write(1, "0x0", 3);
	else
	{
		len = ptr_len(n) + 2;
		write(1, "0x", 2);
		ft_putptr(n);
	}
	return (len);
}
