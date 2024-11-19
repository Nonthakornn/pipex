/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nonthakornchencharatmatha <nonthakornch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:33:19 by nchencha          #+#    #+#             */
/*   Updated: 2024/11/19 23:47:20 by nonthakornc      ###   ########.fr       */
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
		ft_error("Error: Arguments is not 5\n");
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
1. text based commands execute correctly, for example infile "grep Now" "wc -w" outfile  infile "grep Now" "grep Now" outfile
2. infile "sleep 1" "wc -w" outfile results in 1 second blink
3. infile "wc -w" "sleep 1" outfile results in 1 second blink
4. infile "sleep 1" "sleep 10" outfile results in 10 seconds blink
5. infile "sleep 10" "sleep 1" outfile results in 1 second blink

Note:
< text.txt grep Hello | wc -l > out 
grep Hello < text.txt | wc -l > out

*/