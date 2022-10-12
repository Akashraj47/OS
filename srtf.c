#include<stdio.h>
#include<limits.h>
struct process{
    int pid;
    int at,bt,st,ct,tat,wt,rt;
};
int main(){
    int n;
    printf("Enter total number of process");
    scanf("%d",&n);
    struct process pss[n];
    int pre = 0;
    int curr_time = 0;
    int min = INT_MAX;
    int rem_time[n] ;
    int is_completed[n];
    for(int i = 0;i<n;i++){
        is_completed[i] = 0;
    }

    for(int i = 0;i<n;i++){
        printf("Enter arrival time of process %d:- ",i+1);
        scanf("%d",&pss[i].at);
        printf("Enter burst time of process %d:- ",i+1);
        scanf("%d",&pss[i].bt);
        pss[i].pid = i+1;
        rem_time[i] = pss[i].bt;
    }
    return 0;
}