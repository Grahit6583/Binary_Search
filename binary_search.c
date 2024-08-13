#include<stdio.h>
#include<conio.h>
int binary_search(int [],int,int);
int main()
{
    int n,k,i,result;
    printf("Enter the elements :\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the data in array :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nEnter item to search :\n");
    scanf("%d",&k);
    result = binary_search(a,n,k);
    if(result == -1)
    {
        printf("element not found");
    }
    else
    {
        printf("Element found at index %d",result);
    }
    return 0;
}
int binary_search(int a[],int n,int k)
{
    int mid,l = 0,r = n-1;
    while(l<r)
    {
        mid = (l+r)/2;
        if(a[mid]==k)
        {
            return mid;
        }
        else if(a[mid]>k)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}