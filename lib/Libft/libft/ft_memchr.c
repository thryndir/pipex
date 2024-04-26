/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:21:41 by lgalloux          #+#    #+#             */
/*   Updated: 2023/10/30 12:21:41 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)memoryBlock == (unsigned char)searchedChar)
			return ((void *)memoryBlock);
		memoryBlock++;
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	const unsigned int size = 10;
	printf("%p\n", ft_memchr(data, 61, size));
	printf("%p\n", ft_memchr(data, 70, size));
	printf("%p\n", ft_memchr(data, 80, size));
	printf("%p\n", memchr(data, 61, size));
	printf("%p\n", memchr(data, 70, size));
	printf("%p\n", memchr(data, 80, size));
}*/