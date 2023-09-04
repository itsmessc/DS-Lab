#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define Max 100

int top=-1;
char stack[Max];
void push(char a)
{
    if(top==Max-1)
    {
        printf("Stack overflow");
    }
    else{
        stack[++top]=a;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else{
        printf("Popped element:%d",stack[top]);
        top--;
    }
}
int main()
{
    int n;
    char s[100],b;
    while(1)
    {
        printf("1.Check number for palindrome\n2.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter number to check plaindrome:");
                scanf("%s",&s);
                for(int i=strlen(s)-1;i>=0;i--)
                {
                    b=s[i];
                    push(b);
                }
                if(strcmp(s,stack)==0)
                {
                    printf("Entered number is plaindrome\n");
                }
                else
                {
                    printf("Entered number is not plaindrome\n");
                }
                break;
            case 2:
                exit(0);
        }
    }
}

