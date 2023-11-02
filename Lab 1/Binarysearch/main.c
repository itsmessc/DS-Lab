#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,high,low=0;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    high=n-1;
    int a[n],i,p,e,m;
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&e);
    while(low<=high)
    {
        m=(low+high)/2;
        if(a[m]==e)
        {
            p=m+1;
            break;
        }
        else if(e<a[m])
        {
            high=m-1;
        }
        else if(e>a[m])
            low=m+1;
    }
    jj
    printf("The element is present at %d position",p);
    return 0;
}
