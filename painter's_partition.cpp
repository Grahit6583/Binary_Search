#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
bool alloc_poss(vector<int> & , int , int ,int);
int alloc_board(vector<int> & , int , int);
int main()
{
    int n,i,a,k;
    system("CLS");
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter the data in array : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    cout<<"Enter the no. of painters : "<<endl;
    cin>>k;
    int ans;
    ans = alloc_board(arr,n,k);
    cout<<"The ans is : "<<ans;
    return 0;
}

int alloc_board(vector<int> &arr ,int n ,int m)
{
    int sum,i;
    for(i=0;i<n;i++)
    {
        sum = sum + arr[i];
    }
    int s=0;
    int e = sum;
    int mid  = s+(e-s)/2;
    int ans = -1;
    while(s<=e)
    {
        if(alloc_poss(arr,n,m,mid))
        {
            ans = mid;
            e  = mid-1;
        }
        else
        {
            s  =mid+1;
        }
        mid = s+(e-s)/2;
    }
}

bool alloc_poss(vector<int> &arr , int n , int m , int mid)
{
    int boardsum =0 ;
    int painterCount = 1;
    int i;
    for(i=0;i<n;i++)
    {
        if(mid >= boardsum + arr[i])
        {
            boardsum += arr[i];
        }
        else{
            painterCount++;
            if(painterCount > m || arr[i] > mid)
            {
                return false;
            }
            boardsum = arr[i];
        }
    }
    return true;
}