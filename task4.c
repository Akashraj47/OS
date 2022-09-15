//orphan process
#include<stdio.h>
#include<unistd.h>
int main()
{
  printf("Akash Raj\nID - 20011345\n");
  int x = fork();
  if(x == 0) //child process
  {
    sleep(5);
    printf("Child process id is %d\n",getpid());
    printf("Parent Process id is %d\n",getppid());
  }
  else  //parent process
  {
    printf("Parent process id is %d\n",getpid());
  }
}
