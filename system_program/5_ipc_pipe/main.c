#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_LEN 256

int main()
{
	pid_t pid;
	int pipe_fd[2];
	int status;
	char buf[MAX_DATA_LEN];
	const char data[]="pipe Test program";
	int real_read,real_write;

	memset((void*)buf,0,sizeof(buf));

	if(pipe(pipe_fd) < 0){ //create the pipe
		printf("create pipe error\n");
		return -1;
	}

	if((pid = fork()) == 0) { //child process
		close(pipe_fd[1]);  //close the pipe for writing
		if((real_read = read(pipe_fd[0],buf,MAX_DATA_LEN)) > 0){
			printf("%d bytes read from pipe is %s\n",real_read,buf);
		}

		close(pipe_fd[0]);

		exit(0);
	}
	
	else if(pid > 0){
		close(pipe_fd[0]); //close the pipe for reading
		
		if((real_write = write(pipe_fd[1],data,strlen(data))) > 0){
			printf("Parent pipe writes %d bytes: %s\n",real_write,data);
		}

		close(pipe_fd[1]);

		wait(&status);  //wait for the child process to exit

		exit(0);
	}	

	return 0;
}
