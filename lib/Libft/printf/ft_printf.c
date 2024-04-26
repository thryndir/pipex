/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:33:42 by lgalloux          #+#    #+#             */
/*   Updated: 2023/12/30 12:48:03 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_which_type(char type, va_list l_arg)
{
	if (type == 'c')
		return (ft_printchar(va_arg(l_arg, int)));
	else if (type == 's')
		return (ft_printstr(va_arg(l_arg, char *)));
	else if (type == 'p')
		return (ft_printptr(va_arg(l_arg, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_printnbr(va_arg(l_arg, int)));
	else if (type == 'u')
		return (ft_printunbr_base(va_arg(l_arg, unsigned int), "0123456789"));
	else if (type == 'x')
		return (ft_printunbr_base(va_arg(l_arg, unsigned int), MIN));
	else if (type == 'X')
		return (ft_printunbr_base(va_arg(l_arg, unsigned int), MAJ));
	else if (type == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	l_arg;
	int		i;
	int		len;

	va_start(l_arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_which_type(format[i + 1], l_arg);
			i += 2;
		}
		else
		{
			write(1, &format[i++], 1);
			len++;
		}
	}
	return (len);
}

// int	main(void)
// {
// 	printf(" -> %d\n",ft_printf(" NULL %s NULL ", NULL));
// 	printf("-----------------\n");
// 	printf(" -> %d\n", printf("NULL %s NULL ", NULL));
// }