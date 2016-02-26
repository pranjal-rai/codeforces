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
    long long int n,d,i,var,counter,m;
    vector <long long int > vec;
    std::vector<long long int>::iterator up;
    cin >>n>>d;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec.push_back(var);
    }
    sort(vec.begin(),vec.end());
    counter=0;
    for(i=0;i<n;i++)
    {
        up=upper_bound(vec.begin()+i,vec.end(),vec[i]+d);
        if(up==vec.end())
        {
            m=n-i-1;
            counter+=(m*(m-1))/2;
        }
        else
        {
            m=(up-vec.begin()-1)-i;
//            cout <<i<<" "<<*up<<" "<<m<<"\n";
            if(m>=1)
            counter+=(m*(m-1))/2;
        }
    }
    cout <<counter<<"\n";
    return 0;
}

