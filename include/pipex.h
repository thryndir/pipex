/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:38:31 by lgalloux          #+#    #+#             */
/*   Updated: 2024/04/24 22:02:59 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <errno.h>

typedef struct s_pipex
{
	char	**p_path;
	char	**cmd_0;
	char	**cmd_1;
	char	*path_0;
	char	*path_1;
	int		fds[2];
} t_pipex;

char	**search_in_env(char **env);
void	child(char **argv, t_pipex pipex, char **env);
void	child_2(char **argv, t_pipex pipex, char **env);
void	ft_error(char *message, t_pipex *pipex, int	which);
char	*this_is_the_path(char **p_path, char **cmd);
void	free_all(t_pipex *pipex, int which);

#endif