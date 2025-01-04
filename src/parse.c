/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:34:54 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/05 03:22:40 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_findword(envp[i], "PATH="))
			return (i);
		i++;
	}
	return (-1);
}

static char	*check_absolute_path(char *cmd)
{
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}

static char	*try_paths(char **env_vec, char *cmd)
{
	int		i;
	char	*path;
	char	*full_path;

	i = 0;
	while (env_vec[i])
	{
		path = ft_strjoin(env_vec[i], "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**env_vec;
	char	*result;
	int		i;

	result = check_absolute_path(cmd);
	if (result)
		return (result);
	i = get_env(envp);
	if (i == -1)
		ft_error("error finding env", EXIT_FAILURE);
	env_vec = ft_split(envp[i] + 5, ':');
	if (!env_vec)
		ft_error("Error spliting path", EXIT_FAILURE);
	result = try_paths(env_vec, cmd);
	ft_free(env_vec);
	return (result);
}
