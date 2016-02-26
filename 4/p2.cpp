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
    int d,sumtime,sum=0,a,b,i,flag=1;
    vector <int> vecc;
    pair <int,int> mypair;
    vector <pair<int,int> > vec;
    cin >>d>>sumtime;
    for(i=0;i<d;i++)
    {
        cin >>a>>b;
        mypair.first=a;
        mypair.second=b;
        vec.push_back(mypair);
    }
    for(i=0;i<d;i++)
    {
        vecc.push_back(vec[i].first);
        sum=sum+vec[i].first;
        if(sum>sumtime)
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
        cout <<"NO\n";
    else
    {
        flag=0;
        sumtime=sumtime-sum;
        for(i=0;i<d;i++)
        {
            if(sumtime>(vec[i].second-vec[i].first))
            {
                vecc[i]=vec[i].second;
                sumtime=sumtime-(vec[i].second-vec[i].first);
            }
            else
            {
                vecc[i]+=sumtime;
                sumtime=0;
            }
            if(sumtime==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout <<"NO\n";
        else
        {
            cout <<"YES\n";
            for(i=0;i<d;i++)
                cout <<vecc[i]<<" ";
            cout <<"\n";
        }
    }
    return 0;
}

