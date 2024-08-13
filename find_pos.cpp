// find position in rotated sorted array
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int find_pivot(vector <int> &,int);
int binary_search(vector<int> &,int,int,int);
int find_position(vector<int> &,int,int);
int main()
{
    int i,n,a;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter the data in the vector : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    int ans = find_position(arr,n,3);
    cout<<"ans is : "<<ans;
    return 0;
}

int find_pivot(vector<int> &arr,int n)
{
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;
    while(s<e)
    {
        if(arr[mid] >= arr[0])
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

int binary_search(vector<int> &arr, int s, int e, int target)
{
    int start = s;
    int end = e;
    int mid = start+(end-start)/2;
    while(s<=e)
    {
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return -1;
}

int find_position(vector<int> &arr , int n , int target)
{
    int pivot = find_pivot(arr,n);
    if(arr[pivot] <= target && target <= arr[n-1])
    {
        return binary_search(arr,pivot,n-1,target);
    }
    else
    {
        return binary_search(arr,0,pivot-1,target);
    }
}