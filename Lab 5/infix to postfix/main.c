#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max 50
char stack[max];
int top=-1;
void push(char a)
{
    if(top==max-1)
    {
        printf("Stack overflow");
    }
    else{
        stack[++top]=a;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else{
        return stack[top];
        top--;
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
int precednece(char a)
{
    if(a=='+' || a=='-')
        return 1;
    else if(a=='*' || a=='/')
        return 2;
    else if(a=='^')
        return 3;
    return 0;
}
void prefixer(char infix[])
{
    char ch;
    char postfix[max];
    //char* postfix = (char*)malloc(sizeof(char) * (strlen(infix) + 2));
    int i=0,j=0;
    push('(');
    strcat(infix,")");
    while((ch=infix[i++])!='\0')
    {
        if(ch==' ')
            continue;
        else if(ch=='(')
        {
            push(ch);
        }
        else if(isoperand(ch))
        {
            postfix[j++]=ch;
        }

        else if(ch==')')
        {
            while (top > -1 && stack[top] != '(')
				postfix[j++] = stack[top--];
            top--;
        }
        else if(isoperator(ch))
        {
            while(top!=-1 && ( precednece(ch)<=precednece(stack[top])))
                {

                    postfix[j++]=stack[top--];
                }
            push(ch);

        }
    }
    /*while(top!=-1/* && ( stack[top]!='('))
                {

                    postfix[j++]=stack[top--];
                }*/
    postfix[j]='\0';
    printf("%s\n",postfix);
}
int main()
{
    int t;
    char infix[100];
    do
    {
        printf("Enter infix expression:");
        scanf("%s",&infix);
        prefixer(infix);
        printf("1.Another expression\n2.exit\n");
        scanf("%d",&t);
    }while(t==1);
    return 0;
}
