#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for binary tree node
struct TreeNode {
    char value;
    struct TreeNode* left;
    struct TreeNode* right;
};
void inorder(struct TreeNode *root){
    if(root==NULL)
    {
        printf("Empty");
    }
    else{
        struct TreeNode *current,*stack[100];
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
            printf("%c ",current->value);
            current=current->right;
        } 
    }
}
struct TreeNode* createNode(char value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the binary tree from prefix expression
struct TreeNode* buildTreeHelper(char prefix[], int* index) {
    if (prefix[*index] == '\0') {
        return NULL;
    }

    struct TreeNode* root = createNode(prefix[*index]);
    (*index)++;

    if (!isdigit(root->value)) {
        root->left = buildTreeHelper(prefix, index);
        root->right = buildTreeHelper(prefix, index);
    }

    return root;
}

struct TreeNode* buildTree(char prefix[]) {
    int index = 0;
    return buildTreeHelper(prefix, &index);
}

// Function to evaluate the binary tree
float evaluateTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (isdigit((int)root->value)) {
        return root->value - '0';
    }

    float leftValue = evaluateTree(root->left);
    float rightValue = evaluateTree(root->right);

    switch (root->value) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue;
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

int main() {
    char prefix[100];
    printf("Enter the prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);

    // Remove the newline character
    int i = 0;
    while (prefix[i] != '\n') {
        i++;
    }
    prefix[i] = '\0';
    struct TreeNode* root = buildTree(prefix);
    inorder(root);
    printf("\n");
    float result = evaluateTree(root);

    printf("Result: %.2f\n", result);
    printf("%d",isdigit('3'));
    return 0;
}
