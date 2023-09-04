#include <stdio.h>
#include <stdlib.h>

struct time{
    int hour;
    int min;
    int sec;
}t1,t2,t3;
struct time getinfo()
{
    struct time t1;
    printf("Enter Time in format hh:mm:ss:");
    scanf("%d:%d:%d",&t1.hour,&t1.min,&t1.sec);
    return t1;
}
void display(struct time t1)
{
    printf("%d:%d:%d",t1.hour,t1.min,t1.sec);
}
struct time addtime(struct time l,struct time k)
{
    struct time add;
    add.hour=l.hour+k.hour;
    add.min=l.min+k.min;
    add.sec=l.sec+k.sec;
    if(add.sec>=60)
    {
        add.min+=add.sec/60;
        add.sec%=60;
    }
    if(add.min>=60)
    {
        add.hour+=add.min/60;
        add.min%=60;
    }
    return add;
}
struct time removes(struct time t1,struct time t2)
{
    struct time result;
    result.hour=t1.hour-t2.hour;
    result.min=t1.min-t2.min;
    result.sec=t1.sec-t2.sec;
    if(result.sec<0)
    {
        result.min-=1;
        result.sec+=60;
    }
    if(result.min<0)
    {
        result.hour-=1;
        result.min+=60;
    }
    return result;
}
int main()
{
    t1=getinfo();
    t2=getinfo();
    t3=addtime(t1,t2);
    printf("After adding:%d %d %d\n",t3.hour,t3.min,t3.sec);
    t3=removes(t1,t2);
    printf("After subtraction:%d %d %d",t3.hour,t3.min,t3.sec);
    return 0;
}
