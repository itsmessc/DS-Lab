#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max 50

char stack[max][max];
int top=-1;
void push(char c[max])
{
    if(top==max-1)
    {
        printf("Stack overflow");
    }
    else{
        strcpy(stack[++top],c);
    }
}
char* pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
        return '\0';
    }
    else{
        return stack[top--];
    }
}
int isoperand(char a)
{
    if((a>='A' && a<='Z')||(a>='a' && a<='z'))
    {
        return 1;
    }
    return 0;
}
int isoperator(char a)
{
    if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^')
        return 1;
    return 0;
}
void convert(char postfix[])
{
    char ch;
    char str[2]={'\0','\0'};
    char infix[max];
    int i=0,j=0;
    while((ch=postfix[i++])!='\0')
    {
        if(isoperand(ch))
        {
            str[0]=ch;
            push(str);
        }
        else if(isoperator(ch))
        {
            str[0]=ch;
            char op1[max],op2[max];
            strcpy(op1,pop());
            strcpy(op2,pop());
            strcpy(infix,"(");
            strcat(infix,op2);
            strcat(infix,str);
            strcat(infix,op1);
            strcat(infix,")");
            push(infix);
        }
        
    }
    puts(stack[top]);

}
int main()
{
    char postfix[max];
    int i;
    do{
        printf("Enter the postfix expression:");
        scanf("%s",postfix);
        convert(postfix);
        printf("\nDo you want to continue(1/0):");
        scanf("%d",&i);
    }while(i==1);
    
    return 0;
}
