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
    int time,n,i,score,counter=0,index,maximum=INT_MIN,j,l,sum=0;
    string str;
    vector < vector<pair<int,int> > > v(1000);
    set <pair<string,int> >::iterator  it;
    set <pair<string,int> > myset;
    pair <string,int> mypair;
    pair <int,int> mypair1;
    vector <pair<int,int> > vec;
    vector <string> myvec;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>str>>score;
        mypair.first=str;
        mypair.second=-1;
        it=myset.upper_bound(mypair);
        if(it==myset.end()||(*it).first!=str)
        {
            myvec.push_back(str);
            mypair.second=counter;
            myset.insert(mypair);
            mypair1.first=score;
            mypair1.second=i;
            vec.push_back(mypair1);
            v[counter].push_back(mypair1);
            counter++;
        }
        else
        {
            index=(*it).second;
            mypair1.first=score;
            mypair1.second=i;
            v[index].push_back(mypair1);
            vec[index].first+=score;
            if(score!=0)
            vec[index].second=i;
        }
    }
    for(i=0;i<counter;i++)
    {
        if(vec[i].first>=maximum)
        {
            if(vec[i].first==maximum)
            {
                maximum=vec[i].first;
                if(vec[index].second>vec[i].second)
                    index=i;
            }
            else
            {
                maximum=vec[i].first;
                index=i;
            }
        }
    }
    index=INT_MAX,time=INT_MAX;
    for(i=0;i<counter;i++)
    {
        if(vec[i].first==maximum)
        {
            l=v[i].size();
            sum=0;
            for(j=0;j<l;j++)
            {
                sum=sum+v[i][j].first;
                if(sum>=maximum)
                {
                    if(v[i][j].second<time){time=v[i][j].second;
                        index=i;}
                    break;
                }
            }
        }
    }
    cout <<myvec[index]<<"\n";
    return 0;
}
