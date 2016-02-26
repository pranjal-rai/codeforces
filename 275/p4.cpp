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
int n,m,i,l,r,counter,q,j,k,s,sum,p,arr[100010][30];
vector <vector<pair<int,int> > > vec(30),vec1(30);
vector <int> ::iterator it1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>m;
    for(i=0;i<m;i++)
    {
        cin >>l>>r>>q;
        l--,r--;
        counter=0;
        while(counter<30)
        {
            if(q%2==1)
                vec[29-counter].push_back(make_pair(l,r));
            else
                vec1[29-counter].push_back(make_pair(l,r));
            q=q/2;
            counter++;
        }
    }
    for(i=0;i<30;i++)
    {
        sort(vec[i].begin(),vec[i].end());
        sort(vec1[i].begin(),vec1[i].end());
        l=vec[i].size();
        s=-1;
        for(j=0;j<l;j++)
        {
            for(k=max(vec[i][j].F,s);k<=vec[i][j].S;k++)
            {
                arr[k][i]=1;
            }
            s=max(s,vec[i][j].S);
        }
        vector <int> v;
        for(j=0;j<n;j++)
        {
            if(arr[j][i]==0)
                v.PB(j);
        }
        l=vec1[i].size();
        for(j=0;j<l;j++)
        {
            it1=lower_bound(v.begin(),v.end(),vec1[i][j].F);
            if((it1!=v.end())&&(*it1)<=vec1[i][j].S)
                continue;
            else
            {
                cout <<"NO\n";
                return 0;
            }
        }
    }
    cout <<"YES\n";
    for(i=0;i<n;i++)
    {
        sum=0,p=1;
        for(j=29;j>=0;j--)
        {
            sum=sum+arr[i][j]*p;
            p=p*2;
        }
        cout <<sum<<" ";
    }
    cout <<"\n";
    return 0;
}
