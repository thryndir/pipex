/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:40 by lgalloux          #+#    #+#             */
/*   Updated: 2023/11/06 17:14:34 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(const char *set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	trimright;
	size_t	trimleft;
	char	*trimmed;

	if (!str || !set)
		return (NULL);
	trimright = (ft_strlen(str) - 1);
	trimleft = 0;
	while (is_in_set(set, str[trimright]))
		trimright--;
	while (is_in_set(set, str[trimleft]))
		trimleft++;
	if (trimleft > trimright)
		return (ft_strdup(""));
	trimmed = ft_substr(str, trimleft, trimright - trimleft + 1);
	return (trimmed);
}

/*int	main(void)
{
	char *test = "  \t \t \n   \n\n\n\t";
	char *charactere = " \n\t";

	ft_strtrim(test, charactere);
}*/