#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max 50

char stack[max];
int top=-1;

void convert(char postfix[])
{
    char infix[max];
    strrev(postfix);
    char a;
    int i=0,j=0,l=strlen(postfix);
    for(i=0;i<l;i++)
    {
        a=postfix[i];
        if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^')
        {
            stack[++top]=a;
        }
        else
        {
            infix[j++]=a;
            infix[j++]=stack[top--];
        }
    }
    /*while((ch=postfix[i++])!='\0')
    {
        if((ch>='A' && ch<='Z')|| (ch>='a'&&ch<='z'))
        {
            stack[++top]=ch;
        }
        else
        {
            char op2=stack[top--];
            char op1=stack[top--];
            infix[j++]='(';
            infix[j++]=op1;
            infix[j++]=ch;
            infix[j++]=op2;
            infix[j++]=')';
        }
    }*/
    infix[j]='\0';
    strrev(infix);
    printf("Infix expression:%s",infix);
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
