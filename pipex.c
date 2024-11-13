/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:33:19 by nchencha          #+#    #+#             */
/*   Updated: 2024/11/14 02:26:10 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		ft_putstr_fd("OK",1);

	}
	else
		ft_error("Error argments is not 5\n");
	return (0);
}