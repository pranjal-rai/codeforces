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
    long long int d,n,l,r,x,i,var,p,j,counter,counter1,y,arr[20],ans=0,minimum,maximum,sum;
    vector <long long int> vec;
    cin >>n>>l>>r>>x;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec.push_back(var);
    }
    sort(vec.begin(),vec.end());
    p=1;
    for(i=1;i<=n;i++)
        p=p*2;
    for(i=0;i<p;i++)
    {
        counter=n,counter1=0,y=0,d=i;
        while(counter!=0)
        {
            arr[y]=d%2;
            d=d/2;
            counter--;
            if(arr[y]==1)
                counter1++;
            y++;
        }
        if(counter1>1)
        {
            sum=0,minimum=INT_MAX,maximum=INT_MIN;
            for(j=0;j<n;j++)
            {
                if(arr[j]==1)
                {
                    minimum=min(minimum,vec[j]);
                    maximum=max(maximum,vec[j]);
                    sum=sum+vec[j];
                }
            }
            if(sum>=l&&sum<=r&&(maximum-minimum)>=x)
                ans++;
        }
    }
    cout <<ans<<"\n";
    return 0;
}

