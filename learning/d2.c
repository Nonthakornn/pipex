#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
	int fd[2];
	pipe(fd);

	int pid = fork();

	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		//execlp() replaces the current program with the new program (ls). 
		//Any code after execlp() never runs
		execlp("ls", "ls", NULL);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		execlp("grep", "grep", "du", NULL);
	}
	close(fd[0]);
	close(fd[1]);
}

/*
// Without dup2:
ls → prints to screen
grep → reads from keyboard

// With dup2:
ls → writes to pipe
grep → reads from pipe
*/