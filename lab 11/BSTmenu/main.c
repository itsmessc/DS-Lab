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
int search(Node*root,int data)
{
    if(!root)
        return 0;
    if(data==root->val)
        return (1);
    else if(data<root->val)
        search(root->left,data);
    else if(data>root->val)
        search(root->right,data);
}
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
struct node* deletel(struct node* root, int k)
{
    if (root == NULL)
        return root;
    if (root->val > k) {
        root->left = deletel(root->left, k);
        return root;
    }
    else if (root->val < k) {
        root->right = deletel(root->right, k);
        return root;
    }
    if (root->left == NULL) {
        Node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        free(root);
        return temp;
    }
    else {
        Node* succParent = root;
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->val = succ->val;
        free(succ);
        return root;
    }
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
    struct node *root=NULL;
    int m,n,mn;
    do{
        printf("1.Insert\n2.Delete\n3.Search\n4.Traverse\n5.exit");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter element:");
                scanf("%d",&m);
                createBST(&root,m);
                break;
            case 2:
                printf("Enter element:");
                scanf("%d",&m);
                root=deletel(root,m);
                break;
            case 3:
                printf("Enter element:");
                scanf("%d",&m);
                mn=search(root,m);
                if(mn==1)
                {
                    printf("Element found:\n");
                }
                else
                    printf("Element not found:\n");
                break;
            case 4:
                inorder(root);
                print2D(root);
                break;
            case 5:
                return 0;
        }
    }while(1);
    return 0;
}
