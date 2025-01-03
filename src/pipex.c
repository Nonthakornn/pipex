/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:33:19 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/04 02:36:22 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pfd[2];
	int	pid;

	if (argc < 5)
		ft_error("Error: Arguments is not 5\n");
	if (pipe(pfd) < 0)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
		child_process(argv, pfd, envp);
	parent_process(argv, pfd, envp);
	waitpid(pid, NULL, 0);
	return (0);
}

/*
Testing:

./pipex text.txt "grep He" "wc -w" out
./pipex text.txt "cat" "grep Hello" out
./pipex text.txt "sleep 1" "sleep 10" outfile (Should sleep 10 second);

< text.txt grep Hello | wc -w > out
./pipex text.txt "grep Hello" "wc -w" out

#Error Case
./pipex ./src/pipex.c "caet" "grep -i int" out
caet: command not found

< text.txt grepx Hello | wc -w > out
grepx: command not found

# sleep Test
1. text based commands execute correctly,
2. infile "sleep 1" "wc -w" outfile results in 1 second blink
3. infile "wc -w" "sleep 1" outfile results in 1 second blink
4. infile "sleep 1" "sleep 10" outfile results in 10 seconds blink
5. infile "sleep 10" "sleep 1" outfile results in 1 second blink

Note:
< text.txt grep Hello | wc -l > out 
grep Hello < text.txt | wc -l > out
child process terminates but its parent process
hasn't yet collected its exit status
*/