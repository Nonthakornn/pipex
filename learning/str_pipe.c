#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main()
{
	int fd[2];

	if (pipe(fd) == -1) { return 1; }
	int pid = fork();
	if (pid < 0) { return 2; }

	if (pid == 0)
	{
		char str[100];
		int n = strlen(str) + 1;
		write(fd[1], &n, sizeof(int));

		printf("Input String: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = 0; //At the end of that string '\n' is left so we need to add NULL;
		if (write(fd[1], str, strlen(str) + 1) < 0) { return 3; }
	}
	else
	{
		close(fd[1]);

		char str[200];
		int n;
		if (read(fd[0], &n, sizeof(int)) < 0) { return 4; }
		if (read(fd[0], str, sizeof(char) * n) < 0) { return 5; }
		printf("Received %s", str);
		close(fd[0]);
		wait(NULL);
	}
}