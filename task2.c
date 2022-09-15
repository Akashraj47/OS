#include<stdio.h> #include<unistd.h> int main()
{

int n;
printf("Enter the size of the array\n"); scanf("%d",&n);
int arr[n];
printf("Enter the elements of the array\n"); for(int i=0;i<n;i++)
{

scanf("%d",&arr[i]);
}

int x = fork();
int even=0,odd=0; if(x > 0)
{

for(int i = 0;i<n;i++)
 
{
if(arr[i]%2 == 0)
{

even = even+arr[i];
}
}

printf("Child process id is:%d\n",getpid()); printf("Sum of even number is:%d\n",even);
}

else
{

for(int i=0;i<n;i++)
{
if(arr[i]%2 != 0)
{

odd = odd+arr[i];
}
}

printf("Parent process id is:%d\n",getpid()); printf("Sum of odd numbers is :%d\n",odd);
}

return 0;
}
