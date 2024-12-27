
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();

	if (pid == -1) { return 1; }

	if (pid == 0)
	{
		int err = execlp("pings", "ping", "-c", "3", "google.com", NULL);
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
