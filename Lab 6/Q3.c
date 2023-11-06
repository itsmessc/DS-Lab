#include<string.h>
#include<stdio.h>
typedef enum{lparan,rparan,plus,minus,times,division,mod,eos,operand} precedence;
/*int isp[]={19,0,12,12,13,13,13,0};
int icp[]={19,20,12,12,13,13,13,0};*/
char s[20][20];
int top=-1, l;
void push(char a[])
{
    if(top==l-1)
        printf("Stack is full\n");
    else
        strcpy(s[++top],a);
}
char *pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return -9999;
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
void posttoinfix(char postfix[])
{
    char temp1[3],temp2[20];
    int n;
    for(n=0;postfix[n]!='\0';n++);
    int i=n-1;
    int op1,op2;
    precedence temp;
    while(i>=0)
    {
        temp=get_token(postfix[i]);
        temp1[0]=postfix[i];
        temp1[1]='\0';
        if(temp==operand)
            push(temp1);
        else
        {
            op1=pop();
            op2=pop();
            strcpy(temp2,"(");
            strcat(temp2,op1);
            strcat(temp2,temp1);
            strcat(temp2,op2);
            strcat(temp2,")");
            push(temp2);
        }
        i--;
    }
        printf("%s",pop());
}

int main()
{
    char c[20];
    printf("Enter the prefix expression\n");
    scanf("%s",c);
    l=strlen(c);
    posttoinfix(c);
}

