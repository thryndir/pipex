/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 00:33:39 by lgalloux          #+#    #+#             */
/*   Updated: 2024/05/12 01:42:39 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	ft_error(char *message, t_pipex *pipex, int which, int status)
{
	if (which >= 1)
		ft_putstr_fd(message, 2);
	free_all(pipex, which);
	exit(status);
}

void	return_code(t_pipex *pipex)
{
	if (WIFEXITED(pipex->status))
	{
		if (WEXITSTATUS(pipex->status) == 127)
		{
			ft_printf("zsh: command not found: %s\n", pipex->cmd_1[0]);
			ft_error("", pipex, 6, WEXITSTATUS(pipex->status));
		}
		ft_error(strerror(WEXITSTATUS(pipex->status)), pipex,
			6, WEXITSTATUS(pipex->status));
	}
}

void	free_all(t_pipex *pipex, int which)
{
	if (which >= 2)
		double_array_free(pipex->p_path);
	if (which >= 3)
		double_array_free(pipex->cmd_0);
	if (which >= 4)
		double_array_free(pipex->cmd_1);
	if (which >= 5)
		free(pipex->path_0);
	if (which >= 6)
		free(pipex->path_1);
	if (which >= 7)
	{
		close(pipex->fds[0]);
		close(pipex->fds[1]);
	}
}
