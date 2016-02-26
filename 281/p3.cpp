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
    long long int n,i,x,m,l1,l2,a,b,c,d,ans;
    cin >>n;
    vector <long long int> vec1,vec2;
    vector <long long int>::iterator p,q;
    set <long long int> s;
    for(i=0;i<n;i++)
    {
        cin >>x;
        vec1.push_back(x);
        s.insert(x);
    }
    cin >>m;
    for(i=0;i<m;i++)
    {
        cin >>x;
        vec2.push_back(x);
        s.insert(x);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    set <long long int> ::iterator it;
    it=s.begin();
    ans=INT_MIN,c=INT_MIN;
    if((*it)!=0)
    {
        p=upper_bound(vec1.begin(),vec1.end(),0);
        l1=p-vec1.begin();
        q=upper_bound(vec2.begin(),vec2.end(),0);
        l2=q-vec2.begin();
        a=l1*2+(n-l1)*3;
        b=l2*2+(m-l2)*3;
        if((a-b)>=ans)
        {
            if((a-b)==ans){
                if(a>c)
                {
                    c=a;
                    d=b;
                }
            }
            else
            {
                ans=a-b;
                c=a;
                d=b;
            }
        }
    }
    while(it!=s.end())
    {
        p=upper_bound(vec1.begin(),vec1.end(),*it);
        l1=p-vec1.begin();
        q=upper_bound(vec2.begin(),vec2.end(),*it);
        l2=q-vec2.begin();
        a=l1*2+(n-l1)*3;
        b=l2*2+(m-l2)*3;
        if((a-b)>=ans)
        {
            if((a-b)==ans){
                if(a>c)
                {
                    c=a;
                    d=b;
                }
            }
            else
            {
                ans=a-b;
                c=a;
                d=b;
            }
        }
        it++;
    }
    cout<<c<<":"<<d<<"\n";
    return 0;
}
