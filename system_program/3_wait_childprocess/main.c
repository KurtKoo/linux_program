#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
	pid_t result;
	int status;
	result = fork();

	if(result == -1){

	}

	else if(result == 0){
		printf("child\n");
		exit(0);   //print "child"   however using _exit(0) will not because _exit function ignores the internal buffer
	}

	else{
		wait(&status);  //wait for child process to exit
		if(WIFEXITED(status) == 1 ){    //the macro returns 1 if the child process exits normally
			printf("child process exit nomally (status:%d)\n",status);
			return 0;
		}
	}
}
