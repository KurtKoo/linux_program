#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc,char** argv)
{
	int fd1,fd2;
	char buf[512];
	int read_size;
	
	if (argc != 3){
		printf("param error\n");
		return -1;
	}

	fd1 = open(argv[1],O_RDONLY);
	fd2 = open(argv[2],O_WRONLY|O_CREAT,0666);

	if (fd1 < 0 || fd2 < 0){
		printf("open file error\n");
		return -1;
	}		

	while (1){
		read_size = read(fd1,buf,sizeof(buf));
		if (read_size == 0) break;

		write(fd2,buf,read_size);
	}

	close(fd1);
	close(fd2);

	return 0;
}
