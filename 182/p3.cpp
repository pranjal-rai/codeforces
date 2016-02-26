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
    long long int var,n,i,k=0,sum=0;
    vector <long long int > vec;
    vector <long long int >::iterator minele;
    cin >>n;
    sum=0;
    for(i=0;i<2*n-1;i++)
    {
        cin >>var;
        if(var<0)
            k++;
        sum=sum+((long long int)fabs(var));
        vec.push_back(((long long int)fabs(var)));
    }
    minele=min_element(vec.begin(),vec.end());
    if(k==n)
        cout <<sum<<"\n";
    else
    {
        if(k>n)
            k=k-n;
        if(k%2==1&&n%2==0)
            cout <<sum-2*((*minele))<<"\n";
        else
            cout<<sum<<"\n";
    }
    return 0;
}

