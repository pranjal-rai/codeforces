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
    int mmass,i,n,x,t,h,m,j,y,counter1=0,counter2=0,index,l1,l2;
    pair <int,int> mp;
    vector <pair<int,int> > veca,vecb;
    cin >>n>>x;
    for(i=0;i<n;i++)
    {
        cin >>t>>h>>m;
        mp=make_pair(h,m);
        if(t==0)
            veca.PB(mp);
        else
            vecb.PB(mp);
    }
    sort(veca.begin(),veca.end());
    sort(vecb.begin(),vecb.end());
    l1=veca.size();
    l2=vecb.size();
    vector <int> flag1(l1,0),flag2(l2,0);
    y=x;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            index=-1;
            mmass=-1;
            for(j=0;j<l1;j++)
            {
                if((veca[j].first)<=x&&flag1[j]==0&&veca[j].second>mmass){
                    index=j;
                    mmass=veca[j].second;
                }
            }
            if(index==-1)
                break;
            counter1++;
            x=x+veca[index].second;
            flag1[index]=1;
        }
        else
        {
            index=-1;
            mmass=-1;
            for(j=0;j<l2;j++)
            {
                if((vecb[j].first)<=x&&flag2[j]==0&&vecb[j].second>mmass){
                    index=j;
                    mmass=vecb[j].second;
                }
            }
            if(index==-1)
                break;
            counter1++;
            x=x+vecb[index].second;
            flag2[index]=1;
        }
    }
    x=y;
    for(i=0;i<l1;i++)
        flag1[i]=0;
    for(i=0;i<l2;i++)
        flag2[i]=0;
    for(i=0;i<n;i++)
    {
        if(i%2==1)
        {
            index=-1;
            mmass=-1;
            for(j=0;j<l1;j++)
            {
                if((veca[j].first)<=x&&flag1[j]==0&&veca[j].second>mmass){
                    index=j;
                    mmass=veca[j].second;
                }
            }
            if(index==-1)
                break;
            counter2++;
            x=x+veca[index].second;
            flag1[index]=1;
        }
        else
        {
            index=-1;
            mmass=-1;
            for(j=0;j<l2;j++)
            {
                if((vecb[j].first)<=x&&flag2[j]==0&&vecb[j].second>mmass){
                    index=j;
                    mmass=vecb[j].second;
                }
            }
            if(index==-1)
                break;
            counter2++;
            x=x+vecb[index].second;
            flag2[index]=1;
        }
    }
    cout <<max(counter1,counter2)<<"\n";
    return 0;
}
