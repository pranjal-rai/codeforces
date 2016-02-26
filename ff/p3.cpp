#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100000],dp[100000]={0},dpx[100000]={0};
    int i,maximum,x,n;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>arr[i];
    }
    dp[0]=1;
    x=0;
    maximum=1;
    for(i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            dpx[x]++;
            dp[i]=dp[i-1]+1;
        }
        else
        {
            dp[i]=1;
            x=i;
            dpx[x]=1;
        }
        maximum=max(maximum,dp[i]);
    }
    for(i=0;i<n;i++)
    {
        if(i!=0&&i!=(n-1))
        {
            if(arr[i]<=arr[i-1])
            {
                maximum=max(maximum,dp[i-1]+1);
            }
            if(arr[i]>=arr[i+1])
            {
                maximum=max(maximum,dpx[i+1]+1);
            }
            if(arr[i+1]>=(arr[i-1]+2))
            {
                if(arr[i]>arr[i-1]&&arr[i]<arr[i+1])
                {
                }
                else if(arr[i]>arr[i-1])
                {
                    maximum=max(maximum,dp[i]+dpx[i+1]);
                }
                else if(arr[i]<arr[i+1])
                {
                    maximum=max(maximum,dp[i-1]+dpx[i]);
                }
            }
        }
        else if(i==0)
        {
            if(arr[i]>=arr[i+1])
            {
                maximum=max(maximum,dpx[i+1]+1);
            }
        }
        else if(i==(n-1))
        {
            if(arr[i]<=arr[i-1])
            {
                maximum=max(maximum,dp[i-1]+1);
            }
        }
    }
    cout <<maximum<<"\n";
    return 0;
}
