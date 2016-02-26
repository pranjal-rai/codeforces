#include<bits/stdc++.h>
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
using namespace std;
int main()
{
	long long int h,n,x,n1,i,y,flag,counter;
	long long int arr[100]={0};
	cin >>h>>n;
	x=h-1,n1=n-1;
	for(i=0;i<h;i++)
	{
		arr[x]=n1%2;
		n1=n1/2;
		x--;
	}
	counter=1;
	y=(long long int)pow(2,h);
	flag=0;
	for(i=0;i<h;i++)
	{
		if(i!=0)
		{
			if(arr[i-1]==0)
				flag=1;
			else
				flag=0;
		}

		if(arr[i]==1)
		{
			if(flag==0)
			{
				x=y;
				while(x!=0)
				{
					counter+=x/2;
					x=x/2;
				}
		counter+=1;
			}
			else
			{
				counter+=1;
			}
		}
		else
		{
			if(flag==0)
			{
				counter+=1;
			}
			else
			{
				x=y;
				while(x!=0)
				{
					counter+=x/2;
					x=x/2;
				}
		counter+=1;
			}
		}
		y=y/2;
	}
	cout <<counter-1<<"\n";
	return 0;
}
