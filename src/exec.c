/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:48:48 by lgalloux          #+#    #+#             */
/*   Updated: 2024/05/30 02:24:55 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	runner(int current, t_pipex *pipex, int which_child)
{
	if (which_child == FIRST_CHILD)
	{
		fork_init(pipex);
		if (ft_lstlast(pipex->lst)->data == 0)
			first_child(current, *pipex, pipex->pipe_fd);
	}
	else if (which_child == MIDDLE_CHILD)
	{
		fork_init(pipex);
		if (ft_lstlast(pipex->lst)->data == 0)
			middle_child(current, *pipex, pipex->pipe_fd);
	}
	else if (which_child == LAST_CHILD)
	{
		fork_init(pipex);
		if (pipex->lst->data == 0)
			last_child(current, *pipex, pipex->pipe_fd);
	}
}

void	parent(char **argv, int end, t_pipex *pipex)
{
	int	start;

	if (pipex->here_doc)
		start = 3;
	else
		start = 2;
	init_exec(pipex, argv[end]);
	runner(end - start, pipex, LAST_CHILD);
	end--;
	while (end > start)
	{
		init_exec(pipex, argv[end]);
		runner(end - start, pipex, MIDDLE_CHILD);
		end--;
	}
	init_exec(pipex, argv[end]);
	runner(end - start, pipex, FIRST_CHILD);
	close_pipe(pipex->pipe_fd, pipex->cmd_nbr);
	hold_on(pipex->lst, &(pipex->status));
	if (WEXITSTATUS(pipex->status))
		return_code(pipex);
}

void	first_child(int current, t_pipex pipex, int (*pipe_fd)[2])
{
	int	fd;

	fd = read_or_write(pipex.infile, READ, pipex);
	dup2(fd, 0);
	close(fd);
	dup2(pipe_fd[current][1], 1);
	close_pipe(pipe_fd, pipex.cmd_nbr);
	if (pipex.path != NULL)
		execve(pipex.path, pipex.cmd, pipex.env);
	ft_dprintf(2, "pipex: command not found: %s\n", pipex.cmd[0]);
	free_all(&pipex, FREE_LST);
	exit(127);
}

void	middle_child(int current, t_pipex pipex, int (*pipe_fd)[2])
{
	dup2(pipe_fd[current - 1][0], 0);
	dup2(pipe_fd[current][1], 1);
	close_pipe(pipe_fd, pipex.cmd_nbr);
	if (pipex.path != NULL)
		execve(pipex.path, pipex.cmd, pipex.env);
	ft_dprintf(2, "pipex: command not found: %s\n", pipex.cmd[0]);
	free_all(&pipex, FREE_LST);
	exit(127);
}

void	last_child(int current, t_pipex pipex, int (*pipe_fd)[2])
{
	int	fd;

	fd = read_or_write(pipex.outfile, WRITE, pipex);
	dup2(fd, 1);
	close(fd);
	dup2(pipe_fd[current - 1][0], 0);
	close_pipe(pipe_fd, pipex.cmd_nbr);
	if (pipex.path != NULL)
		execve(pipex.path, pipex.cmd, pipex.env);
	ft_dprintf(2, "pipex: command not found: %s\n", pipex.cmd[0]);
	free_all(&pipex, FREE_LST);
	exit(127);
}
