#include<stdio.h>
#include<sys/types.h> 

void main(){
	pid_t r=fork();
	switch(r){
		case -1:
			printf("ERROR!!\n");
			exit(1);
		
		case 0:
			printf("My PID:\t\t%d\nMY PPID:\t%d\n",getpid(),getppid());
			break;
		default:
			wait(0);
			printf("My PID:\t\t%d\nMy Child's PID:\t%d\n",getpid(),r);
			break;
	}
	return;
}
