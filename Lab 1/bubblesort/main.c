#include <stdio.h>
#include <stdlib.h>
int a[30];

void bubbleSort(int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n,i;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubbleSort(n);
    printf("Elements after sorting are:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    
    return 0;
}
