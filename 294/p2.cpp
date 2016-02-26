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
    std::vector<long long int>::iterator low,up,low1,up1;
    long long int n,i,x,var,f1,f2;
    vector <long long int> vec1;
    vector <long long int> vec2;
    vector <long long int> vec3;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec1.push_back(var);
    }
    for(i=0;i<(n-1);i++)
    {
        cin >>var;
        vec2.push_back(var);
    }
    for(i=0;i<(n-2);i++)
    {
        cin >>var;
        vec3.push_back(var);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    sort(vec3.begin(),vec3.end());
    for(i=0;i<n;i++)
    {
        x=vec1[i];
        low1=lower_bound(vec1.begin(),vec1.end(),x);
        up1=upper_bound(vec1.begin(),vec1.end(),x);
        low=lower_bound(vec2.begin(),vec2.end(),x);
        up=upper_bound(vec2.begin(),vec2.end(),x);
        f1=(up1-vec1.begin())-(low1-vec1.begin());
        f2=(up-vec2.begin())-(low-vec2.begin());
        if(f1>f2)
        {
            cout <<x<<"\n";
            break;
        }
    }
    for(i=0;i<(n-1);i++)
    {
        x=vec2[i];
        low1=lower_bound(vec2.begin(),vec2.end(),x);
        up1=upper_bound(vec2.begin(),vec2.end(),x);
        low=lower_bound(vec3.begin(),vec3.end(),x);
        up=upper_bound(vec3.begin(),vec3.end(),x);
        f1=(up1-vec2.begin())-(low1-vec2.begin());
        f2=(up-vec3.begin())-(low-vec3.begin());
        if(f1>f2)
        {
            cout <<x<<"\n";
            break;
        }
    }
    return 0;
}

