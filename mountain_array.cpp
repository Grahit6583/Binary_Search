#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int mount_array(vector<int> &v);
int main()
{
    int n,a,i;
    vector<int> v;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the data in the array : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    int ans = mount_array(v);
    cout<<"the peak index is : "<<ans;
    return 0;
}

int mount_array(vector<int> &v)
{
    int s=0,e=v.size()-1;
    int mid=s+(e-s)/2;
    for(s=0;s<e;)
    {
        if(v[mid]<v[mid+1])
        {
            s = mid+1;
        }
        else
        {
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}