#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

int main(int ac, char **av, char **envp)
{
	// execl("/bin/ping", "/bin/ping", "google.com", NULL);

	// execlp("ping", "ping", "google.com", NULL);

	// char *args[]  = {
	// 	"ping",
	// 	"google.com",
	// 	NULL
	// };
	// execv("/usr/bin/ping", args, NULL);


	/*
	The main difference between execv() and execve() is that 
	execve() allows you to specify the environment 
	variables for the new program 
	execv() uses the current environment
	*/

	char *args[] = {"ls", "-l", NULL};
	char *env[] = {"PATH=/bin:/usr/bin", "TERM=console", NULL};
	execve("/bin/ls", args, env);

}
