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
	int nwrite;

	if(argc <= 1){
		printf("usage:./a.out your_string_to_write\n");
		exit(1);
	}

	sscanf(argv[1],"%s",buff);  //fill up the "buff" with the "argv[1]" 

	fd = open(MYFIFO,O_WRONLY);

	if(fd == -1){
		printf("open fifo error\n");
		exit(1);
	}

	if((nwrite = write(fd,buff,MAX_BUFFER_SIZE)) > 0 ){
			printf("Write %s to fifo\n",buff);
	}
	

	close(fd);
	exit(0);
}
