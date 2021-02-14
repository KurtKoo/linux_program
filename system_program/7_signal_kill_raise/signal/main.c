#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>



void signal_handler(int sig)
{
	printf("this signal number is %d\n",sig);

	if(sig == SIGINT){
		printf("get the SIGINT\n");
		signal(SIGINT,SIG_DFL);
		printf("SIGINT has been restored to the default operation\n");
	}
}

int main()
{
	printf("alarm test function\n");

	signal(SIGINT,signal_handler);   //set the callback function once the process receives the signal "SIGINT"

	while(1){
		printf("press ctrl+c to trigger the signal \"SIGINT\"\n");
		sleep(1);
	}
	
	exit(0);
}
