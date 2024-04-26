/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:21:25 by lgalloux          #+#    #+#             */
/*   Updated: 2023/10/30 12:21:25 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	while (*string != '\0')
	{
		if (*string == (unsigned char)searchedChar)
			return ((char *)string);
		string++;
	}
	if (*string == (const char)searchedChar)
		return ((char *)string);
	return (NULL);
}

/*int	main(void)
{
	char * string = "Je test des choses";
	int searchedChar = 't';
	printf("%s\n", ft_strchr(string, searchedChar));
	printf("%s\n", strchr(string, searchedChar));
}*/