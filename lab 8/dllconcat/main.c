#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node* prev;
    struct node *next;
    int data;
}*head1,*head2;
void concat()
{
    struct node *temp;
    temp=head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    head2->prev=temp;
}
void insertend(int a,int n)
{
    struct node *newnode,*temp,*head;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory insufficient\n");
        return ;
    }
    newnode->data=a;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(n==1)
    {
        if(head1==NULL)
        {
            head1=newnode;
        }
        else
        {
            temp=head1;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }
    }
    else if(n==2)
    {
        if(head2==NULL)
        {
            head2=newnode;
        }
        else
        {
            temp=head2;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }
    }

}
void display(int a)
{
    struct node *temp;
    if(a==1)
        temp=head1;
    else if(a==2)
        temp=head2;
    if(temp==NULL)
    {
        printf("Nothing to display\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int i,m,n;
    do{
        printf("1.Insert\n2.concat\n3.display\n4.exit\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                printf("Enter value and list number:");
                scanf("%d %d",&m,&n);
                insertend(m,n);
                break;
            case 2:
                concat();
                break;
            case 3:
                printf("Enter linked list number to display");
                scanf("%d",&m);
                display(m);
                break;
            case 4:
                exit(0);
                break;
        }
    }while(1);
    return 0;
}
