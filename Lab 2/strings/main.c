#include <stdio.h>
#include <stdlib.h>

int strleng(char a[20])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}
void stringcon(char b[20],char c[20])
{
    char a[50];
    int i,l1,l2;
    l1=strlen(b);
    l2=strleng(c);
    for(i=0;i<l1;i++)
    {
        a[i]=b[i];
    }
    for(i=0;i<l2;i++)
    {
        a[l1+i]=c[i];
    }
    a[l1+l2]='\0';
    printf("Concatenated string:%s\n",a);
}
int strcomp(char a[20],char b[20])
{
    int i,j;
    for(i=0,j=0;i<strleng(a),j<strleng(b);i++,j++)
    {
        if(a[i]!=b[j])
        {
            return a[i]-b[j];
        }
    }
    return 0;
}
int main()
{
    char s1[20],s2[20];
    int l1,l2,c;
    printf("Enter String 1:");
    scanf("%s",&s1);
    printf("Enter String 2:");
    scanf("%s",&s2);
    l1=strleng(s1);
    l2=strleng(s2);
    printf("Length of the string 1:%d\n",l1);
    printf("Length of the string 2:%d\n",l2);
    stringcon(s1,s2);
    if(strcomp(s1,s2)==0)
    {
        printf("Entered strings are same");
    }
    else{
        printf("Entered strings are not same");
    }
    return 0;
}
