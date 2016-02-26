//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef long long int LL;
typedef pair<LL,LL> PLL;
typedef vector<LL> VLL;
typedef vector< PLL > VPLL;

//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
double var,eps=1e-10;
vector <double> v,v1,v2;
int n;
double solve(double x)
{
    double sum=0.0;
    int i;
    for(i=0;i<n;i++)
        v1[i]=v[i]-x;
    v2[0]=v1[0];
    for(i=1;i<n;i++)
    {
        if(fabs(v1[i]+v2[i-1])-fabs(v2[i-1])>eps)
            v2[i]=v1[i]+v2[i-1];
        else
            v2[i]=v1[i];
    }
    for(i=0;i<n;i++)
    {
        if(fabs(v2[i])>sum+eps)
            sum=fabs(v2[i]);
    }
/*    for(i=0;i<n;i++)
        cout <<v1[i]<<" ";
    cout <<"\n";
    for(i=0;i<n;i++)
        cout <<v2[i]<<" ";
    cout <<"\n";
  */  return sum;
}
int main()
{
    scanf("%d",&n);
    v1.resize(n);
    v2.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&var);
        v.PB(var);
    }
    double g,h,fg,fh,a=-20000,b=20000;
    int iteration=0;
    while(iteration<200)
    {
        g=(2*a+b)/3;
        h=(a+2*b)/3;        
        fg=solve(g);
        fh=solve(h);
        //printf("%d %.7lf %.7lf %.7lf %.7lf\n",iteration,fg,fh,a,b);
        if(fg+eps<fh)
            b=h;
        else
            a=g;
        iteration++;
    }
    printf("%.10lf %.10lf\n",solve(a),a);
    return 0;
}
