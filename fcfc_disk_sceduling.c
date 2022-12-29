#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	printf("Enter no of sequence- ");
	scanf("%d",&n);
	int arr[n] ;
	printf("Enter values:- ");
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int head;
	printf("Enter initial value:- ");
	scanf("%d",&head);
	int seek_time = abs(head - arr[0]);
	for(int i = 0;i<n;i++){
		printf("%d ",arr[i]);
		if(i > 0){
			seek_time += abs(arr[i] - arr[i-1]);
		}
	}
	printf("\nTotal seek time = %d\n",seek_time);
	return 0;
}

