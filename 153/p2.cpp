//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
int n;
vector <int> vec;
vector <int> vec1;
int ascending()
{
    for(int i=1;i<n;i++)
    {
        if(vec[i]<vec[i-1])
            return 0;
    }
    return 1;
}
int descending()
{
    for(int i=1;i<n;i++)
    {
        if(vec[i]>vec[i-1])
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    int i,j,var,flag;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec.push_back(var);
        vec1.push_back(var);
    }
    sort(vec1.begin(),vec1.end());
    flag=0;
    if(vec1[0]!=vec1[n-1])
        flag=1;
    if(flag==0||n==1||n==2)
    {
        cout <<-1<<"\n";
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(vec[i]!=vec[j])
                {
                    swap(vec[i],vec[j]);
                    if(ascending()==0&&descending()==0)
                    {
                        cout <<i+1<<" "<<j+1<<"\n";
                        flag=0;
                        break;
                    }
                    swap(vec[i],vec[j]);
                }
            }
            if(flag==0)
                break;
        }
        if(flag==1)
            cout <<-1<<"\n";
    }
    return 0;
}

