/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:31:24 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/08 16:37:53 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>

//process
void	init_process(int *pfd, int *pid, char **argv, char **envp);
void	child_process1(char **argv, int *pfd, char **envp);
void	child_process2(char **argv, int *pfd, char **envp);
void	execute(char *argv, char **envp);

//parse
int		get_env(char **envp);
char	*find_path(char *cmd, char **envp);

//utils
void	error_msg(char *msg);
void	err_full_path(char *cmd);
void	err_command(char *cmd);
void	err_path_per(char *path);
void	ft_free(char **str);
int		ft_findword(char *envp, char *word);
#endif