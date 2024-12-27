#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	printf("PID of exv1.c = %d\n", getpid());
	char *args[] = {"./exv2", "Hello", "Wordld", "Zzz", NULL};
	execv(args[0], args);
	perror("execv");
	printf("Back to exv1.c");
	return (0);

	// cc exv1.c -o exv1 | cc exv2.c -o exv2 | ./exv1

	/*
	exec() will replace the entire procress
	PID of exv1.c = 52872
	At exv2.c
	PID of exv2.c = 52872
	*/

}