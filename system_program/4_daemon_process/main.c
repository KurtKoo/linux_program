#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAXFILE 3

int main()
{
	pid_t pid;
	int fd,len,i,num;
 	char *buf = "the daemon is running\n";

	len = strlen(buf)+1;

	pid = fork();
	if(pid < 0){
		printf("fork error\n");
		exit(1);
	}

	if(pid > 0){
		exit(0);
	}
	
	setsid();  //creat a new session

	chdir("/"); //change the working directory

	umask(0); //set the mask

	for(i = 0;i < MAXFILE;i++){   //close the file descriptor opened by default (0,1,2)
		close(i);
	}

	while(1){   //what the daemon process does
		fd = open("/var/log/daemon.log",O_CREAT|O_WRONLY|O_APPEND,0666);
		write(fd,buf,len);
		close(fd);
		sleep(5);
	}
	

	return 0;
}
