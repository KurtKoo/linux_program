#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int ret;

	if((pid = fork()) < 0){
		printf("fork error\n");
		exit(1);
	}

	if(pid == 0){ //child process
		printf("child process waiting for the SIGSTOP signal\n");
		
		raise(SIGSTOP);    //child process calls to stop its own
		printf("child process never runs to here\n");
		exit(0);
	}

	else if(pid > 0){
		sleep(5);

		if((ret = kill(pid,SIGKILL)) == 0){    //parent process calls to kill child process
			printf("parent kill %d process\n",pid);
		}

		wait(NULL);

		printf("parent process exit\n");

		exit(0);
	}
}
