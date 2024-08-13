#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int aggressiveLions(vector<int> & ,int);
bool max_alloc(vector<int> & , int , int);
int main()
{
    int n,i,a;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter the data : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    int l;
    cout<<"enter the number of lions : ";
    cin>>l;
    int ans;
    ans = aggressiveLions(arr,l);
    cout<<"the ans is : "<<ans;
    return 0;
}

int aggressiveLions(vector<int> &arr, int l)
{
    sort(arr.begin(),arr.end());
    int s=0,e,maxi;
    maxi =-1;
    int i;
    for(i=0;i<arr.size();i++)
    {
        maxi = max(maxi , arr[i]);
    }
    e= maxi;
    int ans = -1;
    int mid = s+(e-s)/2;
    while(s<=e)
    {
        if(max_alloc(arr,l,mid))
        {
            cout<<"Hello"<<endl;
            ans = mid;
            s =mid+1;
        }
        else
        {
            cout<<"world"<<endl;
            e = mid -1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

bool max_alloc(vector<int> &arr,int l,int mid)
{
    int lioncount  = 1;
    int lastpos = arr[0];
    int i;
    for(i=0;i<arr.size();i++)
    {
        cout<<"ram ram"<<endl;
        if(arr[i] - lastpos >= mid)
        {
            lioncount++;
            if (lioncount == l)
            {
                return true;
            }
            lastpos = arr[i];
        }
    }
    return false;
}