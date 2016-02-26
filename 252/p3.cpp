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
    int n,m,k,i,j,counter=1,l,flag=1;
    cin >>n>>m>>k;
    pair <int,int> mp;
    vector < vector<pair<int,int> > > vec(k);
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(j=0;j<m;j++)
            {
                mp=make_pair(i+1,j+1);
                vec[counter-1].PB(mp);
                if(flag%2==0&&counter<k)
                    counter++;
                flag++;
            }
        }
        else
        {
            for(j=m-1;j>=0;j--)
            {
                mp=make_pair(i+1,j+1);
                vec[counter-1].PB(mp);
                if(flag%2==0&&counter<k)
                    counter++;
                flag++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        cout <<vec[i].size()<<" ";
        l=vec[i].size();
        for(j=0;j<l;j++)
            cout <<vec[i][j].first<<" "<<vec[i][j].second<<" ";
        cout <<"\n";
    }
    return 0;
}
