#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
long long int num_sqrt(int);
double more_accur(int,int,int);
int main()
{
    int num;
    cout<<"enter the number to sqrt : ";
    cin>>num;
    long long int ans;
    ans = num_sqrt(num);
    cout<<"the sqrt of num is : "<<more_accur(num,10,ans);
    return 0;
}

long long int num_sqrt(int num)
{
    int s=0;
    int e = num;
    long long int mid = s+(e-s)/2;
    long long int ans = -1;
    while(s<=e)
    {
        long long int sq = mid*mid;
        if(sq == num)
        {
            return mid;
        }
        else if(sq < num)
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
double more_accur(int n , int precision , int temp)
{
    double factor = 1;
    int i;
    double j;
    double ans = temp;
    for(i=0;i<precision;i++)
    {
        factor = factor/10;
        for(j=ans;j*j<n;j=j+factor)
        {
            ans = j;
        }
    }
    return ans;
}