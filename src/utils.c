/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:14:25 by lgalloux          #+#    #+#             */
/*   Updated: 2024/05/05 00:58:55 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

char	*this_is_the_path(char **p_path, char **cmd)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	if (access(cmd[0], X_OK) == 0)
		return (ft_strdup(cmd[0]));
	while (p_path[i])
	{
		tmp = ft_strjoin("/", cmd[0]);
		if (tmp == NULL)
			return (NULL);
		path = ft_strjoin(p_path[i], tmp);
		if (path == NULL)
			return (NULL);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		else
			free(path);
		i++;
	}
	return (NULL);
}

void	double_array_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**search_in_env(char **env)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(env[i], ':');
	if (path == NULL)
		return (NULL);
	tmp = ft_strtrim(path[0], "PATH=");
	if (tmp == NULL)
		return (NULL);
	free(path[0]);
	path[0] = tmp;
	return (path);
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

void	ft_error(char *message, t_pipex *pipex, int which)
{
	if (which >= 1)
		ft_putstr_fd(message, 2);
	if (which < 0)
	{
		free_all(pipex, which *= -1);
		exit(EXIT_FAILURE);
	}
	else
	{
		free_all(pipex, which);
		exit(EXIT_SUCCESS);
	}
}