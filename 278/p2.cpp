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
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
//long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
//long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r%m;}
//int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
//void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int issorted(VI &v)
{
    for(int i=1;i<4;i++)
        if(v[i]<v[i-1])return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int i,n;
    VI v;
    v.resize(4,-1);
    cin >>n;
    for(i=0;i<n;i++)
        cin >>v[i];
    sort(all(v));
    if(n==4)
    {
        int f=0;
        while(1)
        {
            if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v))
            {
                f=1;
                break;
            }
            if(!(next_permutation(all(v))))
                break;
        }
        if(f)
            cout <<"YES\n";
        else
            cout <<"NO\n";
    }
    if(n==3)
    {
        while(1)
        {
            if(v[0]==-1)
            {
                if(v[3]%3==0)
                {
                    v[0]=v[3]/3;
                    if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v))
                    {
                        cout <<"YES\n";
                        cout <<v[0]<<"\n";
                        return 0;
                    }
                    v[0]=-1;
                }
            }
            else if(v[1]==-1)
            {
                if(v[3]==3*v[0])
                {
                    v[1]=4*v[0]-v[2];
                    if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6)
                    {
                        cout <<"YES\n";
                        cout <<v[1]<<"\n";
                        return 0;
                    }
                }
                v[1]=-1;
            }
            else if(v[2]==-1)
            {
                if(v[3]==3*v[0])
                {
                    v[2]=4*v[0]-v[1];
                    if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[2]>=1&&v[2]<=1e6)
                    {
                        cout <<"YES\n";
                        cout <<v[2]<<"\n";
                        return 0;
                    }
                }
                v[2]=-1;
            }
            else if(v[3]==-1)
            {
                v[3]=3*v[0];
                if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[3]>=1&&v[3]<=1e6)
                {
                    cout <<"YES\n";
                    cout <<v[3]<<"\n";
                    return 0;
                }
                v[3]=-1;
            }
            if(!(next_permutation(all(v))))
                break;
        }
        cout <<"NO\n";
    }
    else if(n==0)
    {
        cout <<"YES\n";
        cout <<"1\n2\n2\n3\n";
    }
    else if(n==1)
    {
        int f=0;
        while(1)
        {
            if(v[0]!=-1)
            {
                v[3]=3*v[0];
                for(i=1;i<=4*v[0];i++)
                {
                    v[1]=i;
                    v[2]=4*v[0]-v[1];
                    if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6)
                    {
                        cout <<"YES\n";
                        cout <<v[1]<<"\n"<<v[2]<<"\n"<<v[3]<<"\n";
                        return 0;
                    }
                }
                v[1]=-1,v[2]=-1,v[3]=-1;
            }
            if(v[1]!=-1)
            {
                for(i=1;i<=1e6;i++)
                {
                    v[2]=i;
                    if((v[1]+v[2])%4!=0)
                        continue;
                    v[0]=(v[1]+v[2])/4;
                    v[3]=3*v[0];
                    if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6&&v[0]>=1&&v[0]<=1e6&&v[3]>=1&&v[3]<=1e6)
                    {
                        cout <<"YES\n";
                        cout <<v[0]<<"\n"<<v[2]<<"\n"<<v[3]<<"\n";
                        return 0;
                    }
                }
                v[0]=-1,v[2]=-1,v[3]=-1;
            }
            if(v[2]!=-1)
            {
                for(i=1;i<=1e6;i++)
                {
                    v[1]=i;
                    if((v[1]+v[2])%4!=0)
                        continue;
                    v[0]=(v[1]+v[2])/4;
                    v[3]=3*v[0];
                    if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6&&v[0]>=1&&v[0]<=1e6&&v[3]>=1&&v[3]<=1e6)
                    {
                        cout <<"YES\n";
                        cout <<v[0]<<"\n"<<v[1]<<"\n"<<v[3]<<"\n";
                        return 0;
                    }
                }
                v[0]=-1,v[1]=-1,v[3]=-1;
            }
            else if(v[3]!=-1)
            {
                if(v[3]%3==0)
                {
                    v[0]=v[3]/3;
                    for(i=1;i<=4*v[0];i++)
                    {
                        v[1]=i;
                        v[2]=4*v[0]-v[1];
                        if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6&&v[0]>=1&&v[0]<=1e6)
                        {
                            cout <<"YES\n";
                            cout <<v[0]<<"\n"<<v[1]<<"\n"<<v[2]<<"\n";
                            return 0;
                        }
                    }
                    v[0]=-1,v[2]=-1,v[1]=-1;
                }
            }
            if(!(next_permutation(all(v))))
                break;
        }
        cout <<"NO\n";
    }
    else if(n==2)
    {
        while(1)
        {
            if(v[0]!=-1&&v[1]!=-1)
            {
                v[3]=3*v[0];
                v[2]=4*v[0]-v[1];
                if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6&&v[0]>=1&&v[0]<=1e6&&v[3]>=1&&v[3]<=1e6)
                {
                   // trace1(1);
                    cout <<"YES\n";
                    cout <<v[2]<<"\n"<<v[3]<<"\n";
                    return 0;
                }
                v[2]=-1,v[3]=-1;
            }
            if(v[0]!=-1&&v[2]!=-1)
            {
                v[3]=3*v[0];
                v[1]=4*v[0]-v[2];
                if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6&&v[0]>=1&&v[0]<=1e6&&v[3]>=1&&v[3]<=1e6)
                {
                   // trace1(2);
                    cout <<"YES\n";
                    cout <<v[1]<<"\n"<<v[3]<<"\n";
                    return 0;
                }
                v[1]=-1,v[3]=-1;
            }
            if(v[0]!=-1&&v[3]!=-1)
            {
                for(i=1;i<=1e6;i++)
                {
                    v[1]=i;
                    v[2]=4*v[0]-v[1];
                    if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6&&v[0]>=1&&v[0]<=1e6&&v[3]>=1&&v[3]<=1e6)
                    {
                   // trace1(3);
                        cout <<"YES\n";
                        cout <<v[1]<<"\n"<<v[2]<<"\n";
                        return 0;
                    }
                }
                v[1]=-1,v[2]=-1;
            }
            if(v[1]!=-1&&v[2]!=-1)
            {
                v[0]=(v[1]+v[2])/2;
                v[3]=3*v[0];
                if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6&&v[0]>=1&&v[0]<=1e6&&v[3]>=1&&v[3]<=1e6)
                {
                    //trace1(4);
                    cout <<"YES\n";
                    cout <<v[0]<<"\n"<<v[3]<<"\n";
                    return 0;
                }
                v[0]=-1,v[3]=-1;
            }
            if(v[1]!=-1&&v[3]!=-1)
            {
                  //  trace1(5);
                v[0]=v[3]/3;
                v[2]=4*v[0]-v[1];
                if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6&&v[0]>=1&&v[0]<=1e6&&v[3]>=1&&v[3]<=1e6)
                {
                    cout <<"YES\n";
                    cout <<v[0]<<"\n"<<v[2]<<"\n";
                    return 0;
                }
                v[0]=-1,v[2]=-1;
            }
            if(v[2]!=-1&&v[3]!=-1)
            {
                v[0]=v[3]/3;
                v[1]=4*v[0]-v[2];
                if(v[3]==3*v[0]&&(v[1]+v[2])==4*v[0]&&issorted(v)&&v[1]>=1&&v[1]<=1e6&&v[2]>=1&&v[2]<=1e6&&v[0]>=1&&v[0]<=1e6&&v[3]>=1&&v[3]<=1e6)
                {
                //    trace1(6);
                    cout <<"YES\n";
                    cout <<v[0]<<"\n"<<v[1]<<"\n";
                    return 0;
                }
                v[0]=-1,v[1]=-1;
            }
            if(!(next_permutation(all(v))))
                break;
        }
        cout <<"NO\n";
    }        
    return 0;
}
