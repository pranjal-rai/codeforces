//pranjalr34

#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define SZ(a) (int)(a.size())
#define fi(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define n_p next_permutation
#define b_s binary_search
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a<b)?b:a)
#define gcd __gcd
#define INF INT_MAX
#define init(a,b) memset(a,b,sizeof(a))
#define INFL LLONG_MAX
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef long long int LL;
typedef pair<LL,LL> PLL;
typedef vector<LL> VLL;
typedef vector< PLL > VPLL;
typedef set<int> SI;
typedef set<LL> SLL;

void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);cout.precision(15);}
//LL modpow(LL a,LL b,LL m){LL r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
LL power(LL a, LL p){LL ret=1;while(p){if(p&1)ret=(ret*a);a=(a*a);p/=2;}return ret;}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int M[100010][100];
int A[100010];
int M1[100010][100];
int A1[100010];
int N;
void process1()
{
    int i, j;

    //initialize M for the intervals with length 1
    for (i = 0; i < N; i++)
        M[i][0] = i;
    //compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}  
void process2()
{
    int i, j;

    //initialize M for the intervals with length 1
    for (i = 0; i < N; i++)
        M1[i][0] = i;
    //compute values from smaller to bigger intervals
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A1[M1[i][j - 1]] < A1[M1[i + (1 << (j - 1))][j - 1]])
                M1[i][j] = M1[i][j - 1];
            else
                M1[i][j] = M1[i + (1 << (j - 1))][j - 1];
} 

int main()
{
    FastIO(); 
    int i,n,j;
    cin >>n;
    N=n;
    for(i=0;i<n;i++)
    {
        cin >>A[i];
        A1[i]=-1*A[i];
    }
    process1();
    process2();
    int val1,val2,idx1,idx2,l1=0,r,k,l2,r1,r2=n-1,counter=1;
    for(i=0;i<n-1;i++)
    {
        r1=i;
        k=log2(r1-l1+1);
        if(A1[M1[l1][k]]<=A1[M1[r1-power(2,k)+1][k]])
            idx2=M1[l1][k];
        else
            idx2=M1[r1-power(2,k)+1][k];
        l2=i+1,r2=n-1;
        k=log2(r2-l2+1);
        if(A[M[l2][k]]<=A[M[r2-power(2,k)+1][k]])
            idx1=M[l2][k];
        else
            idx1=M[r2-power(2,k)+1][k];
        val1=A[idx2];
        val2=A[idx1];
        if(val1<=val2)
        {
            counter++;
            l1=i;
        }
    }
    cout <<counter<<"\n";
    return 0;
}
