/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:23 by lgalloux          #+#    #+#             */
/*   Updated: 2024/05/05 00:59:51 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_error("wrong number of arguments\n", &pipex, -1);
	struct_init(&pipex, argv, env);
	parent(argv, env, pipex);
	free_all(&pipex, 5);
	return (0);
}
