//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k,p,i,j,var,count_odd=0,count_even=0,s;
    vector <int> veco,vece;
    cin >>n>>k>>p;
    vector <vector<int> > v(k);
    for(i=0;i<n;i++)
    {
        cin >>var;
        if(var%2==0)
        {
            vece.PB(var);
            count_even++;
        }
        else
        {
            veco.PB(var);
            count_odd++;
        }
    }
    if(count_odd<(k-p)||(count_odd-(k-p))%2!=0)
    {       
        cout <<"NO\n";
        return 0;
    }
    for(i=0;i<(k-p);i++)
        v[i].PB(veco[i]);
    s=i;
    for(;i<k&&s<count_odd;i++,s=s+2)
    {
        v[i].PB(veco[s]);
        v[i].PB(veco[s+1]);
    }
    if(s<count_odd)
    {
        for(;s<count_odd;s=s+2)
        {
            v[0].PB(veco[s]);
            v[0].PB(veco[s+1]);
        }
        s=0;
        while(s<count_even)
        {
            v[0].PB(vece[s]);
            s++;
        }
    }
    else 
    {
        for(s=0;i<k&&s<count_even;s++,i++)
            v[i].PB(vece[s]);
        if(i!=k)
        {
            cout <<"NO\n";
            return 0;
        }
        else
        {
            while(s<count_even)
            {
                v[0].PB(vece[s]);
                s++;
            }
        }
    }
    cout <<"YES\n";
    for(i=0;i<k;i++)
    {
        cout <<v[i].size()<<" ";
        for(j=0;j<v[i].size();j++)
        {
            cout <<v[i][j]<<" ";
        }
        cout <<"\n";
    }
    return 0;
}
