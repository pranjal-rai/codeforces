#include<bits/stdc++.h>
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
using namespace std;
int main()
{	
	int i,n,k,var,counter=0,arr[100000];
	cin >>n>>k;
	vector <pair<int,int > > vec;
	pair <int,int> mypair;
	for(i=0;i<n;i++)
	{
		cin >>var;
		mypair.first=var;
		mypair.second=i+1;
		vec.push_back(mypair);
	}
	sort(vec.begin(),vec.end());
	for(i=0;i<n;i++)
	{
		if(vec[i].first<=k)
		{
			k=k-vec[i].first;
			arr[counter]=vec[i].second;
			counter++;
		}
	}
	cout <<counter<<"\n";
	for(i=0;i<counter;i++)
	{
		cout <<arr[i]<<" ";
	}
	if(counter!=0)
	cout <<"\n";
			return 0;
}
