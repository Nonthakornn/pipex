/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:31:24 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/05 02:51:59 by nchencha         ###   ########.fr       */
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

void	ft_error(char *msg, int err_num);
void	ft_exit(int err_num);
void	ft_free(char **str);
int		ft_findword(char *envp, char *word);
void	child_process(char **argv, int *pfd, char **envp);
void	parent_process(char **argv, int *pfd, char **envp);
void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
int		get_env(char **envp);
#endif