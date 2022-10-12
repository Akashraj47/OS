// FCFS Scheduling  
  
 #include <stdio.h> 
 #include <stdlib.h> 
  
 struct process { 
     int pid;  
     int at;  
     int bt;  
     int ct; 
     int wt; 
     int tat; 
     int rt; 
     int idlet;
 };  
  
 int comparator (const void *p, const void *q)  
 { 
     struct process p1 = (struct process) p; 
     struct process p2 = (struct process) q;  
  
     if (p1->at >= p2->at) 
     return 1;  
     else  
     return -1;  
 } 
  
 int main () { 
  
    int n, sum_turnaround=0, sum_wt=0 , sum_rt = 0;  
    int t_idle = 0,len_cycle = 0;
    float throughput=0;
    float cpu_util = 0;
     printf ("Enter the number of processes: ");  
     scanf ("%d", &n); 
  
     struct process p[n]; 
  
     for (int i=0; i < n; i++) 
     { 
         p[i].pid = i+1;  
         printf ("Enter AT(arrival time) & BT(burst time) for P%d: ", (i+1));  
         scanf("%d%d", &p[i].at, &p[i].bt); 
  
     } 
  
     qsort (p, n, sizeof(struct process), comparator);  
  
     p[0].ct = p[0].at + p[0].bt;  
     p[0].tat = p[0].ct - p[0].at;  
     p[0].wt = p[0].tat - p[0].bt; 
     p[0].rt = (p[0].ct - p[0].bt) - p[0].at;  
        p[0].idlet = 0;
     sum_turnaround += p[0].tat;  
     sum_wt += p[0].wt;  
  
     for (int i=1; i<n; i++) 
     { 
        if(p[i].at >= p[i-1].ct){
            p[i].idlet = p[i].at >= p[i-1].ct;
        }
        else{
            p[i].idlet =0;
        }
        t_idle += p[i].idlet;
         if (p[i].at >= p[i-1].ct) 
         { 
             p[i].ct = p[i].at + p[i].bt;  
         } 
         else { 
             p[i].ct = p[i-1].ct + p[i].bt;  
         } 
         p[i].tat = p[i].ct - p[i].at;  
         p[i].wt = p[i].tat - p[i].bt; 
         p[i].rt = (p[i].ct - p[i].bt) - p[i].at;  
  
         sum_turnaround += p[i].tat;  
         sum_wt += p[i].wt;  
         sum_rt += p[i].rt;
     } 
     
    len_cycle = (p[n-1].ct - p[0].at);
    cpu_util = (((float)(len_cycle - t_idle)/(float)(len_cycle)) * 100.00);
    throughput = (float)n /(float) (len_cycle);
    
     printf ("Pid\tAT\tBT\tCT\tTAT\tWT\tRT\n");  
     for (int i =0; i<n; i++) 
     { 
         printf ("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);  
     } 
     float avg_wt = (float) sum_wt/(float)n; 
     float avg_tat = (float) sum_turnaround/(float)n; 
     float avg_rt = (float) sum_rt/(float)n;
  
     printf ("\nAverage waiting time: %f", avg_wt);  
     printf ("\nAverage Turn-around time: %f", avg_tat);  
     printf ("\nAverage response time: %f", avg_rt);
     printf ("\nidle time: %d", t_idle);  
     printf ("\nlength cycle: %d", len_cycle);  
     printf ("\nCpu Utilization: %f percent", cpu_util);  
     printf ("\nThroughput: %f", throughput);  
     return 0;  
 }
