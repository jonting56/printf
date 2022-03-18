/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:14:06 by jting             #+#    #+#             */
/*   Updated: 2022/03/18 10:26:50 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsign_len(unsigned int n)
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

char	*ft_uitoa(unsigned int n)
{
	int		len;
	int		i;
	char	*result;

	len = unsign_len(n);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		result[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	result[len] = '\0';
	return (result);
}

int	ft_putunsign(unsigned int n)
{
	int		count;
	char	*result;

	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	else
	{
		result = ft_uitoa(n);
		count += ft_printstr(result);
		free(result);
	}
	return (count);
}
