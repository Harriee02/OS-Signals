/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int check = 0;
int noOfSecs = 0;
int noOfAlarms = 0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
	check = 1;
	
}

void cancelHandler(int signum)
{ //signal handler
  printf("\n%d alarm(s) ran for %d second(s) \n",noOfAlarms, noOfSecs);
	exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
	signal(SIGINT,cancelHandler);
  alarm(1); //Schedule a SIGALRM for 1 second

  while(1){//busy wait for signal to be delivered
		if (check == 1){
			printf("Turing was right!\n");
			check = 0;
			alarm(1);
			noOfAlarms ++;
			noOfSecs++;}
	};
  return 0; //never reached

}
