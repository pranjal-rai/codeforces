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
int count_max(vector<int> v)
{
    int l=v.size(),counter=0,maxcounter=0,i;
    for(i=0;i<l;i++)
    {
        if(v[i]==1)
            counter++;
        else
        {
            maxcounter=max(counter,maxcounter);
            counter=0;
        }
    }
            maxcounter=max(counter,maxcounter);
            return maxcounter;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,q,i,j,var,k;
    cin >>n>>m>>q;
    vector < vector<int> > vec(n);
    vector <int> dp;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            cin >>var;
            vec[i].push_back(var);
        }
    for(i=0;i<n;i++)
        dp.push_back(count_max(vec[i]));
    for(k=0;k<q;k++)
    {
        cin >>i>>j;
        i--,j--;
        vec[i][j]=1-vec[i][j];
        dp[i]=count_max(vec[i]);
        cout <<*(max_element(dp.begin(),dp.end()))<<"\n";
    }
    return 0;
}
