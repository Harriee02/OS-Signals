/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;


int check = 0;
int noOfAlarms = 0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
	check = 1;
	noOfAlarms ++;
	
}
\
void cancelHandler(int signum)
{ //signal handler
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("\n%d alarm(s) ran for %f second(s) \n",noOfAlarms, cpu_time_used);
	exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
	signal(SIGINT,cancelHandler);
	start = clock();
  alarm(1); //Schedule a SIGALRM for 1 second

  while(1){//busy wait for signal to be delivered
		if (check == 1){
			printf("Turing was right!\n");
			check = 0;
			alarm(1);}
	};
  return 0; //never reached

}
