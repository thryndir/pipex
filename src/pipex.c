/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:48:48 by lgalloux          #+#    #+#             */
/*   Updated: 2024/04/24 23:29:57 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	read_or_write(char *file, int which)
{
	int	fd;

	if (which == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_WRONLY);
	return (fd);
}

void	child(char **argv, t_pipex pipex, char **env)
{
	int	fd;

	fd = read_or_write(argv[1], 0);
	dup2(fd, 0);
	dup2(pipex.fds[1], 1);
	close(pipex.fds[0]);
	execve(pipex.path_0, pipex.cmd_0, env);
}

void child_2(char **argv, t_pipex pipex, char **env)
{
	int	fd;

	fd = read_or_write(argv[4], 1);
	dup2(fd, 1);
	dup2(pipex.fds[0], 0);
	close(pipex.fds[1]);
	execve(pipex.path_1, pipex.cmd_1, env);
}

void	struct_init(t_pipex *pipex, char **argv, char **env)
{
	pipex->p_path = search_in_env(env);
	if (pipex->p_path == NULL)
		ft_error("problem when searching in the env", pipex, 1);
	pipex->cmd_0 = ft_split(argv[2], ' ');
	if (pipex->cmd_0 == NULL)
		ft_error("problem with the first split", pipex, 2);
	pipex->cmd_1 = ft_split(argv[3], ' ');
	if (pipex->cmd_1 == NULL)
		ft_error("problem with the second split\n", pipex, 3);
	pipex->path_0 = this_is_the_path(pipex->p_path, pipex->cmd_0);
	// if (pipex->path_0 == NULL)
	// 	ft_error("command not found 1\n", pipex, 4);
	pipex->path_1 = this_is_the_path(pipex->p_path, pipex->cmd_1);
	// if (pipex->path_1 == NULL)
	// 	ft_error("command not found 2\n", pipex, 5);
}

int	main(int argc,char **argv ,char **env)
{
	pid_t	pid_0;
	pid_t	pid_1;
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	if (pipe(pipex.fds) == -1)
		ft_error("problem with the pipe", &pipex, 0);
	struct_init(&pipex, argv, env);
	pid_0 = fork();
	if (pid_0 == -1)
		ft_error("problem with the fork", &pipex, 3);
	if (pid_0 == 0)
		child(argv, pipex, env);
	else
	{
		pid_1 = fork();
		if (pid_1 == -1)
			ft_error("problem with the fork", &pipex, 3);
		if (pid_1 == 0)
			child_2(argv, pipex, env);
	}
	free_all(&pipex, 5);
	return (0);
}
