#include<stdio.h>
#include<unistd.h>
int main(){
	
	fork();
	fork();
	printf("Process id is:- %d\n",getpid());
}
