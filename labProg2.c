#include<stdio.h>
typedef struct{
    int ProcessID;
    int burstTime;
    int Priority;
}Process;
void fcfs(Process processes[],int n){
    int waitingTime=0;
    float TotalwaitingTime=0;
    float averagewaitingTime=0;
    printf("FCFS Scheduling Algorithm");
    for(int i=0;i<n;i++){
        printf("Process %d is running.\n",processes[i].ProcessID);
        waitingTime+=processes[i].burstTime;
        printf("Process %d is finished.waiting time:%d\n",processes[i].ProcessID,waitingTime);
        TotalwaitingTime+=waitingTime;
    }
    averagewaitingTime=TotalwaitingTime/n;
    printf("Average waiting Time: %.2f\n",averagewaitingTime);
}
void sjn(Process processes[],int n){
    int totalTime=0;
    int waitingTime=0;
    float TotalwaitingTime=0;
    float averagewaitingTime=0;
    printf("SJN Scheduling Algorithm");
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(processes[j].burstTime>processes[j+1].burstTime)
            {
                Process temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("Process %d is running.\n",processes[i].ProcessID);
        waitingTime+=totalTime;
        totalTime+=processes[i].burstTime;
        printf("Process %d finished. Waiting time: %d\n",processes[i].ProcessID,waitingTime);
        TotalwaitingTime+=waitingTime;
    }
    averagewaitingTime=TotalwaitingTime/n;
    printf("Average Waiting Time: %.2f\n",averagewaitingTime);
}
void priorityScheduling(Process processes[], int n)
{
    int waitingTime=0;
    float totalWaitingTime=0;
    float averageWaitingTime;
    printf("\nPriority Scheduling Algorithm:\n");
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(processes[j].burstTime>processes[j+1].burstTime)
            {
                Process temp=processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("Process %d is running.\n",processes[i].ProcessID);
        waitingTime+=processes[i].burstTime;
        printf("Process %d finished. Waiting time: %d\n",processes[i].ProcessID,waitingTime);
        totalWaitingTime+=waitingTime;
    }
    averageWaitingTime=totalWaitingTime/n;
    printf("Average Waiting Time: %.2f\n",averageWaitingTime);
}
