#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for binary tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

// Function to build a binary tree from postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    struct Node* stack[100];
    int top = -1;
    struct Node *t, *t1, *t2;
    int i;
    // Traverse through each character of postfix expression
    for ( i = 0; postfix[i] != '\0'; i++) {
        // If operand, create a new node and push it to stack
        if (!isOperator(postfix[i])) {
            t = createNode(postfix[i]);
            stack[++top] = t;
        } else {
            // If operator, pop two nodes from stack
            t1 = stack[top--];
            t2 = stack[top--];

            // Create a new node with operator as data
            t = createNode(postfix[i]);

            // Make the popped nodes as children of the new node
            t->right = t1;
            t->left = t2;

            // Push the new node to stack
            stack[++top] = t;
        }
    }

    // The final node in stack will be the root of the binary tree
    return stack[top];
}

// Function to evaluate the binary tree
int evaluateExpressionTree(struct Node* root) {
    // If root is NULL, return 0
    if (root == NULL)
        return 0;

    // If leaf node, return the value of the node
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    // Evaluate left and right subtrees recursively
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    // Apply the operator on left and right values
    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
    }
    return 0;
}
void inorder(struct Node *root){
    if(root==NULL)
    {
        printf("Empty");
    }
    else{
        struct Node *current,*stack[100];
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
            printf("%c ",current->data);
            current=current->right;
        } 
    }
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Build the expression tree
    struct Node* root = buildExpressionTree(postfix);
    
    inorder(root);
    printf("\n");
    // Evaluate the expression tree
    int result = evaluateExpressionTree(root);

    printf("Result: %d\n", result);

    return 0;
}
