/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:48:48 by lgalloux          #+#    #+#             */
/*   Updated: 2024/05/11 21:41:21 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	read_or_write(char *file, int which, t_pipex pipex)
{
	int	fd;

	fd = -1;
	if (which == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ft_error("problem when opening the file\n", &pipex, 7, 1);
	return (fd);
}

void	parent(char **argv, char **env, t_pipex pipex)
{
	pid_t	pid_0;
	pid_t	pid_1;

	if (pipe(pipex.fds) == -1)
		ft_error("problem with the pipe", &pipex, 1, 1);
	pid_0 = fork();
	if (pid_0 == -1)
		ft_error("problem with the fork", &pipex, 4, 1);
	pid_1 = -1;
	if (pid_0 == 0)
		child(argv, pipex, env);
	else
	{
		pid_1 = fork();
		if (pid_1 == -1)
			ft_error("problem with the fork", &pipex, 4, 1);
		if (pid_1 == 0)
			child_2(argv, pipex, env);
	}
	close(pipex.fds[0]);
	close(pipex.fds[1]);
	waitpid(pid_0, &pipex.status_0, 0);
	waitpid(pid_1, &pipex.status_1, 0);
	if (WIFEXITED(pipex.status_0) || WIFEXITED(pipex.status_1))
		return_code(&pipex);
}

void	child(char **argv, t_pipex pipex, char **env)
{
	pipex.fd_1 = read_or_write(argv[1], 0, pipex);
	dup2(pipex.fd_1, 0);
	close(pipex.fd_1);
	dup2(pipex.fds[1], 1);
	close(pipex.fds[0]);
	close(pipex.fds[1]);
	if (pipex.path_0 != NULL)
		execve(pipex.path_0, pipex.cmd_0, env);
	free_all(&pipex, 6);
	exit(127);
}

void	child_2(char **argv, t_pipex pipex, char **env)
{
	pipex.fd_2 = read_or_write(argv[4], 1, pipex);
	dup2(pipex.fd_2, 1);
	close(pipex.fd_2);
	dup2(pipex.fds[0], 0);
	close(pipex.fds[1]);
	close(pipex.fds[0]);
	if (pipex.path_1 != NULL)
		execve(pipex.path_1, pipex.cmd_1, env);
	free_all(&pipex, 6);
	exit(127);
}

void	struct_init(t_pipex *pipex, char **argv, char **env)
{
	pipex->p_path = search_in_env(env);
	if (pipex->p_path == NULL)
		ft_error("problem when searching in the env", pipex, 2, 1);
	pipex->cmd_0 = ft_split(argv[2], ' ');
	if (pipex->cmd_0 == NULL)
		ft_error("problem with the first split", pipex, 3, 1);
	pipex->cmd_1 = ft_split(argv[3], ' ');
	if (pipex->cmd_1 == NULL)
		ft_error("problem with the second split\n", pipex, 4, 1);
	pipex->path_0 = this_is_the_path(pipex->p_path, pipex->cmd_0);
	pipex->path_1 = this_is_the_path(pipex->p_path, pipex->cmd_1);
}
