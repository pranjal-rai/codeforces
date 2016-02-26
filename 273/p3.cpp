//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
vector <long long int> vec;
long long int table,i,var;
void preparetable()
{
    if(vec[0]==vec[1]&&vec[2]==vec[1])
    {
        table+=vec[0];
        vec[0]=0;
        vec[1]=0;
        vec[2]=0;
    }
    else 
    if((vec[1]-vec[0])<=vec[2]/2)
    {
        table+=(vec[1]-vec[0]);
        vec[2]-=(2*(vec[1]-vec[0]));
        vec[1]=vec[0];
    }
    else 
    {
        table+=(vec[2]-vec[0])/2;
        vec[1]-=((vec[2]-vec[0])/2);
        vec[2]=vec[0];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    for(i=0;i<3;i++)
    {
        cin >>var;
        vec.push_back(var);
    }
    sort(vec.begin(),vec.end());
    while(!((vec[0]+vec[1]+vec[2]<3)||(vec[0]==0&&(vec[1]==0||vec[2]==0))||(vec[1]==0&&(vec[0]==0||vec[2]==0))||(vec[2]==0&&(vec[0]==0||vec[1]==0))))
    {
        preparetable();
        sort(vec.begin(),vec.end());
    }
    cout <<table<<"\n";
    return 0;
}
