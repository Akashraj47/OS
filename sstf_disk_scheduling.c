#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main(){
	int n;
	printf("Enter mumber of sequence:- ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter values in sequence:- ");
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int visited[n];
	int seek_time = 0;
	int val = 0;
	int temp = -1;
	int ind = -1;
	printf("Enter value of head:- ");
	scanf("%d",&val);
	for(int i = 0;i<n;i++){
		visited[i] = -1;
	}
	printf("The Sequence is:- ");
	printf("%d ",val);
	int completed = 0;
	while(completed != n){
		int sm = INT_MAX;
		for(int i = 0;i<n;i++){
			if(visited[i] != 0){
				temp = abs(val - arr[i]);
				if(temp < sm){
					sm = temp;
					ind = i;
				}
			}
		}
		completed++;
		visited[ind] = 0;
		seek_time += sm; 
		val = arr[ind];
		printf("%d ",arr[ind]);
	}
	printf("\nTotal Seek Time = %d\n",seek_time);
	return 0;
}