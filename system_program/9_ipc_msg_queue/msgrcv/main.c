#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 512

struct message{
	long msg_type;
	char msg_text[BUFFER_SIZE];
};

int main()
{
	int qid;
	key_t key;
	struct message msg;

	if((key = ftok("/tmp",11)) == -1){  //create standard key
		printf("ftok error\n");
		exit(1);
	}

	if((qid = msgget(key,IPC_CREAT|0666)) == -1){  //create message queue
		printf("msgget error\n");
		exit(1);
	}

	printf("open queue %d\n",qid);

	do{
		
		memset(msg.msg_text,0,BUFFER_SIZE);     
		if(msgrcv(qid,(void*)&msg,BUFFER_SIZE,0,0) < 0){       //get message contents
			printf("msgrcv error\n");
			exit(1);
		}

		printf("message from process %ld:%s\n",msg.msg_type,msg.msg_text);
	}while(strncmp(msg.msg_text,"quit",4));

	if((msgctl(qid,IPC_RMID,NULL)) < 0){        //remove the message queue created from the system kernel
		printf("msgctl error\n");
		exit(1);
	}

	exit(0);
}
