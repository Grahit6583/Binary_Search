#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int pivot_index(vector<int> &);
main()
{
    int a,i,n;
    vector<int> v;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the data in the array : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    int ans = pivot_index(v);
    if(ans == -1)
    {
        cout<<"no pivot index";
    }
    else
    {
        cout<<"the pivot index is : "<<ans;
    }
    return 0;
}

int pivot_index(vector<int> &v)
{
    int sum=0,i;
    for(i=0;i<v.size();i++)
    {
        sum += v[i];
    }
    int lsum=0,rsum=sum;
    for(i=0;i<v.size();i++)
    {
        rsum =rsum - v[i];
        if(lsum==rsum)
        {
            return i;
        }
        lsum += v[i];
    }
    return -1;
}