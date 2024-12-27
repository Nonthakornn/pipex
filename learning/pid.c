#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int id = fork();
	if (id == 0)
	{
		sleep(1);
	}
	printf("Parent ID: %d || Current ID: %d\n", getppid(), getpid());

	int waitnum = wait(NULL); // Number of process id you actually waiting for
	if (waitnum == -1)
		printf("No children to wait \n");
	else
		printf("%d finish execution", waitnum);

	return (0);

	/*
	Parent ID: 97711 || Current ID: 94793
	Parent ID: 94793 || Current ID: 94796
	No children to wait 
	94796 finish execution%                                                       

	*/
}
