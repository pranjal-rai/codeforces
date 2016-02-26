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
    //long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
    //int prime(long long int x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){long long int y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}
    //LL root(LL x){return v[x]<0?x:(v[x]=root(v[x]));}  //returns the root of the node x
    //void merge(int x,int y){    if((x = root(x)) == (y = root(y)))     return ;if(v[y] < v[x]) swap(x, y);v[x] += v[y];v[y] = x;}  //(merges two sets) further if i is a root then v[i] is the negative of size of its set
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

    LL P1=1000000009,M1=1000001011,P2=1000002043,M2=1000003051;

    LL p1[200010],p2[200010],h1[200010],h2[200010],h3[200010],h4[200010];


    //get first hash value
    LL gethash1(LL l,LL r)
    {
        if(l==0)
            return h1[r];
        else 
            return (h1[r]-(h1[l-1]*p1[r-l+1])%M1+M1)%M1;
    }

    //get second hash value
    LL gethash2(LL l,LL r)
    {
        if(l==0)
            return h2[r];
        else 
            return (h2[r]-(h2[l-1]*p2[r-l+1])%M2+M2)%M2;
    }

    LL gethash3(LL l,LL r)
    {
        if(l==0)
            return h3[r];
        else 
            return (h3[r]-(h3[l-1]*p1[r-l+1])%M1+M1)%M1;
    }
    LL gethash4(LL l,LL r)
    {
        if(l==0)
            return h4[r];
        else 
            return (h4[r]-(h4[l-1]*p2[r-l+1])%M2+M2)%M2;
    }

    int check(LL l1,LL r1,LL l2,LL r2)
    {
        if(r1<l1||r2<l2)
            return 0;
        if(MP(gethash1(l1,r1),gethash2(l1,r1))==MP(gethash3(l2,r2),gethash4(l2,r2)))
            return 1;
        if((l1-r1)%2==0)
            return 0;
        LL mid1=(l1+r1)/2,mid2=(l2+r2)/2;
        
             srand ( time(NULL)+rand() );
             int m=rand()%2;
             if(m==0)
             {
        if(check(l1,mid1,mid2+1,r2)&&(check(mid1+1,r1,l2,mid2)))
        return 1;
        if(check(l1,mid1,l2,mid2)&&(check(mid1+1,r1,mid2+1,r2)))
            return 1;
    }
    else
    {
    if(check(l1,mid1,l2,mid2)&&(check(mid1+1,r1,mid2+1,r2)))
            return 1;
        if(check(l1,mid1,mid2+1,r2)&&(check(mid1+1,r1,l2,mid2)))
        return 1;
    }
        return 0;

    }



    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);   
        string str1,str2;
        LL len,i;
        cin >>str1>>str2;
        len=str1.length();
        p1[0]=1,p2[0]=1;
        for(i=1;i<=len;i++)
        {
            p1[i]=(p1[i-1]*P1)%M1;
            p2[i]=(p2[i-1]*P2)%M2;
        }
        h1[0]=str1[0]%M1;
        for(i=1;i<len;i++)
        {
            h1[i]=((h1[i-1]*P1)%M1+str1[i])%M1;
        }
        h2[0]=str1[0]%M2;
        for(i=1;i<len;i++)
        {
            h2[i]=((h2[i-1]*P2)%M2+str1[i])%M2;
        }
        h3[0]=str2[0]%M1;
        for(i=1;i<len;i++)
        {
            h3[i]=((h3[i-1]*P1)%M1+str2[i])%M1;
        }
        h4[0]=str2[0]%M2;
        for(i=1;i<len;i++)
        {
            h4[i]=((h4[i-1]*P2)%M2+str2[i])%M2;
        }
        if(check(0,len-1,0,len-1)==1)
            cout <<"YES\n";
        else
            cout <<"NO\n";
        return 0;
    }