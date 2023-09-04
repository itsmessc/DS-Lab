#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    char s1[20],s2[20];
    int l1,l2,i,pos;
    printf("Enter String:");
    gets(s1);
    printf("Enter substring:");
    gets(s2);
    printf("Enter position to enter a substring:");
    scanf("%d",&pos);
    l1=strlen(s1);
    l2=strlen(s2);
    for(i=l2-1;i>=0;i--)
    {
        for(int j=l1;j>=pos-1;j--)
        {
            s1[j+1]=s1[j];
        }
        s1[pos-1]=s2[i];
        l1++;
    }
    printf("Final String:%s",s1);
    return 0;
}
