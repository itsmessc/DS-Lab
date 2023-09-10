#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//All functions work 
//Write main accordingly...its messy
int strleng(char *a)
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}
void stringcon(char *a,char *b)
{
    int i,start = strleng(a);
    for(i=0;i<strleng(b);i++)
    {
        a[start+i]=b[i];
    }
    a[start+i]='\0';
    //puts(a);
}
int strcomp(char *a,char *b)
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
void insertstr(char *a,char *b,int pos)
{
    int i,l1=strleng(a),l2=strleng(b);
    for(i=l1;i>=pos-1;i--)
    {
        a[i+l2]=a[i];
    }
    //puts(a);
    for(i=0;i<l2;i++)
    {
        a[pos+i-1]=b[i];
    }
    //a[l1+l2]='\0';
}
void delstr(char *a,char *b)
{
    int l1,l2;
    l1=strleng(a);
    l2=strleng(b);
    char *pos=strstr(a,b);
    if(pos!=NULL)
    {
        while(a[l1-l2]!='\0')
        {
            *pos=*(pos+l2);
            pos++;
        }
    }
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
    puts(s1);
    delstr(s1,s2);
    if(strcomp(s1,s2)==0)
    {
        printf("Entered strings are same");
    }
    else{
        printf("Entered strings are not same\n");
    }
    insertstr(s1,s2,4);
    puts(s1);
    delstr(s1,s2);
    delstr(s1,s2);
    puts(s1);
    return 0;
}
