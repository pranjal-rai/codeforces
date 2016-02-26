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
    LL n,i,x,y,a,b,l1,l2,count1,count2,flag;
    vector <pair<LL,LL> > v1,v2;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>x>>y;
        if(x>0)
        v1.PB(MP(x,y));
        else
        v2.PB(MP(x,y));
    }
    sort(v1.begin(),v1.end());
    sort(v2.rbegin(),v2.rend());
    l1=v1.size();
    l2=v2.size();
    a=0;
    count1=0,count2=0,flag=0;
    while(1)
    {
        if(flag==0)
        {
            if(count1<l1)
            {
                a=a+v1[count1].S;
                count1++;
                flag=1;
            }
            else
                break;
        }
        else
        {
            if(count2<l2)
            {
                a=a+v2[count2].S;
                count2++;
                flag=0;
            }
            else
                break;
        }
    }
    flag=1;
    b=0;
    count1=0,count2=0;
    while(1)
    {
        if(flag==0)
        {
            if(count1<l1)
            {
                b=b+v1[count1].S;
                count1++;
                flag=1;
            }
            else
                break;
        }
        else
        {
            if(count2<l2)
            {
                b=b+v2[count2].S;
                count2++;
                flag=0;
            }
            else
                break;
        }
    }
    cout <<max(a,b)<<"\n";
    return 0;
}

