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

class segment_tree
{
    public:
        VLL ST;
        VLL A;  //base array
        LL n;

        void build(LL node,LL l,LL r)
        {
            if(l==r-1)
            {
                ST[node]=A[l];
                return;
            }

            LL leftChild = node<<1;
            LL rightChild = leftChild | 1;
            LL mid = (l+r)>>1;

            build(leftChild,l,mid);
            build(rightChild,mid,r);

            //Operation of segment tree
            LL lc = ST[leftChild];
            LL rc = ST[rightChild];
            ST[node] = lc + rc;
        }

        void update(LL node,LL l,LL r, LL idx, LL x)
        {
            if(l==r-1)
            {
                ST[node]=x;
                return;
            }
            LL leftChild = node<<1;
            LL rightChild = leftChild | 1;
            LL mid = (l+r)>>1;
            if(idx<mid)
                update(leftChild,l,mid,idx,x);
            else
                update(rightChild,mid,r,idx,x);
            ST[node]=ST[leftChild]+ST[rightChild];
        }

        LL range_query(LL L,LL R,LL node,LL l,LL r)
        {
            if(l>=R || r<=L)
                //Depending on your operation return a value which indicates that there's nothing here
                return 0;

            LL leftChild = node<<1;
            LL rightChild = leftChild|1;
            if(L<=l && r<=R)
                return ST[node];
            LL mid = (l+r)>>1;
            LL leftAns = range_query(L,R,leftChild,l,mid);
            LL rightAns = range_query(L,R,rightChild,mid,r);
            //Operation of segment tree
            return leftAns + rightAns;
        }
        segment_tree(){ST.clear();A.clear();n=0;}
        segment_tree(VLL& baseArray)    //construct using a vector
        {
            A = baseArray;
            n = baseArray.size();
            ST = VLL(4*n,0);
            build(1,0,n);
        }
        segment_tree(LL *begin,LL *end)   //construct using an array
        {
            A = VLL(begin,end);
            n = A.size();
            ST = VLL(4*n,0);
            build(1,0,n);
        }

        //returns [L,R)
        LL query(LL L,LL R)
        {
            return range_query(L,R,1,0,n);
        }
};

LL n,k,i,var,diff,val,mn,idx;
VLL v;
set <LL> s;
set <LL> ::iterator it;
segment_tree s1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>k;
    LL mn=INT_MAX;
    for(i=0;i<n;i++)
    {
        cin >>var;
        v.PB(var);
        mn=min(mn,var);
    }
    s1=segment_tree(v);
    for(i=0;i<k;i++)
        s.insert(i);
    LL ans=0;
    for(i=0;i<n-k+1;i++)
    {
        val=s1.query(i,i+k);
        if(val<0)
        {
            s.insert(i+k);
            continue;
        }
        it=--(s.end());
        diff=val+1;
        ans=ans+diff;
        while(diff!=0)
        {
            idx=*it;
            if((v[idx]-mn)>diff)
            {
                v[idx]-=diff;
                diff=0;
                s1.update(1,0,n,idx,v[idx]);
            }
            else
            {
                diff-=(v[idx]-mn);
                v[idx]=mn;
                s1.update(1,0,n,idx,v[idx]);
                it--;
            }
        }
        s.insert(i+k);
    }
    cout <<ans<<"\n";
    for(i=0;i<n;i++)
    {
        cout <<v[i]<<" ";
    }
    cout <<"\n";
    return 0;
}
