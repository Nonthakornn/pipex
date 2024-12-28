#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
	int pid = fork();

	if (pid == -1) { return 1; }

	if (pid == 0)
	{
		int file1 = open("pingResult.txt", O_WRONLY | O_CREAT, 0777);
		if (file1 == -1)
			return 2;

		printf("fd of pingResult(file1): %d\n", file1);
		// int file2 = dup2(file1, 1);
		// printf("fd of duplicate(file2): %d\n", file2);
		dup2(file1, 1);
		close(file1);
		
		int err = execlp("ping", "ping", "-c", "1", "google.com", NULL);
		if (err == -1)
		{
			printf("Count not find a program to execute!\n");
			return (2);
		}
	}
	else
	{
		int wstatus;
		
		wait(&wstatus);
		if (WIFEXITED(wstatus));
		{
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("Success\n");
			else
				printf("Fail with status code %d\n", statusCode);
		}
	}
	return 0;
}
