#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd;
	fd = open("./a.txt",O_RDONLY|O_CREAT,0666);
	if(fd < 0){
		printf("file open error\n");
	}
	printf("fd:%d\r\n",fd);
	close(fd);
	return 0;
}
