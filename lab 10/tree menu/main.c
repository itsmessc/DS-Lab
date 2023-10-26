#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
void inorder(Node *root)
{
    Node* stack[50];
    int top=-1;
    Node* current=root;
    while(current!=NULL ||top>-1)
    {
        while(current!=NULL)
        {
            stack[++top]=current;
            current=current->left;
        }
        current=stack[top--];
        printf("%d ",current->val);
        current=current->right;
    }
    printf("\n");
}
void postorder(Node *root)
{
    Node* stack[50];
    int top=-1;
    Node* current=root;
    Node *temp,*pr=NULL;
    while(current!=NULL ||top>-1)
    {
        if(current!=NULL)
        {
            stack[++top]=current;
            current=current->left;
        }
        else{
            temp=stack[top];
            if(temp->right!=NULL && temp->right!=pr )
            {
                current=temp->right;

            }
            else
            {
                pr=temp;
                printf("%d ",temp->val);
                top--;
            }
        }
    }
    printf("\n");
}
void preorder(Node *root)
{
    Node *current=root;
    Node *stack[50];
    int top=-1;
    while(current!=NULL || top>-1)
    {
        while(current!=NULL)
        {
            printf("%d ",current->val);
            stack[++top]=current;

            current=current->left;
        }
        current=stack[top--];
        current=current->right;
    }
    printf("\n");
}
void createBST(struct node** root,int data)
{
    struct node* temp =(struct node*)malloc(sizeof(struct node));
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    struct node* t = *root;
    if(*root==NULL)
    {
        *root = temp;
        return;
    }
    if(data<t->val)
        createBST(&(t->left),data);
    else
        createBST(&(t->right),data);

}
int leafs(Node *root)
{
   if(root==NULL)
   {
       return 0;
   }
   if(root->left==NULL && root->right==NULL)
    return 1;
   else
    return leafs(root->left)+leafs(root->right);
}
void parent(Node *root,int data)
{
    Node *current=root;
    if(current->val==data)
    {
        printf("No parents\n");
        return ;
    }
    while(1)
    {
        if(current->left->val==data || current->right->val==data)
        {
            printf("%d is parent of %d\n",current->val,data);
            return;
        }
        if(current->val>data)
        {
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
}
void ancestors(Node *root,int value)
{
    Node *current=root;
    while(current->val!=value)
    {
        printf("%d ",current->val);
        if(current->val>value)
        {
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    printf("\n");
}
int maxDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
int main()
{
    struct node *root=NULL;
    int m,n,mn;
    do
    {
        printf("1.Insert\n2.inorder\n3.preorder\n4.postorder\n5.number of leafs\n6.parent of given\n7.Ancestors\n8.depth\n9.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                 printf("Enter element:");
                 scanf("%d",&m);
                 createBST(&root,m);
                 break;
            case 2:
                inorder(root);
                break;
            case 9:
                return 0;
                break;
            case 4:
                postorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 5:
                mn=leafs(root);
                printf("no of leafs of tree are:%d\n",mn);
                break;
            case 6:
                printf("Enter element to check parent:");
                scanf("%d",&m);
                parent(root,m);
                break;
            case 7:
                printf("Enter element to check ancestors:");
                scanf("%d",&m);
                ancestors(root,m);
            case 8:
                mn=maxDepth(root);
                printf("Depth of tree is:%d\n",mn);
                break;
            default:
                printf("Invalid input\n");
        }
    }while(1);
    return 0;
}
