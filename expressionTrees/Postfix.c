#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char value;
    struct Node* left;
    struct Node* right;
};

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void postfixTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postfixTraversal(root->left);
    postfixTraversal(root->right);
    printf("%c", root->value);
}
struct Node* buildTree(char infix[],int s,int e)
{
    if(s>e)
    return NULL;
    int minp=999,mini=-1,pcount=0;
    for(int i=s;i<=e;i++)
    {
        if(infix[i]=='(')
        pcount++;
        else if(infix[i]==')')
        pcount--;
        else if(isOperator(infix[i]) && pcount==0)
        {
            int prec;
            if(infix[i]=='+' || infix[i]=='-')
            prec=1;
            else
            prec=2;
            if(prec<=minp)
            {
                minp=prec;
                mini=i;
            }
        }
    }

    if (mini == -1) {
            return createNode(infix[s]);
    }
    struct Node *newnode=createNode(infix[mini]);
    newnode->left=buildTree(infix,s,mini-1);
    newnode->right=buildTree(infix,mini+1,e);
    return newnode;
}
int main() {
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    struct Node* root = buildTree(infix, 0, strlen(infix) - 1);

    printf("Postfix expression: ");
    postfixTraversal(root);

    return 0;
}