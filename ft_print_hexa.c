/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:35:47 by aleger            #+#    #+#             */
/*   Updated: 2022/02/01 15:24:20 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_hexa(unsigned int number, const char format)
{
	if (number >= 16)
	{
		ft_put_hexa(number / 16, format);
		ft_put_hexa(number % 16, format);
	}
	else
	{
		if (number <= 9)
			ft_putchar(number + '0');
		else
		{
			if (format == 'x')
				ft_putchar(number - 10 + 'a');
			if (format == 'X')
				ft_putchar(number - 10 + 'A');
		}
	}
}

int	ft_len_hexa(unsigned int number)
{
	int	i;

	i = 0;
	while (number)
	{
		number = number / 16;
		i++;
	}
	return (i);
}

int	ft_print_hexa(unsigned int number, const char format)
{
	if (number == 0)
		return (write(1, "0", 1));
	else
		ft_put_hexa(number, format);
	return (ft_len_hexa(number));
}
