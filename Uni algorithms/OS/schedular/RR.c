#include <stdio.h>
#include <stdlib.h>
#define freque 4
typedef struct process PCB;
typedef struct new_queue NQ;
struct process
{
    int pid, priority, arrival_time, burst_time, excuted_time;
    int status; //0: terminate,new 1:running 2: ready 3:wait
};
struct new_queue
{
    PCB *Parr;
    NQ *next;
} * Nque, *NTemp, *Rque, *FRque, *point, *RUN;
int Sum_respone = 0, Sum_burst = 0, Sum_CPU = 0, Sum_ternaround = 0;
int time = 0, N = 10, MAX = 0, F = 0, itime=0;;
FILE *input;
void NEW();
void Ready();
int start();
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Wrong Inputs");
        return -1;
    }
    input = fopen(argv[1], "r");
    if (start() == -1)
        return -1;
    //Schedulling
    while (1)
    {
        NEW();

        //terminate
        if (RUN != NULL && (RUN->Parr->burst_time) == (RUN->Parr->excuted_time))
        {
            printf("<time %d> PID %d finish\n", time, RUN->Parr->pid);
            if (Rque != NULL)
                printf("-----------------------------------(Context-switch)\n");
            RUN->Parr->status = 0;
            Sum_ternaround += time - RUN->Parr->arrival_time;
            free(RUN->Parr);
            free(RUN);
            RUN = NULL;
            F = 0;
        }

        Ready();

        if (RUN != NULL)
        {
            printf("<time %d> pid %d is running\n", time, RUN->Parr->pid);
            RUN->Parr->excuted_time++;
        }
        else if (N == 0 && Rque == NULL)
            break;
        else
            {
                itime++;
                printf("<time %d> --- system is idle ---\n");
            }
        time++;
        F++;
    }
    printf("<time %d> all processes finished\n", time);
    printf("======================================\n");
    printf("Adverage CPU usage : %1.f%%\n",100-(double)itime/time);
    printf("Adverage waiting time  : %.1f\n", ((float)Sum_ternaround - Sum_burst) / MAX);
    printf("Adverage respone time : %.1f\n", (float)Sum_respone / MAX);
    printf("Adverage turnaroundtime : %.1f\n", (float)Sum_ternaround / MAX);
}
void Ready()
{
    if (Rque == NULL)
        return;

    else if (RUN == NULL)
    {
        RUN = Rque;
        Rque = Rque->next;
        F = 0;
        RUN->Parr->status = 1;
        if (RUN->Parr->excuted_time == 0)
            Sum_respone += time - RUN->Parr->arrival_time;
        return;
    }
    else if (F % freque == 0)
    {
        RUN->Parr->status = 2;
        point = Rque;
        while (point->next != NULL)
            point = point->next;
        point->next = RUN;
        RUN->next = NULL;
        RUN = NULL;
        F = 0;
        RUN = Rque;
        Rque = Rque->next;
        printf("-----------------------------------(Context-switch)\n");
        if (RUN->Parr->excuted_time == 0)
            Sum_respone += time - RUN->Parr->arrival_time;
        RUN->Parr->status = 1;
        return;
    }
}
int start()
{

    if (input == NULL)
    {
        printf("Fail to Open");
        return -1;
    }
    RUN = NULL;
    Nque = (NQ *)malloc(sizeof(NQ));
    Rque = NULL;

    for (point = Nque; !feof(input); point->next = (NQ *)malloc(sizeof(NQ)), point = point->next)
    {
        point->next = NULL;
        point->Parr = (PCB *)malloc(sizeof(PCB));
        fscanf(input, "%d %d %d %d ", &(point->Parr->pid), &(point->Parr->priority), &(point->Parr->arrival_time), &(point->Parr->burst_time));
        Sum_burst += point->Parr->burst_time;
        point->Parr->excuted_time = 0;
        point->Parr->status = 0;
        MAX++;
    }
    fclose(input);
    printf("Scheduling : Round-Robin\n");
    printf("----------------------------------------------------\n");
    return 0;
}
void NEW()
{

    if (Nque == NULL)
        return;
    NQ *Npoints = Nque;
    NTemp = Npoints;
    int i = N;
    while (Npoints != NULL && i > 0)
    {
        i--;
        if (Npoints->Parr->arrival_time != time)
        {
            NTemp = Npoints;
            Npoints = Npoints->next;
            continue;
        }
        if (Rque == NULL)
        {
            Rque = Npoints;
            if (Nque == Npoints)
            {
                Nque = Nque->next;
                Npoints = Nque;
                NTemp = Npoints;
            }
            else
            {
                NTemp->next = Npoints->next;
                Npoints = Npoints->next;
            }
            Rque->next = NULL;
            printf("<time %d> [new arrival] PID %d\n", time, Rque->Parr->pid);
        }
        else
        {
            point = Rque;
            while (point->next != NULL)
                point = point->next;
            point->next = Npoints;
            point = point->next;
            if (Nque == Npoints)
            {
                Nque = Nque->next;
                Npoints = Nque;
                NTemp = Npoints;
            }
            else
            {
                NTemp->next = Npoints->next;
                Npoints = Npoints->next;
            }
            point->next = NULL;
            Rque->Parr->status = 2;
            printf("<time %d> [new arrival] PID %d\n", time, Rque->Parr->pid);
        }
        N--;
    }
}