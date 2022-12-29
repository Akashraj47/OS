// Cscan
#include<stdio.h>
int main(){
    int n;
    printf("Enter size of array:- ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int head = 0;
    printf("Enter initial position of head:- ");
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
    printf("Enter 1 for left movement and 2 for right movement:- ");
    scanf("%d",&choice);
    int l;
    if(choice == 1){
        for(int i = n-1;i>=0;i--){
            if(arr[i] <= head){
                printf("%d ",arr[i]);
            }
        }
        printf("0 ");
        printf("199 ");
        for(int i = n-1;i>=0;i--){
            if(arr[i] > head){
                printf("%d ",arr[i]);
                l = arr[i];
            }
        }
        t_seek += (head);
        t_seek += (199);
        t_seek += (199 - l);
    }
    else if(choice == 2){
        for(int i = 0;i<n;i++){
            if(arr[i] >= head){
                printf("%d ",arr[i]);
            }
        }
        printf("199 ");
        printf("0 ");
        for(int i = 0;i<n;i++){
            if(arr[i] < head){
                printf("%d ",arr[i]);
                l = arr[i];
            }
        }
        t_seek += (199 - head);
        t_seek += 199;
        t_seek += (l);
    }
    printf("\nTotal seek time is:- %d",t_seek);
    return 0;
}
