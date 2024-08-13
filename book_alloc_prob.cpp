#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool alloc_poss(vector<int> &,int ,int,int);
int bookallocate(vector<int> &,int,int);
int main()
{
    vector<int> arr;
    int a,n,i;
    cout<<"Enter size : ";
    cin>>n;
    cout<<"enter data : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    int ans;
    ans = bookallocate(arr,n,2);
    cout<<"The ans is : "<<ans;
    return 0 ;
}
int bookallocate(vector<int> &arr,int n,int m)
{
    int s= 0;
    int sum=0;
    int i;
    for(i=0;i<n;i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s+(e-s)/2;
    int ans = -1;
    int count =0;
    while(s<=e)
    {
        cout<<"step no."<<count++<<endl;
        if(alloc_poss(arr,n,m,mid))
        {
            ans = mid;
            e  = mid - 1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

bool alloc_poss(vector<int> &arr,int n,int m,int mid)
{
    int pagesum =0;
    int stdcount =1;
    int i;
    for(i=0;i<n;i++)
    {
        if(mid >= pagesum+arr[i])
        {
            pagesum += arr[i];
        }
        else
        {
            stdcount++;
            if(stdcount > m || arr[i] > mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}