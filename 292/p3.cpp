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
    vector <char> vec;
    int i,j,l,n;
    string str;
    cin >>n;
    cin >>str; 
    for(i=0;i<n;i++)
    {
        if(str[i]=='2')
        {
            vec.push_back('2');
        }
        if(str[i]=='3')
        {
            vec.push_back('3');
        }
        if(str[i]=='4')
        {
            vec.push_back('2');
            vec.push_back('2');
            vec.push_back('3');
        }
        if(str[i]=='5')
        {
            vec.push_back('5');
        }
        if(str[i]=='6')
        {
            vec.push_back('3');
            vec.push_back('5');
        }
        if(str[i]=='7')
        {
            vec.push_back('7');
        }
        if(str[i]=='8')
        {
            vec.push_back('7');
            vec.push_back('2');
            vec.push_back('2');
            vec.push_back('2');
        }
        if(str[i]=='9')
        {
            vec.push_back('7');
            vec.push_back('3');
            vec.push_back('3');
            vec.push_back('2');
        }
    }
    sort(vec.begin(),vec.end());
    l=vec.size();
    for(i=l-1;i>=0;i--)
    {
        cout <<vec[i];
    }
    cout <<"\n";
    return 0;
}

