/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:41:23 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/06 20:21:05 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_process(int *pfd, int *pid, char **argv, char **envp)
{
	if (pipe(pfd) < 0)
		error_msg("pipe fail");
	pid[0] = fork();
	if (pid[0] < 0)
		error_msg("fork fail");
	if (pid[0] == 0)
		child_process1(argv, pfd, envp);
	else
		close(pfd[1]);
	pid[1] = fork();
	if (pid[1] == 0)
		child_process2(argv, pfd, envp);
	else
		close(pfd[0]);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		exit(1);
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
	{
		write(2, "pipex: ", 8);
		write(2, path, ft_strlen(path));
		write(2, ": Permission denied\n", 21);
		free(path);
		ft_free(cmd);
		exit(126);
	}
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
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	execute(argv[3], envp);
}
