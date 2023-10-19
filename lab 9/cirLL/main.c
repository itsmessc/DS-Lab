#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
    struct node* prev;
}*head;

void insertele(int data)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory insufficient\n");
        exit;
    }
    newnode->val=data;
    if(head==NULL)
    {
        head=newnode;
        head->next=head;
        head->prev=head;
    }
    else{

        head->prev->next=newnode;
        newnode->prev=head->prev;
        newnode->next=head;
        head->prev=newnode;

    }
}
void display()
{
    struct node* temp;
    temp=head->next;
    printf("%d ",head->val);
    while(temp!=head)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}
void deleteele()
{
    if(head==NULL)
    {
        printf("No element to delete\n");
        return 0;
    }
    if(head->next==head)
    {
        head=NULL;
        return 0;
    }
    struct node*temp;
    temp=head->prev;
    temp->prev->next=head;
    head->prev=temp->prev;
    free(temp);
}
int main()
{
    int s,n;
    do
    {
        printf("1.Insert\n2.Delete\n3.display\n4.exit\n");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                printf("Enter element to insert:");
                scanf("%d",&n);
                insertele(n);
                break;
            case 2:
                deleteele();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Invalid input\n");
        }
    }while(1);
    return 0;
}
