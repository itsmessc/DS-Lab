#include <stdio.h>
#include <stdlib.h>

struct student{
    char name[30];
    int rollno;
    int grade;
}s[40],temp,*ptr;
struct student getinfo()
{
    struct student s1;
    printf("Enter name:");
    scanf("%s",&s1.name);
    printf("Enter Rollno and Grade:");
    scanf("%d %d",&s1.rollno,&s1.grade);
    return s1;
}
void display(struct student s1)
{
    printf("Roll no:%d Name:%s Grade:%d\n",s1.rollno,s1.name,s1.grade);
}
void sorting(struct student *lol,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if((*(lol+j)).rollno>(*(lol+j+1)).rollno)
            {
                temp=*(lol+j);
                *(lol+j)=*(lol+j+1);
                *(lol+j+1)=temp;
            }
        }
    }
}
int main()
{
    int i,n,j;
    printf("Enter Number of students:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter details of student %d:\n",i+1);
        s[i]=getinfo();
    }
    ptr=&s[0];
    sorting(ptr,n);
    for(i=0;i<n;i++)
    {
        display(s[i]);
    }
    return 0;
}
