#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 50
double stack[max];
int top=-1;
void push(double a)
{
    if(top==max-1)
    {
        printf("Stack overflow");
    }
    else{
        stack[++top]=a;
    }
}
double pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
        return -1;
    }
    else{
        return stack[top];
        top--;
    }
}
int num(char a)
{
    if(a>='0' && a<='9')
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
void posteva(char postfix[])
{
    //puts(postfix);
    int i=0;
    double op1,op2,result;
    char s;
    while((s=postfix[i++])!='\0')
    {
        if(num(s))
        {
            int i=s-'0';
            push(i);
            //printf("%c",s);
        }
        else if(isoperator(s))
        {
            op2=stack[top--];
            op1=stack[top--];
            //printf("%d",op1);
            //printf("%d",op2);
            switch(s)
            {
            case '+':
                result=op1+op2;break;
            case '-':
                result=op1-op2;break;
            case '*':
                result=op1*op2;break;
            case '/':
                result=(op1/op2)*1.0;break;
            case '^':
                result=pow(op2,op1);break;

            }
            push(result);
        }
    }
    printf("%f\n",result);
}
int main()
{
    char postfix[50];
    int i;
    do
    {
        printf("Enter postfix expression:");
        scanf("%s",&postfix);
        posteva(postfix);
        printf("1.Another expression\n2.exit\n");
        scanf("%d",&i);
    }while(i==1);
    return 0;
}
