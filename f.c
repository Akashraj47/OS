#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

struct process
{
    int pid,at,bt,ct,tat,wt,rt,st;
};

int comparator(const void* a,const void* b){
    int x = ((struct process *)a)->at;
    int y = ((struct process *)b)->at;
    if(x < y){
        return -1;
    }
    else if( x >= y){
        return 1;
    }
}

int max(int a,int b){
    if(a <= b){
        return b;
    }
    else{
        return a;
    }
}


int main(){
    int n;
    printf("Enter total numbe of process:- ");
    scanf("%d",&n);

    float t_tat = 0,t_wt = 0,t_rt= 0;
    float lengh_cycle = 0;
    float cpu_util = 0;

    struct process p[n];
    int remaining[n] ;
    int visited[n] ;
    for(int i = 0;i<n;i++){
        visited[i] = 0;
    }
    for(int i = 0;i<n;i++){
        printf("Enter At and Bt of process %d:- ",i+1);
        scanf("%d",&p[i].at);
        scanf("%d",&p[i].bt);
        remaining[i] = p[i].bt;
    }

    int qn;
    printf("Enter time quanta:- ");
    scanf("%d",&qn);

    int queue[100];
    int front = -1,rear = -1;

    qsort((void *)p,n,sizeof(struct process),comparator);
    front = rear = 0;
    queue[rear] = 0;
    visited[0] = 1;
    
    int completed = 0;
    int curr_time = 0;
    int first_process = 0;
    int t_idle_time = 0;
    
    while(completed != n){
        int index = queue[front];
        front++;

        if(p[index].bt == remaining[index]){
            p[index].st = max(curr_time,p[index].at);
            curr_time = p[index].st;
            if(first_process == 1){
                t_idle_time += 0;
            }
            else{
                t_idle_time += p[index].st - curr_time;
            }
        }

        if(remaining[index] - qn > 0){
            remaining[index] -= qn;
            curr_time += qn;
        }

        else{
            curr_time += remaining[index];
            completed++;
            
            p[index].ct = curr_time;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].st - p[index].at;

            t_tat += p[index].tat;
            t_wt += p[index].wt;
            t_rt += p[index].rt;

            remaining[index] = 0;
        }

        for(int i = 0;i<n;i++){
            if(p[i].at <= curr_time && visited[i] != 1){
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
        }

        if(remaining[index] != 0){
            rear++;
            queue[rear] = index;
        }
    }
    printf("\n\n");
    printf("AT\tBT\tst\tct\ttat\twt\trt\n");
    for(int i = 0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }

    printf("\n\n");
    printf("Average Tat:- %f\n",t_tat/n);
    printf("Average wt:- %f\n",t_wt/n);
    printf("Average rt:- %f\n",t_rt/n);

    int max_completion = -1;
    for(int i = 0;i<n;i++){
        if(max_completion < p[i].ct){
            max_completion = p[i].ct;
        }
    }

    lengh_cycle = (float)n / (max_completion - p[0].at);
    printf("length cycle :- %f\n",lengh_cycle);

    cpu_util = ((float)(lengh_cycle - t_idle_time) / (lengh_cycle)) * 100;
    printf("Cpu utilisation:- %f",cpu_util);
    return 0;
}

