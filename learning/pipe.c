#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int ac, char **av)
{
	int fd[2];
	//fd[0] - read;
	//fd[1] - write;
	pipe(fd);
	if (pipe(fd) == -1)
		return 1;

	int id = fork();
	if (id == -1)
		return 4;
	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], av[1], 1) == -1)
			return 2;
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		char y;
		if (read(fd[0], &y, 1) == -1)
			return 3;
		close(fd[0]);
		printf("Got from child process: %c", y);
	}
	return (0);
}