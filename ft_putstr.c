/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:54:48 by jting             #+#    #+#             */
/*   Updated: 2022/03/11 12:18:06 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		ft_putstr("(null)");
	while (s[i])
		ft_putstr(s);
}

int	numlen(int n)
{
	int			i;
	long int	long_n;
	
	if (n == 0)
		return (1);
	long_n = n;
	if (long_n < 0)
	{
		long_n *= -1;
		i = 1;
	}
	while (long_n)
	{
		i++;
		long_n/= 10;
	}
	return (i);
}


int	ft_putnbr(int n)
{
	char	*num;

	num = ft_itoa(n);
	ft_printstr(num);
	return (numlen(n));
}
