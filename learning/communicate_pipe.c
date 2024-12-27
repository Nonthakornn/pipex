#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int p1[2]; //Child -> parent
	int p2[2]; //Parent ->child
	if (pipe(p1) == -1) {return 1;}
	if (pipe(p2) == -1) {return 1;}

	int pid = fork();
	if (pid == -1) {return 2;}

	if (pid == 0)
	{
		close(p1[0]);
		close(p2[1]);
		int x;

		if (read(p2[0], &x, sizeof(int)) == -1 ) { return 3;}
		printf("Received %d\n", x);
		x = x * 4;
		if (write(p1[1], &x, sizeof(int)) == -1) { return 4;}
		printf("Write %d\n", x);

		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		close(p1[1]);
		close(p2[0]);

		srand(time(NULL));
		int y = rand() % 10;

		if (write(p2[1], &y, sizeof(int)) == -1) { return 5;}
		printf("Wrote %d\n", y);
		if (read(p1[0], &y, sizeof(int)) == -1) { return 6; }
		printf("Result %d\n", y);

		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}

}

