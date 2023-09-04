#include <stdio.h>
#include <stdlib.h>
#define max 10

int queue[max];
int front=-1,rear=-1;
int isFull()
{
    if((rear+1==front) || (rear==max-1 && front==0))
        return 1;
    return 0;
}
void enqueue(int item)
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
    queue[rear]=item;
    printf("%d enqueued\n",item);
}
void dequeue()
{
    if(rear==-1 && front==-1)
    {
        printf("queue underflow\n");
    }
    else if(front==rear)
    {
        printf("element %d dequeued\n",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("element %d dequeued\n",queue[front]);
        front=(front+1)%max;
    }
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
            printf("%d ",queue[i]);
            i++;
        }
        printf("\n");
    }
    else
    {
        while(i<max)
        {
            printf("%d ",queue[i]);
            i++;
        }
        i=0;
        while(i<=rear)
        {
            printf("%d ",queue[i]);
            i++;
        }
        printf("\n");
    }
}
int main()
{
    int n,a;
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
               printf("Enter element to enqueue:");
               scanf("%d",&a);
               enqueue(a);
               break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
        }
    }
    return 0;
}
