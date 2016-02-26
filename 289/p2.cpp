//pranjalr34
#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int m, long long int n){if(n == 0) return m;return gcd(n, m % n);}  
long long int fastpow(long long int a, long long int b,long long int m){long long int r = 1;while (b > 0){if (b % 2 == 1)r = (r * a) % m;b = b >> 1;a = (a * a) % m;}return r;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k,i,j,var,flag,x;
    int arr[200][200]={0};
    vector <int> vec1;
    vector <int> vec;
    cin >>n>>k;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vec.push_back(var);
    }
    for(i=0;i<n;i++)
    {
        x=vec[i];
        j=1;
        while(x!=0)
        {
            arr[i][j]++;
            if(j==k)
                j=1;
            else 
                j++;
            x--;
        }
    }
    flag=1;
    for(i=1;i<k+1;i++)
    {
        for(j=0;j<n;j++)
        {
            var=arr[j][i];
            vec1.push_back(var);
        }
        sort(vec1.begin(),vec1.end());
        if((vec1[n-1]-vec1[0])>1)
        flag=0;
      //  for(j=0;j<n;j++)
        //    cout<<vec1[j]<<" ";
    //    cout <<"\n";
          /*  if(vec1
        for(j=0;j<(n-1);j++)
        {
            if((vec1[j+1]-vec1[j])>1)
            {
                flag=0;
            }
        }*/
        if(flag==0)
            break;
        vec1.erase(vec1.begin(),vec1.end());
    }
  if(flag==0)
        cout <<"NO\n";
    else
    {
        cout <<"YES\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<vec[i];j++)
            {
                while(arr[i][j+1]!=0)
                {
                    cout <<(j+1)<<" ";
                    arr[i][j+1]--;
                }
            }
            cout <<"\n";
        }
    }

            
    return 0;
}

