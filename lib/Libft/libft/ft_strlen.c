/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:37:55 by lgalloux          #+#    #+#             */
/*   Updated: 2023/10/26 15:00:00 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	cpt_str;

	cpt_str = 0;
	while (*str != '\0')
	{
		str++;
		cpt_str++;
	}
	return (cpt_str);
}

/*int	main(void)
{
	char *test = "test";
	printf("%ld\n%d\n", strlen(test), ft_strlen(test));
}*/