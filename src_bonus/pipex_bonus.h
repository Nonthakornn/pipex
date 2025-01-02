/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:02:54 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/02 23:45:51 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>

typedef int t_pipes[2];
typedef struct s_process
{
	t_pipes	*pipe_fd;
	size_t	num_pipes;
	size_t	num_fork;
	int		*forks;
	int		infile;
	int		outfile;
	char	**cmd_1;
	char	**cmd_2;
	char	*paths;
}				t_process;

//error
void	ft_error(char *msg, int err_num);
void	ft_exit(int err_num);

//init
void	init_pipes(t_process *proc, int argc);
void	start_fork(t_process *proc, int argc);
bool	is_parent(int *forks, int num_fork);

#endif