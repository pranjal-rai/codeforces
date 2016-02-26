#include<bits/stdc++.h>
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
using namespace std;
int arr[1010][1010];
int main()
{
	int i,n,m,k,j;
	std::ios_base::sync_with_stdio(false);
	cin >>n>>m>>k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			arr[i][j]=0;
		}
	}
	int index=0,l,flag=0;
	for(l=0;l<k;l++)
	{
		cin >>i>>j;
		i=i-1;
		j=j-1;
		arr[i][j]=1;
		if(flag==0)
		{	
			if(j!=(m-1)&&i!=(n-1))
			{
				if(arr[i+1][j]==1&&arr[i][j+1]==1&&arr[i+1][j+1]==1)
				{
					flag=1;
					index=l+1;
				}
			}
			if(j!=0&&i!=(n-1))
			{
				if(arr[i][j-1]==1&&arr[i+1][j-1]==1&&arr[i+1][j]==1)
				{
					flag=1;
					index=l+1;
				}
			}
			if(j!=(m-1)&&i!=0)
			{
				if(arr[i-1][j]==1&&arr[i][j+1]==1&&arr[i-1][j+1]==1)
				{
					flag=1;
					index=l+1;
				}
			}
			if(j!=0&&i!=0)
			{
				if(arr[i-1][j-1]==1&&arr[i][j-1]==1&&arr[i-1][j]==1)
				{
					flag=1;
					index=l+1;
				}
			}
		}
	}
	cout <<index<<"\n";

	return 0;
}
