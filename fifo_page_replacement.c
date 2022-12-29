#include<stdio.h>
int find(int frame[],int f,int ele){
    for(int i = 0;i<f;i++){
        if(frame[i] == ele) return 1;
    }
    return 0;
}
int main(){
    int n,f;
    printf("Enter size of referrence string:- ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter pages:- ");
    for(int i = 0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter size of frame:- ");
    scanf("%d",&f);
    int frame[f];
    for(int i = 0;i<f;i++) frame[i] = -1;
    int ptr = -1;
    int p_hit = 0;
    int p_fault = 0;
    for(int i = 0;i<n;i++){
        int hit = find(frame,f,arr[i]);
        if(hit) p_hit++;
        else{
            p_fault++;
            ptr = (ptr + 1) % f;
            frame[ptr] = arr[i];
        }
        for(int i = 0;i<f;i++) printf("%d ",frame[i]);
        printf("\n");
    }
    printf("Page hit = %d\n",p_hit);
    printf("Page fault = %d",p_fault);
    return 0;
}