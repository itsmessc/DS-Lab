#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};
// void bubblesort(Node *head){
//     int swap,i;
//     Node *ptr1,*ptr2=NULL,*temp=head;
//     do{
//         swap=0;
//         ptr1=head;
//         while(ptr1->next!=ptr2)
//         {   
//             if(ptr1->val>ptr1->next->val)
//             {
//                 int t=ptr1->val;
//                 ptr1->val=ptr1->next->val;
//                 ptr1->next->val=t;
//                 swap=1;
//             }
//             ptr2=ptr1;
//         }
//     }while(swap);
// }
void inorder(struct node *root){
    if(root==NULL)
    {
        printf("Empty");
    }
    else{
        struct node *current,*stack[100];
        int top=-1;
        current=root;
        while(current!=NULL || top>-1)
        {
            while(current!=NULL)
            {
                stack[++top]=current;
                current=current->left;
            }
            current=stack[top--];
            printf("%d ",current->value);
            current=current->right;
        } 
    }
}

void create(struct node **root,int i){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->value=i;
    newnode->left=NULL;
    newnode->right=NULL;
    if(*root==NULL)
    {
        *root=newnode;
    }
    else if((*root)->value>i)
    {
        create(&(*root)->left,i);
    }
    else{
        create(&(*root)->right,i);
    }
}

void postorder(struct node* root){
    struct node *stack1[100],*stack2[100],*current;
    int top1=-1,top2=-1;
    current=root;
    stack1[++top1]=current;
    while(top1>-1){
        current=stack1[top1--];
        stack2[++top2]=current;
        if(current->left!=NULL)
        stack1[++top1]=current->left;
        if(current->right!=NULL)
        stack1[++top1]=current->right;
    }
    while(top2>-1)
    printf("%d ",stack2[top2--]);
}
struct node* deletee(struct node* root,int i){
    if(root==NULL)
    {
        return root;
    }
    if(root->value>i){
        root->left=deletee(root->left,i);
        return root;
    }
    if(root->value<i){
        root->right=deletee(root->right,i);
        return root;
    }
    if(root->left==NULL && root->value==i)
    {
        struct node* temp=root->right;
        free(root);
        return temp;
    }
    if(root->right==NULL && root->value==i)
    {
        struct node* temp=root->left;
        free(root);
        return temp;
    }
    else{
        struct node *sucp=root,*succ=root->right;
        while(succ->left!=NULL)
        {
            sucp=succ;
            succ=succ->left;
        }
        if(sucp!=root){
            sucp->left=succ->right;
        }
        else{
            sucp->right=succ->right;
        }
        root->value=succ->value;
        return root;
    }
}
int pans(struct node* root,int i){
    if(root==NULL){
        return 0;
    }
    if(root->value==i)
    {
        return 1;
    }
    if (pans(root->left,i)||pans(root->right,i))
    {
        printf("\n%d ",root->value);
        return 1;
    }
    return 0;
    
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
void levelorder(struct node*root){
    struct node *queue[100],*curr=root;
    int front=-1,rear=-1;
    queue[++rear]=curr;
    printf("\n");
    while(front!=rear)
    {
        curr=queue[++front];
        printf("%d ",curr->value);
        if(curr->left!=NULL)
        {
            queue[++rear]=curr->left;
        }
        if(curr->right!=NULL)
        {
            queue[++rear]=curr->right;
        }
    
    }
}
int main(){
    struct node *root=NULL;
    create(&root,5);
    create(&root,3);
    create(&root,7);
    create(&root,2);
    create(&root,4);
    create(&root,6);
    inorder(root);
    printf("\n");
    root=deletee(root,5);
    inorder(root);
    printf("\n");
    int i=maxDepth(root);
    printf("%d",i);
    int m=pans(root,2);
    levelorder(root);
    return 0;
}