/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:31:24 by nchencha          #+#    #+#             */
/*   Updated: 2024/12/29 13:39:01 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_process
{
	pid_t	pid[2];
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	char	**cmd_1;
	char	**cmd_2;
	char	*paths;

}				t_process;

//error
void	ft_error(char *msg);
void	ft_exit(int err_num);

//init_process
void	init_process(t_process **process, char **argv, char **envp);


#endif