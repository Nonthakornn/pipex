/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:41:23 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/05 00:00:10 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, int *pfd, char **envp)
{
	int infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		ft_error("No such file or directory\n");
	dup2(infile, STDIN_FILENO);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	close(infile);
	execute(argv[2], envp);
}

void	parent_process(char **argv, int *pfd, char **envp)
{
	int	outfile;
	
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		exit(1); //Fix this later
		
	dup2(pfd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	close(outfile);
	execute(argv[3], envp);
	// execve("/usr/bin/ls", str, envp);
	perror("execlp error");
}

/*
First Part (Child Process):

Fork creates child process
Child opens file
Redirects standard input to read from file 
Redirects standard output to write to pipe
Executes cat command which reads demo.c and sends to pipe

Second Part (Parent Process):
Parent waits for child (cmd) to finish
Opens out.txt file
Redirects standard input to read from pipe (where cmd wrote)
Redirects standard output to write to out.txt
Executes grep command to search for "main"
*/


