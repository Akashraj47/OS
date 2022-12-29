#include <stdio.h>
#include <stdbool.h>

struct pro
{
    int max[10];
    int allocated[10];
    int need[10];
};
int n, r;
void input(struct pro process[], int available[])
{

    for (int i = 0; i < n; i++)
    {
        printf("Enter process[%d] info\n", i);
        printf("Enter Maximum Need: ");
        for (int j = 0; j < r; j++)
            scanf("%d", &process[i].max[j]);
        printf("Enter No. of Allocated Resources for this process: ");
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &process[i].allocated[j]);
            process[i].need[j] = process[i].max[j] - process[i].allocated[j];
        }
    }
    printf("Enter Available Resources: ");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &available[i]);
    }
}

void showTheInfo(struct pro process[])
{
    printf("\nPID\tMaximum\t\tAllocated\tNeed\n");
    for (int i = 0; i < n; i++)
    {

        printf("P[%d]\t", i);
        for (int j = 0; j < r; j++)
            printf("%d ", process[i].max[j]);
        printf("\t\t");
        for (int j = 0; j < r; j++)
            printf("%d ", process[i].allocated[j]);
        printf("\t\t");
        for (int j = 0; j < r; j++)
            printf("%d ", process[i].need[j]);
        printf("\n");
    }
}
bool applySafetyAlgo(struct pro process[], int available[], int safeSequence[])
{
    bool finish[n];
    int work[r];
    for (int i = 0; i < r; i++)
    {
        work[i] = available[i];
    }
    for (int i = 0; i < n; i++)
        finish[i] = false;
    bool proceed = true;
    int k = 0;
    while (proceed)
    {
        proceed = false;
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            if (finish[i] == false)
            {

                for (int j = 0; j < r; j++)
                {

                    if (process[i].need[j] <= work[j])
                    {
                        continue;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                    continue;
                for (int j = 0; j < r; j++)
                    work[j] = work[j] + process[i].allocated[j];

                finish[i] = true;
                safeSequence[k++] = i;
                proceed = true;
            }
        }
    }
    int i;
    for (i = 0; i < n && finish[i] == true; i++)
    {
        continue;
    }

    if (i == n)
        return true;
    else
        return false;
}
bool isSafeState(struct pro process[], int available[], int safeSequence[])
{

    if (applySafetyAlgo(process, available, safeSequence) == true)
        return true;
    return false;
}
int main()
{
    printf("Name: Chandni Mishra\n Student ID:20012871\n");
    printf("Enter No of Process: ");
    scanf("%d", &n);
    printf("\nEnter No of Resource Instances in system: ");
    scanf("%d", &r);
    int available[r];
    int safeSequence[n];
    struct pro process[n];
    input(process, available);
    printf("\n");
    showTheInfo(process);
    printf("\n");
    if (isSafeState(process, available, safeSequence))
    {
        printf("\nSystem is in SAFE State\n");
        printf("Safe Sequence is: ");
        for (int i = 0; i < n; i++)
            printf("P[%d] ", safeSequence[i]);
    }
    else
        printf("\nSystem is in UNSAFE State\n");
    return 0;
}