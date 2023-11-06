#include<string.h>
#include<stdio.h>
typedef enum{lparan,rparan,plus,minus,times,division,mod,eos,operand} precedence;
char s[20];
int top=-1,l;
/*int isp[]={19,0,12,12,13,13,13,0};
int icp[]={19,20,12,12,13,13,13,0};*/
void push(char a)
{
    if(top==l-1)
        printf("Stack is full\n");
    else
        s[++top]=a;
}
char pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return(-9999);
    }
    else
        return(s[top--]);
}
precedence get_token(char c)
{
    switch(c)
    {
        case '#':return eos;
        case '(':return lparan;
        case ')':return rparan;
        case '+':return plus;
        case '-':return minus;
        case '*':return times;
        case '/':return division;
        case '%':return mod;
        default: return operand;
    }
}
void postfix_eval(char postfix[])
{
    int n;
    for(n=0;postfix[n]!='\0';n++);
    int i=n-1,op1,op2;
    precedence temp;
    while(i>=0)
    {
        temp=get_token(postfix[i]);
        if(temp==operand)
            push(postfix[i]-'0');
        else
        {
            op1=pop();
            op2=pop();
            switch(postfix[i])
            {
                case '+':push(op1+op2); break;
                case '-':push(op1-op2); break;
                case '*':push(op1*op2); break;
                case '/':push(op1/op2); break;
                case '%':push(op1%op2); break;
                default: printf("Invalid operator");
            }
        }
        i--;
    }
    printf("Result= %d",pop());
}

int main()
{
    char c[20];
    printf("Enter the prefix expre ssion\n");
    gets(c);
    l=strlen(c);
    postfix_eval(c);
}

