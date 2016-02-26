#include<bits/stdc++.h>
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(false);
	string str;
	int l,i,x,y,flag;
	cin >>str;
	l=str.length();
	flag=0;
	for(i=0;i<l;i++)
	{
		x=str[i]-'0';
		if(x%2==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout <<-1<<"\n";
	}
	else
	{
		flag=0;
		y=str[l-1]-'0';
		for(i=0;i<(l-1);i++)
		{
			x=str[i]-'0';
			if(x%2==0&&y>x)
			{
				swap(str[i],str[l-1]);
				flag=1;
				break;
			}
		}
		y=str[l-1]-'0';
		if(flag==0)
		{
			for(i=l-2;i>=0;i--)
			{
				x=str[i]-'0';
				if(x%2==0){
				swap(str[i],str[l-1]);
				break;}
			}
		}
		cout <<str<<"\n";
	}
	return 0;
}
