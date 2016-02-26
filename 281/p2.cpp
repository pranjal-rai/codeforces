//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
vector <long long int> vec1,vec2;
int compare()
{
    long long int l1,l2;
    l1=vec1.size(),l2=vec2.size();
    for(int i=0;i<min(l1,l2);i++)
    {
        if(vec1[i]!=vec2[i])
        {
            if(vec1[i]>vec2[i])
                return 1;
            return -1;
        }
    }
    if(l1>l2)
        return 1;
    if(l2>l1)
        return -1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long int n,i,x,s1=0,s2=0,flag=0;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>x;
        if(x<0)
        {
            vec2.push_back(-1*x);
            flag=0;
            s2+=(-1*x);
        }
        else
        {
            vec1.push_back(x);
            flag=1;
            s1+=(x);
        }
    }
    if(s1==s2)
    {
        int c=compare();
        if(c==1)
            cout<<"first\n";
        else if(c==-1)
            cout <<"second\n";
        else if(flag==0)
            cout <<"second\n";
        else
            cout <<"first\n";
    }
    else if(s1>s2)
        cout <<"first\n";
    else
        cout <<"second\n";
    return 0;
}

