/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:23 by lgalloux          #+#    #+#             */
/*   Updated: 2024/05/26 00:34:12 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex		pipex;

	if (argc < 5)
		ft_error("wrong number of arguments\n", &pipex, -WRITE_MSG, 1);
	pipex.here_doc = 0;
	if (argc > 5)
		here_doc_verif(&pipex, argc, argv);
	struct_init(&pipex, argv, argc, env);
	init_pipe_fds(&pipex);
	parent(argv, argc - 2, &pipex);
	free_all(&pipex, FREE_LST);
	return (0);
}
