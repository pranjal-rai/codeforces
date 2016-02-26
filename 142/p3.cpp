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
    int n,m,i,j,flag=1,sum=0;
    int arr[100][10001]={0};
    char c;
    cin >>n>>m;
    vector < vector <int> > vec;
    vector <int> vec1;
    vector<int>::iterator low,up;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >>c;
            if(c=='1')
            {
                vec1.push_back(j);
            }
        }
        vec.push_back(vec1);
        vec1.erase(vec1.begin(),vec1.end());
    }
    for(i=0;i<n;i++)
    {
        int l=vec[i].size();
        if(l==0)
        {
            flag=0;
            break;
        }
        for(j=0;j<m;j++)
        {
            low=lower_bound(vec[i].begin(),vec[i].end(),j);
//            cout <<*low<<" ";
            if(vec[i].end()==low)
            {
                arr[i][j]=min(j-(*(low-1)),m-j+vec[i][0]);
            }
            else if(vec[i].begin()==low)
            {
                arr[i][j]=min(vec[i][0]-j,j+m-vec[i][l-1]);
            }
          /*  else if(*(low)==vec[i][l-1])
            {
                arr[i][j]=min(l-j,j+m-vec[i][l-1]);
            }*/
            else
            {
                arr[i][j]=min((*low)-j,j-*(low-1));
            }
        }
  //      cout <<"\n";
    }
  /*  for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout <<arr[i][j]<<" ";
        }
        cout <<"\n";
    }*/
    if(flag==0)
        cout <<"-1\n";
    else
    {
    int minimum=INT_MAX;
    for(i=0;i<m;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        {
            sum+=arr[j][i];
        }
        minimum=min(minimum,sum);
    }
    cout <<minimum<<"\n";
    }
    return 0;
}

