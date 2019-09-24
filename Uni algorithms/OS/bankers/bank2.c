#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pidList list;
typedef struct controlBlock pid;
struct controlBlock
{
    int pid;
    int *allocation;
    int *max;
};
struct pidList
{
    pid *block;
    list *next;
} * head;
int *rest, Process, mount, t;
FILE *open, *write;
int checkstart(int i);
int check(int size, int arr[], int que[], int temp[], int resour[]);
void start();
void adds();
int main(int argc, char *argv[])
{
    int i = 3;
    if (argc != 5 && argc != 4 && argc != 1)
    {
        printf("wrong Input");
        exit(-1);
    }
    else if (argc == 4)
    {
        i--;
        printf("you didn't set output file - automatly setted name is output.txt\n");
    }
    mount = atoi(argv[i]);
    Process = atoi(argv[i + 1]);
    if (NULL == (open = fopen(argv[1], "r")))
    {
        printf("failed to open input file\n");
        exit(-1);
    }
    write = (argc == 5) ? fopen(argv[2], "w") : fopen("output.txt", "w");
    rest = malloc(sizeof(int) * mount);
    fprintf(write, "%s\n", argv[1]);
    start();
    list *point = head;
    checkstart(1);
    adds();
    checkstart(0);
    close(open);
    close(write);
    return 0;
}

void start()
{
    for (int i = 0; i < mount; i++)
        fscanf(open, "%d", &(rest[i]));
    head = (list *)malloc(sizeof(list));
    list *point = head;
    point->next = NULL;
    point->block = (pid *)malloc(sizeof(pid));
    point->block->allocation = malloc(sizeof(int) * mount);
    point->block->max = malloc(sizeof(int) * mount);
    fscanf(open, "%d", &(head->block->pid));
    for (int i = 0; i < mount; i++)
        fscanf(open, "%d", &(point->block->allocation[i]));
    for (int i = 0; i < mount; i++)
        fscanf(open, "%d", &(point->block->max[i]));
    for (int i = 1; i < Process; i++)
    {
        point->next = (list *)malloc(sizeof(list));
        point = point->next;
        point->next = NULL;
        point->block = (pid *)malloc(sizeof(pid));
        point->block->allocation = malloc(sizeof(int) * mount);
        point->block->max = malloc(sizeof(int) * mount);
        fscanf(open, "%d", &(point->block->pid));
        for (int i = 0; i < mount; i++)
            fscanf(open, "%d", &(point->block->allocation[i]));
        for (int i = 0; i < mount; i++)
            fscanf(open, "%d", &(point->block->max[i]));
    }
}
int check(int size, int arr[], int que[], int temp[], int resour[])
{
    list *point = head;
    int *left = malloc(sizeof(int) * mount);
    for (int i = 0; i < mount; i++)
        left[i] = resour[i] + temp[i];
    if (size <= 1)
    {
        for (int i = 0; i < Process; i++)
            if (!arr[i])
            {
                for (int j = 0; j < mount; j++)
                    if (point->block->max[j] - point->block->allocation[j] > left[j])
                        return 0;
                que[Process - 1] = i + 1;
                return 1;
            }
            else
                point = point->next;
    }
    for (int i = 0; i < Process; i++)
    {
        if (arr[i])
            goto con;
        for (int j = 0; j < mount; j++)
            if (point->block->max[j] - point->block->allocation[j] > left[j])
                goto con;
        arr[i] = 1;
        que[t++] = i + 1;
        if (check(size - 1, arr, que, point->block->allocation, left))
            return 1;
        arr[i] = 0;
    con:
        if (point == NULL)
            return 0;
        point = point->next;
    }
    return 0;
}
int checkstart(int i)
{
    t = 0;
    int arr[Process]; //memo that pid has in ques
    int que[Process]; //save pid
    int *temp = malloc(sizeof(int) * mount);

    for (int i = 0; i < mount; i++)
        temp[i] = 0;
    for (int i = 0; i < Process; i++)
        arr[i] = que[i] = 0;
    if (i)
    {
        fprintf(write, "current state : ");
        printf("current state : ");
    }
    else
    {
        fprintf(write, "After arriving request : ");
        printf("After arriving request : ");
    }
    if (!check(Process, arr, que, temp, rest))
    {
        fprintf(write, "unsafe!");
        printf("unsafe!\n");
        exit(0);
    }
    fprintf(write, "p%d", que[0]);
    printf("p%d", que[0]);
    for (int i = 1; i < Process; i++)
    {
        fprintf(write, "->p%d", que[i]);
        printf("->p%d", que[i]);
    }
    fprintf(write, "\n");
    printf("\n");
}
void adds()
{
    int pid, *tarr = malloc(sizeof(int) * mount);
    list *point = NULL;
    while (!feof(open))
    {
        fscanf(open, "%d", &pid);
        for (int i = 0; i < mount; i++)
            fscanf(open, "%d", &(tarr[i]));
        point = head;
        while (point != NULL && point->block->pid != pid)
            point = point->next;
        if (point == NULL)
            exit(-1);
        for (int i = 0; i < mount; i++)
            point->block->max[i] += tarr[i];
    }
}