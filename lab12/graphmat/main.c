#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    do{
        int i,j;
        printf("1.add\n2.stop adding\n");
        scanf("%d",&m);
        if(m==1)
        {
            printf("Enter index:");
            scanf("%d %d",&i,&j);
            a[i][j]=1;
        }
    }while(m!=2);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
