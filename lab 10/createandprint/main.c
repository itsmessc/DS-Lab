#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
struct node{
    int val;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
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

void print2DUtil(struct node* root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);
    print2DUtil(root->left, space);
}

void print2D(struct Node* root)
{
    print2DUtil(root, 0);
}

int main()
{
    Node *root=NULL;
    int m,n;
    do{
        printf("1.insert\n2.print\n3.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                 printf("Enter element:");
                 scanf("%d",&m);
                 createBST(&root,m);
                 break;
            case 2:
                print2D(root);
                break;
            case 3:
                return 0;

        }
    }while(1);
    return 0;
}
