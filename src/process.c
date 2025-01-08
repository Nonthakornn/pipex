/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:41:23 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/08 16:52:52 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_fail(char *path, char **cmd);
static void	null_fail(char **cmd);

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		if (!cmd[0])
			null_fail(cmd);
		exit(127);
	}
	path = find_path(cmd[0], envp);
	if (!path)
	{
		if (cmd[0][0] == '/')
			err_full_path(cmd[0]);
		else
			err_command(cmd[0]);
		ft_free(cmd);
		exit(127);
	}
	if (execve(path, cmd, envp) < 0)
		exec_fail(path, cmd);
}

void	child_process1(char **argv, int *pfd, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror(argv[1]);
		close(pfd[0]);
		close(pfd[1]);
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	close(pfd[0]);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[1]);
	execute(argv[2], envp);
}

void	child_process2(char **argv, int *pfd, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		write(2, "pipex: ", 8);
		write(2, argv[4], ft_strlen(argv[4]));
		write(2, ": Permission denied\n", 21);
		close(pfd[0]);
		exit(1);
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	execute(argv[3], envp);
}

static void	exec_fail(char *path, char **cmd)
{
	err_path_per(path);
	free(path);
	ft_free(cmd);
	exit(126);
}

static void	null_fail(char **cmd)
{
	err_command(cmd[0]);
	ft_free(cmd);
	exit(127);
}
