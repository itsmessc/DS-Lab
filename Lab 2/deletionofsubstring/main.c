#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[20],s2[20],k;
    int i,j,l1,l2;
    printf("Enter String:");
    gets(s1);
    printf("Enter substring:");
    gets(s2);
    l1=strlen(s1);
    l2=strlen(s2);
    char *pos=strstr(s1,s2);
    if(pos!=NULL)
    {
        while(s1[l1-l2]!='\0')
        {
            *pos=*(pos+l2);
            *pos++;
        }
    }
    printf("New string is:%s",s1);
    return 0;
}
