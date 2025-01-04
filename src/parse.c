/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:34:54 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/04 21:35:48by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_env(char **envp)
{
	int i;
	
	i = 0;
	while (envp[i])
	{
		if (ft_findword(envp[i], "PATH="))
			return (i);
		i++;
	}
	return (-1);
}

char *find_path(char *cmd, char **envp)
{
	int	i;
	char **env_vec;
	char *path;
	char *full_path;

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	env_vec = NULL;	
	i = get_env(envp);
	if (i != -1)
	{
		dprintf(2,"PATH value: %s\n", envp[i]);
		env_vec = ft_split(envp[i] + 5, ':');
		if (!env_vec)
		{
			ft_free(env_vec);
			ft_error("Error spliting path");
		}
	}
	else
		dprintf(2,"Error");
	i = 0;
	while (env_vec[i])
	{
		path = ft_strjoin(env_vec[i], "/");
		full_path = ft_strjoin(path, cmd);
		// dprintf(2, "Full path: %s\n", full_path);
		free(path);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		i++;
	}
	return NULL;

}

