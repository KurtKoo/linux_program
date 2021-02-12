#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd = open("file.txt",O_RDWR|O_CREAT,0666);
	write(fd,"123",3);
	lseek(fd,100,SEEK_CUR);
	write(fd,"abc",3);
	sync();   // contents written into disk right now
	close(fd);
	return 0;
}
