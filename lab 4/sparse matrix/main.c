#include <stdio.h>
#include <stdlib.h>
#define max 50
int rear=-1,front=-1;
struct Queue
{
    int row;
    int column;
    int value;
}queue[max];
int isFull()
{
    if((rear+1==front) || (rear==max-1 && front==0))
        return 1;
    return 0;
}
void enqueue(int i,int j,int value)
{
    if(isFull()==1)
    {
        printf("Queue overflown\n");
        return;
    }
    else if(front==rear)
    {
        front=0;
    }
    rear=(rear+1)%max;
    queue[rear].row=i;
    queue[rear].column=j;
    queue[rear].value=value;
}

void display()
{
    if(rear==-1 && front==-1)
    {
        printf("Queue is empty\n");
        return ;
    }
    int i=front;
    if(front<=rear)
    {
        while(i<=rear)
        {
            printf("%d\t%d\t%d\n",queue[i].row,queue[i].column,queue[i].value);
            i++;
        }
    }
    else
    {
        while(i<max)
        {
            printf("%d\t%d\t%d\n",queue[i].row,queue[i].column,queue[i].value);
            i++;
        }
        i=0;
        while(i<=rear)
        {
            printf("%d\t%d\t%d\n",queue[i].row,queue[i].column,queue[i].value);
            i++;
        }
    }
}
int main()
{
    int a[10][10];
    int i,j,temp;
    int n,m;
    printf("Enter order of matrix:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<j)
            {
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                enqueue(i,j,a[i][j]);
            }
        }
    }
    printf("Fast transpose of a sparse matrix:\n");
    printf("row\tcolumn\tvalue\n");
    display();
    return 0;
}
