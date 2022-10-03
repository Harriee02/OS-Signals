/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int check = 0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
	check = 1;
	
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second

  while(1){//busy wait for signal to be delivered
		if (check == 1){
			printf("Turing was right!\n");
			check = 0;
			alarm(1);}
	};
  return 0; //never reached
}