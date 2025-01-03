/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:36:33 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/04 02:42:00 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void execute(int *argc, char **envp)
{

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