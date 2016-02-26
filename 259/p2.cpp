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
    int n,i,var,mini,index,flag=1;
    vector <int> vec,vec1;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec.push_back(var);
    }
    mini=INT_MAX;
    for(i=n-1;i>=0;i--)
    {
        mini=min(mini,vec[i]);
        if(vec[i]>mini)
            break;
        index=i;
    }
    for(i=index;i<n;i++)
        vec1.push_back(vec[i]);
    for(i=0;i<index;i++)
        vec1.push_back(vec[i]);
    sort(vec.begin(),vec.end());
    for(i=0;i<n;i++)
    {
        if(vec[i]!=vec1[i])
            flag=0;
    }
    if(flag==0)
        cout <<-1<<"\n";
    else if(index!=0)
        cout <<n-index<<"\n";
    else
        cout <<0<<"\n";
}
