/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:17:37 by jting             #+#    #+#             */
/*   Updated: 2022/03/11 11:54:23 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	int	i;
	int count;
	va_list input;

	i = 0;
	count = 0;
	va_start(input, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += check_char(input, s[i + 1]);
			i++;
		}
		else
		{
			count += ft_putchar('%');
			i++;
		}
	va_end(input);
	return (count);
}

int	check_char(va_list input, const char spec)
{
	int	count;

	count = 0;
	if (spec == 'c')
		return (ft_putchar(input, int));
	else if (spec == 's')
		return (ft_putstr(input, char *));
	else if (spec == 'p')
		return (ft_putptr(input, unsigned long long));
	else if (spec == 'd' || spec =='i')
		return (ft_putnbr(input, int));
	else if (spec == 'u')
		return (ft_putunsign(input, unsigned int));
	else if (spec == 'x' || spec == 'X')
		return (ft_puthex(input, unsigned long));
	return (count);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
