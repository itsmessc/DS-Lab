#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int a[100];
    int top;
};
void initialize(struct Stack *stack)
{
    stack->top=-1;
}
void push(struct Stack *stack,int b)
{
    if(stack->top==99)
    {
        printf("Stack overflow");
        return;
    }
    stack->a[++stack->top]=b;

}
void pop(struct Stack *stack)
{
    if(stack->top==-1)
    {
        printf("Stack underflow");
        return;
    }
    printf("%d",stack->a[stack->top]);
    stack->top--;
}
int peek(struct Stack *stack)
{
    if(stack->top==-1)
    {
        printf("Stack underflow");
        exit(0);
    }
    return stack->a[stack->top];
}
int main()
{
    struct Stack stack;
    initialize(&stack);
    int n,m,x;
    printf("Enter number:");
    scanf("%d",&n);
    printf("1.Binary\n2.Octal\n3.Hexa\n");
    scanf("%d",&m);
    switch(m)
    {
        case 1:
            while(n>0)
            {
                push(&stack,n%2);
                n=n/2;
            }
            while(stack.top!=-1)
            {
                pop(&stack);

            }
            break;
        case 2:
            while(n>0)
            {
                push(&stack,n%8);
                n=n/8;
            }
            while(stack.top!=-1)
            {
                pop(&stack);
            }
            break;
        case 3:
            initialize(&stack);
            while(n>0)
            {
                x=n%16;
                if(x>=10 && x<=15)
                {
                    char ch='A'+(x%10);
                    push(&stack,ch);
                }
                else
                {
                    push(&stack,x);
                }
                n/=16;
            }
            while(stack.top!=-1)
            {
                if(peek(&stack)>='A' && peek(&stack)<='F')
                {
                    char ch=peek(&stack);
                    printf("%c",ch);
                    stack.top--;
                }
                else
                {
                    printf("%d",stack.a[stack.top]);
                    stack.top--;
                }
            }
    }

    return 0;
}
