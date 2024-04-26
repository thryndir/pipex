/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:21:20 by lgalloux          #+#    #+#             */
/*   Updated: 2023/10/30 12:21:20 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	long unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((const char *)src));
}

/*int	main(void)
{
	char source[30] = "je test des choses ici";
	char destination[30];
	ft_strlcpy(destination, source, 15);
	printf("%s\n", source);
	printf("%s\n", destination);
	printf("%lu\n", ft_strlcpy(destination, source, 30));

	return (0);
}*/