#include<stdio.h>
int find(int frame[],int f,int ele){
    for(int i = 0;i<f;i++){
        if(frame[i] == ele) return i;
    }
    return -1;
}
int main(){
    int n,f;
    printf("Enter size of reference string:- ");
    scanf("%d",&n);
    int arr[n];
    int queue[n];
    for(int i = 0;i<n;i++) queue[i] = -1;
    for(int i = 0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter frame size:- ");
    scanf("%d",&f);
    int frame[f];
    for(int i = 0;i<f;i++) frame[i] = -1;
    int ptr = -1;
    int p_hit = 0,p_fault = 0;
    for(int i = 0;i<n;i++){
        int hit = find(frame,f,arr[i]);
        if(hit == -1){
            p_fault++;
            int ind = find(frame,f,-1);
            if(ind == -1){
                int ele;
                for(int i = 0;i<n;i++){
                    if(queue[i] >= 0) {
                        ele = queue[i];
                        queue[i] = -1;
                        break;
                    }
                }
                int r = find(frame,f,ele);
                frame[r] = arr[i];
                ptr++;
                queue[ptr] = arr[i];
            }
            else{
                frame[ind] = arr[i];
                ptr++;
                queue[ptr] = arr[i];
            }
        }
        else{
            p_hit++;
            int ind = find(queue,n,arr[i]);
            queue[ind] = -1;
            ptr++;
            queue[ptr] = arr[i];
        }
        for(int i = 0;i<f;i++) printf("%d ",frame[i]);
        printf("\n");
    }
    printf("page hit = %d\n",p_hit);
    printf("page fault = %d\n",p_fault);
    return 0;
}