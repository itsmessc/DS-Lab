#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *a,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0 && temp<=a[j];j--)
        {
            if(temp<=a[j])
            {
                a[j+1]=a[j];
            }
        }
        a[j+1]=temp;
    }
}
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n],i,j,temp;
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    insertionSort(a,n);
    printf("Array after sorting:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
