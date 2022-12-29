// SCAN

#include<stdio.h>
int main(){
    int n;
    printf("Enter size of request:- ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter requests:- ");
    for(int i = 0;i<n;i++) scanf("%d",&arr[i]);
    int head = 0;
    printf("Enter position of head:- ");
    scanf("%d",&head);
    
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int t_seek = 0;
    int choice = 0;
    printf("Press 1 for left movement and 2 for right movement:- ");
    scanf("%d",&choice);
    if(choice == 1){
        for(int i = n-1;i>=0;i--){
            if(arr[i] <= head){
                printf("%d ",arr[i]);
            }
        }
        printf("0 ");
        for(int i = 0;i<n;i++){
            if(arr[i] > head){
                printf("%d ",arr[i]);
            }
        }
        t_seek += (head);
        t_seek += (arr[n-1]);
    }
    else if(choice == 2){
        for(int i = 0;i<n;i++){
            if(arr[i] >= head){
                printf("%d ",arr[i]);
            }
        }
        printf("199 ");
        for(int i = n-1;i>=0;i--){
            if(arr[i] < head){
                printf("%d ",arr[i]);
            }
        }
        t_seek += (199 - head);
        t_seek += (199 - arr[0]);
    }
    printf("\nEnter total head movement is:- %d\n",t_seek);
}
