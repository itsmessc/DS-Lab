#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    printf("Enter order of matrices in form nxm:");
    scanf("%dx%d",&n,&m);
    int a[n][m],b[n][m],i,j,c[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter element (%d,%d) of A matrix:",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter element (%d,%d) of B matrix:",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            c[i][j]=(a[i][j]>b[i][j])?a[i][j]:b[i][j];
        }
    }
    printf("Elements in matrix C are:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
