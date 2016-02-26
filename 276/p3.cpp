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
    
LL n,p,l,r;
vector <LL> vec,vec1;

LL cal(LL l,LL r)
{
    if(l==r)
        return l;
    LL ans=-1,i;
    for(i=0;i<63;i++)
    {
        if(vec1[i]>=l&&vec1[i]<=r)
            ans=vec1[i];
    }
    if(ans!=-1)
        return ans;
    i=0;
    while(vec[i]<=l)
        i++;
    return cal(l-vec[i-1],r-vec[i-1])+vec[i-1];
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n;
    LL i;
    p=1,i=0;
    while(i<63)
    {
        vec.PB(p);
        vec1.PB(p-1);
        p=p*2;
        i++;
    }
    while(n--)
    {
        cin >>l>>r;
        cout <<cal(l,r)<<"\n";
    }
}
