/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 03:36:41 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/03 05:29:35 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(1);
}

/*
void ft_exit(int err_num)
{
	if (err_num == 2)
		exit(127);
	else if (err_num == 13)
		exit(126);
	else
		exit(1);
}
*/

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
*/