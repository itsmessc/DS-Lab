#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *a,int n)
{
    int i,j,min,temp;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n],i;
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    selectionSort(a,n);
    printf("Elements after sorting:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
