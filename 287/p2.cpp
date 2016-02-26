#include<bits/stdc++.h>
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
using namespace std;
int main()
{
	long long int dist,r,x,y,x1,y1,factor;
	double dist1;
	cin >>r>>x>>y>>x1>>y1;
	dist=(x-x1)*(x-x1)+(y-y1)*(y-y1);
	dist1=sqrt((double)dist);
	factor=dist1/(2*r);
	if(fabs(dist1-(factor*2*r))>0.000001)
	{
		factor+=1;
	}
	cout <<factor<<"\n";
	return 0;
}
