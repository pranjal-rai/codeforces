#include<bits/stdc++.h>
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(false);
	long long int m,t,r,i,var,min1,max1,flag=1,counter=0;
	vector <long long int> vec;
	cin >>m>>t>>r;
	for(i=0;i<m;i++)
	{
		cin >>var;
		vec.push_back(var);
	}
	min1=vec[0]-r;
	max1=vec[0]-1;
	if(min1+t<vec[0])
	{
		flag=0;
	}
	counter+=r;
	for(i=1;i<m;i++)
	{
		if(vec[i]>(max1+t))
		{
			if((vec[i]-vec[i-1])>=r)
			{
				counter+=r;
			}
			else
			{
				
				flag=0;
				break;
			}
			min1=vec[i]-r;
			max1=vec[i]-1;
		}
		else
		{
			int counter1=counter;
			counter+=(((min1+t-vec[i]))>0?0:min(vec[i]-min1-t));
			if(counter!=counter1&&(vec[i]-min1)<(r-(max1+t-vec[i])))
			{
				flag=0;
				break;
			}
			max1=vec[i]-1;
		}
	}
	if(flag==0)
		cout <<-1<<"\n";
	else
		cout <<counter<<"\n";
	return 0;
}
