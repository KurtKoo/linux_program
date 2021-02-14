#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>


//command "kill -l" can show all of the signals that the system supports
//among those 64 signals ,(0-31)signals will only be responded once if those were triggered multiple times within a short period
//by doing as below the system will respond as many times as those signals(0-31,SIGINT used as an example) are triggered
void signal_func()
{ 
	sigset_t set;
	sigset_t set_old;

	sigemptyset(&set);  //every bit in signal set is set to 0

	sigaddset(&set,SIGINT);   //SIGINT bit set to 1

	//certain bits in the blocked set of signals will be removed according to the "set" in which the bit has been set to 1 
	//and the original set will be preserved in the "set_old" 
	sigprocmask(SIG_UNBLOCK,&set,&set_old);   //what the first parameter of this function means can be referred to documents provided by command "man" 
											  //you can set the cursor on the function and press shift+k to easily do the job here

	printf("hello\n");
	sleep(1);
	printf("world\n");
}

int main()
{
	signal(SIGINT,signal_func);
	while(1);
	return 0;
}
