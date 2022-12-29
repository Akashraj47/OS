#include<stdio.h>
struct process{
    int allocated[10];
    int max[10];
    int need[10];
};
int find(struct process p[],int n,int r,int remaining[],int visited[]){
    int flag = 0;
    for(int i = 0;i<n;i++){
        flag = 0;
        if(visited[i] != 1){
            for(int j = 0;j<r;j++){
                if(p[i].need[j] <= remaining[j]) flag = 0;
                else {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                return i;
            }
        }
    }
    if(flag == 1) return -1;
}
int main(){
    int n,r;
    printf("Enter Total number of process:- ");
    scanf("%d",&n);
    printf("Enter types of resources:- ");
    scanf("%d",&r);
    int resources[r];
    printf("Enter no of resources of each type:- \n");
    for(int i = 0;i<r;i++) scanf("%d",&resources[i]);
    struct process p[n];
    int remaining[r];
    for (int i = 0; i < r; i++) remaining[i] = 0; 
    printf("Enter no of allocated resources for each process:- \n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<r;j++){
            scanf("%d",&p[i].allocated[j]);
            remaining[j] += p[i].allocated[j];
        }
    }
    printf("Enter no of max resources need for each process:- \n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<r;j++){
            scanf("%d",&p[i].max[j]);
            p[i].need[j] = p[i].max[j] - p[i].allocated[j];
        }
    }
    for(int i = 0;i<r;i++){
        remaining[i] = resources[i] - remaining[i];
    }
    int completed = 0;
    int visited[n];
    for(int i = 0;i<n;i++) visited[i] = 0;

    printf("\nALLOCATED\tMAX\t\tNEED\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<r;j++){
            printf("%d ",p[i].allocated[j]);
        }
        printf("\t\t");
        for(int j = 0;j<r;j++){
            printf("%d ",p[i].max[j]);
        }
        printf("\t\t");
        for(int j = 0;j<r;j++){
            printf("%d ",p[i].need[j]);
        }
        printf("\n");
    }
    
    printf("Sequence is:- ");
    while(completed != n){
        int ind = find(p,n,r,remaining,visited);
        if(ind == -1){
            printf("System is not in safe state\n");
            break;
        }
        else{
            printf("p[%d] ",ind);
            for(int i = 0;i<r;i++){
                remaining[i] += p[ind].allocated[i];
            }
            visited[ind] = 1;
            completed++;
        }
    }
    return 0;
}