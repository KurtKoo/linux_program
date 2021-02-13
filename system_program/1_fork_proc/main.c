#include <unistd.h>
#include <stdio.h>
int main()
{
	//fork() returns twice
	//parent process returns the process ID
	//child process returns the 0

	//the codes before fork() run once while the codes after run twice because of the existence of the child process
	pid_t i;
	printf("before fork()\n");
	i = fork();
	printf("after fork() pid=%d\n",i);
	return 0;
}
