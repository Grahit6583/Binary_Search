#include<iostream>
#include<conio.h>
using namespace std;
int find_pivot(int [],int);
int main()
{
    int n,i;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the data in the array : "<<endl;;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans = find_pivot(arr,n);
    cout<<"ans is : "<<ans ;
}

int find_pivot(int arr[],int n)
{
    int s =0;
    int e = n-1;
    int mid = s+(e-s)/2;
    while(s<e)
    {
        if(arr[mid]>= arr[0])
        {
            s = mid+1;
        }
        else
        {
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}