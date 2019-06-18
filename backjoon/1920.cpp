#include <stdio.h>
#include <stdlib.h>
typedef struct tre tree;
struct tre
{
    int data;
    tree *left;
    tree *right;
} * head, *point;
void add(tre *point, int data);
void search(int dat);
int main()
{
    int N, dat;
    scanf("%d", &N);
    head = (tree *)malloc(sizeof(tree));
    head->right = head->left = NULL;

    scanf("%d", &(head->data));
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &dat);
        add(head, dat);
    }
    scanf("%d", &N);
    scanf("%d", &dat);
    search(dat);
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &dat);
        printf("\n");
        search(dat);
    }
}

void search(int data)
{
    point = head;
    int temp;
    while (1)
    {
        temp = point->data;
        if (temp == data)
            printf("1");
        else if (temp < data)
            if (point->right == NULL)
                printf("0");
            else
            {
                point = point->right;
                continue;
            }
        else if (point->left == NULL)
            printf("0");
        else
        {
            point = point->left;
            continue;
        }
        return;
    }
}

void add(tre *point, int data)
{
    if (point->data > data)
        if (point->left == NULL)
        {
            point->left = (tree *)malloc(sizeof(tree));
            point = point->left;
            point->data = data;
            point->left = point->right = NULL;
        }
        else
            add(point->left, data);
    else if (point->right == NULL)
    {
        point->right = (tree *)malloc(sizeof(tree));
        point = point->right;
        point->data = data;
        point->left = point->right = NULL;
    }
    else
        add(point->right, data);
}