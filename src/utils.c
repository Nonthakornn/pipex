/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 03:36:41 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/08 16:38:28 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit (1);
}

void	err_full_path(char *cmd)
{
	write(2, "pipex: ", 8);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": No such file or directory\n", 29);
}

void	err_command(char *cmd)
{
	write(2, "Command '", 9);
	write(2, cmd, ft_strlen(cmd));
	write(2, "' not found\n", 12);
}

void	err_path_per(char *path)
{
	write(2, "pipex: ", 8);
	write(2, path, ft_strlen(path));
	write(2, ": Permission denied\n", 21);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*
**File Descriptor
STDIN_FILENO	0
STDOUT_FILENO	1
STDERR_FILENO	2

**Error number
EXIT_FAILURE	1
**Error number
General error				EXIT_FAILURE(1) exit(1)

Bad file descriptor			EBADF(9) exit(1)
No such file or directory	ENOENT(2); exit(1)

Command not found    		ENOENT(2) exit(127)
permission denile    EACCESS(13)    exit(126)
fork and pipe fail    exit(127)

**error message
`/usr/bin/lx` - bash: /usr/bin/lx: No such file or directory
`lx` -  `lx` : command not found

`cat nofile.txt` - <command>: <filename.txt>: No such file of directory
`/use/bin/cat nofile.txt` - <command>: <filename.txt>: No such file of directory
*/