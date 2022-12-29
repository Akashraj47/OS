#include<stdio.h>
#include<limits.h>
struct process{
    int at,bt,ct,st,tat,rt,wt;
    int priority;
};
int main(){
    int n;
    printf("Enter Total number of process:- ");
    scanf("%d",&n);
    struct process p[n];
    int remaining[n];
    int max_completion = INT_MIN;
    int min_arrival = INT_MAX;
    int t_idle_time = 0;
    printf("Enter arrival Time and burst time and priority:- \n");
    for(int i = 0;i<n;i++){
        scanf("%d",&p[i].at);
        scanf("%d",&p[i].bt);
        scanf("%d",&p[i].priority);
        remaining[i] = p[i].bt;
        if(p[i].at <= min_arrival){
            min_arrival = p[i].at;
        }
    }
    int curr_time = 0,prev = 0;
    int min,min_ind;
    float t_tat = 0,t_wt = 0,t_rt= 0;
    int finished = 0;
    while(finished != n){
        min = INT_MAX;
        min_ind = -1;
        for(int i = 0;i<n;i++){
            if(p[i].at <= curr_time && remaining[i] > 0){
                if(p[i].priority < min){
                    min = p[i].priority;
                    min_ind = i;
                }
                else if(p[i].priority == min){
                    if(p[i].at < p[min_ind].at){
                        min = p[i].priority;
                        min_ind = i;
                    }
                }
            }
        }
        if(min_ind == -1){
            curr_time++;
            continue;
        }
        else{
            if(remaining[min_ind] == p[min_ind].bt){
                p[min_ind].st = curr_time;
                t_idle_time += (curr_time - prev);
            }
            curr_time++;
            prev = curr_time;
            remaining[min_ind]--;
            if(remaining[min_ind] == 0){
                p[min_ind].ct = curr_time;
                p[min_ind].rt = p[min_ind].st - p[min_ind].at;
                p[min_ind].tat = p[min_ind].ct - p[min_ind].at;
                p[min_ind].wt = p[min_ind].tat - p[min_ind].bt;

                t_tat += p[min_ind].tat;
                t_rt += p[min_ind].rt;
                t_wt += p[min_ind].wt;
                finished++;
                if(max_completion <= p[min_ind].ct){
                    max_completion = p[min_ind].ct;
                }
            }
        }   
    }
    printf("\nAT\tBT\tST\tCT\tRT\tTAT\tWT\n");
    for(int i = 0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].rt,p[i].tat,p[i].wt);
    }
    printf("Average TAT = %f\n",(float)(t_tat / n));
    printf("Average WT = %f\n",(float)(t_wt / n));
    printf("Average RT = %f\n",(float)(t_rt / n));
    float len_cycle = max_completion - min_arrival;
    printf("Length cycle:- %f\n",len_cycle);
    printf("Through_put = %f\n",(float)n / (float)len_cycle);
    float cpu_util = 0;
    cpu_util = (float)(len_cycle - t_idle_time) / (float)len_cycle * 100.0;
    printf("Cpu Utilisation = %f\n",cpu_util);
    return 0;
}