#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct process{
    float at,bt,ct,tat,wt,rt,st;
};
int max(int a,int b) {return (a > b) ? a : b;}
int comp(const void * a,const void *b){
    int p = ((struct process *)a)->at;
    int q = ((struct process *)b)->at;
    if(p < q) return -1;
    else return 1;
}
int main(){
    int n;
    printf("Enter Total number of process:- ");
    scanf("%d",&n);
    struct process p[n];
    float max_comp = INT_MIN,min_arr = INT_MAX;
    float t_tat =0,t_wt = 0,t_rt = 0;
    float len_cycle = 0,through_put = 0,cpu_util = 0;
    int remaining[n];
    int queue[100];
    int front = -1,rear = -1;
    printf("Enter Arrival time and burst time:- ");
    for(int i = 0;i<n;i++){
        scanf("%f",&p[i].at);
        scanf("%f",&p[i].bt);
        if(p[i].at < min_arr) min_arr = p[i].at;
        remaining[i] = p[i].bt;
    }
    int completed = 0;
    int curr_time  = 0;
    float t_idle = 0;
    int visited[n];
    for(int i = 0;i<n;i++) visited[i] = 0;
    qsort((void *)p,n,sizeof(struct process),comp);
    front++;
    rear++;
    queue[rear] = 0;
    visited[0] = 1;
    int q;
    printf("Enter time quanta:- ");
    scanf("%d",&q);
    while(completed != n){
        int ind = queue[front];
        front++;
        
        if(remaining[ind] == p[ind].bt){
            p[ind].st = max(p[ind].at,curr_time);
            t_idle += (p[ind].st - curr_time);
            curr_time = p[ind].st;
        }
        if(remaining[ind] - q > 0){
            curr_time += q;
            remaining[ind] -= q;
        }
        else{
            curr_time += remaining[ind];
            remaining[ind] = 0;
            p[ind].ct = curr_time;
            p[ind].tat = p[ind].ct - p[ind].at;
            p[ind].wt = p[ind].tat - p[ind].bt;
            p[ind].rt = p[ind].st - p[ind].at;
            
            t_tat += p[ind].tat;
            t_rt += p[ind].rt;
            t_wt += p[ind].wt;
            if(p[ind].ct > max_comp) max_comp = p[ind].ct;
            completed++;
        }
        for(int i = 1;i<n;i++){
            if(p[i].at <= curr_time && visited[i] != 1 && remaining[i] > 0){
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
        }
        if(remaining[ind] > 0){
            rear++;
            queue[rear] = ind; 
        }
        if(front > rear){
            for(int i = 0;i<n;i++){
                if(remaining[i] > 0){
                    rear++;
                    queue[rear] = i;
                    visited[i] = i;
                    break;
                }
            }
        }
    }
    len_cycle = max_comp - min_arr;
    through_put= n / len_cycle;
    cpu_util = (len_cycle - t_idle) / len_cycle * 100;
    printf("AVG TAT = %f\n",t_tat/n);
    printf("AVG WT = %f\n",t_wt/n);
    printf("AVG RT = %f\n",t_rt/n);
    printf("AVG through_put = %f\n",through_put);
    printf("Cpu util = %f\n",cpu_util);
    return 0;
}