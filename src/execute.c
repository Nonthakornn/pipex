/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:36:33 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/04 18:04:52y nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void execute(char *argv, char **envp)
{
	char **cmd;
	char *path;
	
	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_free(cmd);
	// for (int j = 0; j < 2; j++)
	// 	dprintf(2, "%s ",cmd[j]);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		write(2, "Command '", 9);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, "' not found\n", 12);
		ft_free(cmd);
		exit(127);
	}
	dprintf(2,"PATH that can access: %s\n", path);
	if (execve(path, cmd, envp) < 0)
		perror("execve");

	ft_free(cmd);

}


/*

int execve(const char *fullpath, char *argv[], char *envp[]);
// Must be full path to the executable
char *cmd = "/usr/bin/ls";// This works
char *cmd = "ls"; // This won't work - needs full path

char *argVec[] = {
    "program_name",  // argv[0] - conventional name
    "arg1",
    "arg2",
    NULL
};
// Empty environment
char *envVec[] = {NULL};  
char *envVec[] = {
    "PATH=/usr/bin",
    "HOME=/home/user",
    NULL
};
*/