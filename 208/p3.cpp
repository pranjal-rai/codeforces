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
//bool cmp(int x,int y){return x<y;}    //sorts in ascending order 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,i,var,counter,v[4],l;
    stack <int> s;
    queue <int> q;
    deque <int> d;
    VPII vec;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        if(var==0)
        {
            counter=0,v[0]=v[1]=v[2]=v[3]=0;
            if(!(s.empty()))
            {
                v[0]=1;
                counter++;
                stack<int> s1;
                swap(s,s1);
            }
            if(!(q.empty()))
            {
                v[1]=1;
                counter++;
                queue<int> q1;
                swap(q,q1);
            }
            if(!(d.empty()))
            {
                counter++;
                if(d.front()>=d.back())
                    v[2]=1;
                else
                    v[3]=1;
                deque<int> d1;
                swap(d,d1);
            }
            cout <<counter;
            if(v[0]==1)
                cout <<" popStack";
            if(v[1]==1)
                cout <<" popQueue";
            if(v[2]==1)
                cout <<" popFront";
            if(v[3]==1)
                cout <<" popBack";
            cout <<"\n";
        }
        else
        {
            if(!(s.empty()))
                vec.PB(MP(s.top(),0));
            else
                vec.PB(MP(-1,0));
            if(!(q.empty()))
                vec.PB(MP(q.front(),1));
            else
                vec.PB(MP(-1,1));
            if(!(d.empty()))
                vec.PB(MP(d.front(),2));
            else
                vec.PB(MP(-1,2));
            if(!(d.empty()))
                vec.PB(MP(d.back(),3));
            else
                vec.PB(MP(-1,3));
            sort(all(vec));
            l=vec.size();
                l=vec[0].S;
                if(l==0)
                {
                     cout <<"pushStack";
                     s.push(var);
                }
                else if(l==1)
                {
                     cout <<"pushQueue";
                     q.push(var);
                }
                else if(l==2)
                {
                     cout <<"pushFront";
                     d.push_front(var);
                }
                else if(l==3)
                {
                     cout <<"pushBack";
                     d.push_back(var);
                }
            cout <<"\n";
            vec.clear();
        }
    }
    return 0;
}
