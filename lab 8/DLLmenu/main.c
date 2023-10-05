#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node* prev;
    struct node *next;
    int data;
}*head;

void insertend(int a)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory insufficient\n");
        return ;
    }
    newnode->data=a;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void delend()
{
    struct node *temp,*temp1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp1=temp->prev;
    temp1->next=NULL;
    free(temp);
}
/*void display()
{
    if(head==NULL)
    {
        printf("Nothing to display\n");
    }
    else{
        struct node *temp;
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}*/
void insertatpo(int a,int po)
{
    int i;
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory insufficient\n");
        return ;
    }
    newnode->data=a;
    newnode->next=NULL;
    newnode->prev=NULL;
    temp=head;
    for(i=1;i<po;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("insertion not possible");
            return ;
        }
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
}
void insertafter(int a,int m)
{
    struct node *temp,*newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory insufficient\n");
        return ;
    }
    newnode->data=a;
    newnode->next=NULL;
    newnode->prev=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==m)
        {
            break;
        }
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        insertend(a);
        return;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
}
void insertbefore(int a,int m)
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory insufficient\n");
        return ;
    }
    newnode->data=a;
    newnode->next=NULL;
    newnode->prev=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==m)
        {
            break;
        }
        temp=temp->next;
    }
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;
}
void delatpo(int p)
{
    int i;
    struct node *temp;
    temp=head;
    for(i=0;i<p;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("deletion not possible");
            return ;
        }
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}
void traverse()
{
    printf("Linked list:");
    if(head==NULL)
    {
        printf("NULL");
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
void reverse()
{
    struct node *temp,*curr;
    curr=head;
    while(curr!=NULL)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    head=temp->prev;
}
int main()
{
    int i,m,p;
    do{
        printf("DLL menu:\n");
        printf("1.Insertion at end\n");
        printf("2.Deletion at end\n");
        printf("3.Insertion at position\n");
        printf("4.Delete at position\n");
        printf("5.Insert after element\n");
        printf("6.Insert before element\n");
        printf("7.Traverse\n");
        printf("8.Reverse\n");
        //printf("9.display\n");
        printf("Enter choice:");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                printf("Enter element:");
                scanf("%d",&m);
                insertend(m);
                break;
            case 2:
                delend();
                break;
            case 3:
                printf("Enter element and position:");
                scanf("%d %d",&m,&p);
                insertatpo(m,p);
                break;
            case 4:
                printf("Enter position:");
                scanf("%d",&p);
                delatpo(p);
                break;
            case 5:
                printf("Enter element to be inserted:");
                scanf("%d",&m);
                printf("Enter element after which to be inserted:");
                scanf("%d",&p);
                insertafter(m,p);
                break;
            case 6:
                printf("Enter element to be inserted:");
                scanf("%d",&m);
                printf("Enter element before which to be inserted:");
                scanf("%d",&p);
                insertbefore(m,p);
                break;
            case 7:
                traverse();
                break;
            case 8:
                reverse();
                break;
            /*case 9:
                display();
                break;*/

        }
    }while(i!=0);
    return 0;
}
