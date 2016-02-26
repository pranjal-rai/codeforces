//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int l,n,k,p,x,y,var,i,sum=0;
    vector <int> vec,vec1;
    vector <int> ::iterator it;
    cin >>n>>k>>p>>x>>y;
    for(i=0;i<k;i++)
    {
        cin >>var;
        vec.push_back(var);
    }
    sort(vec.begin(),vec.end());
    for(i=1;i<=(n-k);i++)
    {
        vec.push_back(1);
        vec1.push_back(1);
    }
    sort(vec.begin(),vec.end());
    for(i=0;i<(n-k);i++)
        sum+=vec[i];
    if(sum>x)
    {
        cout <<"-1\n";
        return 0;
    }
    if(vec[n/2]<y)
    {
        it=lower_bound(vec.begin(),vec.end(),y);
        l=it-vec.begin()-n/2;
        if(l>(n-k))
        {
            cout <<"-1\n";
            return 0;
        }
        for(i=0;i<l;i++)
        {
            vec[i]=y;
            vec1[i]=y;
        }
    }
    sum=0;
    l=vec1.size();
    sort(vec1.rbegin(),vec1.rend());
    for(i=0;i<n;i++)
    {
        sum+=vec[i];
    }
    if(sum>x)
    {
        cout <<"-1\n";
        return 0;
    }
    for(i=0;i<l;i++)
        cout <<vec1[i]<<" ";
    cout <<"\n";
    return 0;
}
