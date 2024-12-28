#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int pid1 = fork();
	if (pid1 == -1)
		return 1;
	
	if (pid1 == 0)
	{
		sleep(4);
		printf("Finish execution (%d)\n", getpid());
		return 0;
	}

	int pid2 = fork();
	if (pid2 == -1)
		return 2;
	

	if (pid2 == 0)
	{
		sleep(1);
		printf("Finish execution (%d)\n", getpid());
		return 0;
	}

	int p1_wait = waitpid(pid1, NULL, WNOHANG);
	printf("p1_wait:%d\n", p1_wait);
	int p2_wait = waitpid(pid2,NULL, WNOHANG);
	printf("p1_wait:%d\n", p2_wait);
	return (0);
}