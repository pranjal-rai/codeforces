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
vector <long long int> veca,vecb;
long long int n,m;
long long int solve(long long int x)
{
    long long int i,counter=0;
    for(i=0;i<n;i++)
    {
        if(veca[i]<x)
            counter+=(x-veca[i]);
    }
    for(i=0;i<m;i++)
    {
        if(vecb[i]>x)
            counter+=(vecb[i]-x);
    }
    return counter;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long int i,var,a,b,iteration,g,h,fg,fh,minans=LLONG_MAX;
    cin >>n>>m;
    for(i=0;i<n;i++)
    {
        cin >>var;
        veca.push_back(var);
    }
    for(i=0;i<m;i++)
    {
        cin >>var;
        vecb.push_back(var);
    }
    a=1,b=1000000100,iteration=0;
    while(iteration<300)
    {
        g=(2*a+b)/3;
        h=(a+2*b)/3;        
        fg=solve(g);
        fh=solve(h);
        if(fg<fh)
            b=h;
        else
            a=g;
        iteration++;
    }
    for(i=a;i<=b;i++)
        minans=min(minans,solve(i));
    cout <<minans<<"\n";
    return 0;
}
