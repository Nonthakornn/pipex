#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>


int main()
{
	int arr[] = {1, 2, 3, 4 , 1, 2};
	int arrSize = sizeof(arr) / sizeof(int); //6
	int fd[2];
	int start;
	int end;

	if (pipe(fd) == -1)
		return 1;
	int id = fork();
	if (id == -1)
		return 2;
	if (id == 0)
	{
		// close(fd[0]);
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}

	int sum = 0;
	int i;
	for (i = start; i < end; i++)
		sum+= arr[i];
	printf("Partial Sum: %d\n", sum);

	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(int)) == -1)
			return 3;
		close(fd[1]);
	}
	else
	{
		int sumChild;
		close(fd[1]);
		if (read(fd[0], &sumChild, sizeof(int)) == -1)
			return 4;
		close(fd[0]);

		int total = sum + sumChild;
		printf("Total Sum: %d", total);
		wait(NULL);
	}

}
