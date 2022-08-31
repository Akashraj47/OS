#include<stdio.h>
#include<unistd.h>
int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int p;
	int sum_odd = 0;
	int sum_even = 0;
	p = fork();
	if(p == 0){
		for(int i = 0;i<10;i++){
			if(arr[i] & 1){
				sum_odd += arr[i];
			}
		}
		printf("The sum of odds are :- %d\n",sum_odd);
	}
	else{
		for(int i = 0;i<10;i++){
			if((arr[i] & 1) == 0){
				sum_even += arr[i];
			}
		}
		printf("The sum of even are :- %d\n",sum_even);
	}
	return 0;
}
