#include <stdio.h>
//#include <stdlib.h>

int main()
{
    int n,e,p;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n],i;
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("Enter element to be searched:");
    scanf("%d",&e);
    for(i=0;i<n;i++)
    {
       if(a[i]==e)
        {
            p=i+1;
            break;
        }
    }
    printf("The element in the %d position",p);
    return 0;
}
