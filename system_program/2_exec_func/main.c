#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t result;
	char *arg[]={"ls","-l",NULL};
	char *arg1[]={"env",NULL};
	char *env[]={"PATH=/tmp","name=exec_fun",NULL};
	result = fork();
	
	if(result > 0){
	//	execl("/bin/ls","ls","-l",NULL);  
//		execlp("ls","ls","-l",NULL);  
		//execv("/bin/ls",arg);
		execve("/usr/bin/env",arg1,env);  
		printf("error\n");   //program comes to an end after running the exec*() so print error if it runs here 
		return -1;
	}

	if(result == 0){
		return 0;
	}
}
