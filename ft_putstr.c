/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:54:48 by jting             #+#    #+#             */
/*   Updated: 2022/03/16 15:46:17 by jting            ###   ########.fr       */
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
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		ft_putstr("(null)");
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
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
		long_n /= 10;
	}
	return (i);
}

char	*itoa(int n)
{
	int		i;
	int		len;
	char	* result;

	len = numlen(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	if (n < 0)
		n *= -1;
	i = 0;
	while (n != 0)
	{
		result[len - i - 1] = '0' + (n % 10);
		n /= 10;
		i++;
	}
	result[len] = '\0';
	return (result);
}

int	ft_putnbr(int n)
{
	char	*num;

	num = ft_itoa(n);
	ft_printstr(num);
	free(num);
	return (numlen(n));
}
