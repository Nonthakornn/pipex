#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

/*
2 processes
- Child generate random numbers and send them to the parent
- Parent sum all the number and print the result;
*/


int main()
{
	int fd[2];
	if (pipe(fd) == -1) { return 2; }

	int pid = fork();
	if (pid == -1) { return 1; }

	if (pid == 0)
	{
		close(fd[0]);
		int n;
		int i;
		int arr[10];

		srand(time(NULL));
		n = rand() % 10 + 1; // 1-10
		printf("Generate Number: ");
		for (i = 0; i < n; i++)
		{
			arr[i] = rand() % 11;
			printf("%d ", arr[i]);
		}

		if (write(fd[1], &n, sizeof(int)) < 0) { return 4; }
		printf("\nSend n: %d\n", n);
		if (write(fd[1], arr, sizeof(int) * n) < 0) { return 3; }
		printf("Sent Array");
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int arr[10];
		int n;
		int i;
		int sum = 0;

		if (read(fd[0], &n, sizeof(int)) < 0) { return 5; }
		printf("\nReceive n: %d\n", n);
		if (read(fd[0], arr, sizeof(int) * n) < 0) { return 6; }
		printf("Receive arr\n");
		close(fd[0]);

		for (i = 0; i < n; i++)
			sum += arr[i];
		printf("Result: %d\n", sum);
		wait(NULL);
	}

}