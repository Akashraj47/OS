//Zombie process
#include<stdio.h>
#include<unistd.h>
int main()
{
   printf("Akash Raj\nID - 20011345\n");
   int x = fork();
   if(x==0) //child process
   {
     printf("Process id of child is : %d\n",getpid());
     printf("Prcoess id of parent is :%d\n",getppid());
   }
   else // Parent Process
   {
      sleep(5);
      printf("Process id of parent is : %d\n",getpid());
   }
}
