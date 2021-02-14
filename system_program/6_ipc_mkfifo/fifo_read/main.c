#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

#define MYFIFO "/tmp/myfifo"

#define MAX_BUFFER_SIZE PIPE_BUF    //PIPE_BUF is defined in the header file "limits.h"

int main(int argc,char* argv[])
{
	char buff[MAX_BUFFER_SIZE];
	int fd;
	int nread;

	if(access(MYFIFO,F_OK) == -1){   //if the fifo doesn't exist, create one with specified access code
		if((mkfifo(MYFIFO,0666) < 0) && (errno != EEXIST)){
			printf("create fifo error\n");
			exit(1);
		}
	}

	fd = open(MYFIFO,O_RDONLY);

	if(fd == -1){
		printf("open fifo error\n");
		exit(1);
	}

	while(1){
		memset(buff,0,sizeof(buff));
		
		if((nread = read(fd,buff,MAX_BUFFER_SIZE)) > 0 ){
			printf("Read %s from fifo\n",buff);
		}
	}

	close(fd);
	exit(0);
}
