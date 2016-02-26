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
    int n,var,i,j,k,l,minx,miny,counter=0,min1;
    vector <int> vecc,vec1;
    vector < vector <int> > vec;
    int arr[10000][4]={0};
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >>var;
        vecc.push_back(var);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<vecc[i];j++)
        {
            cin >>var;
            vec1.push_back(var);
        }
        vec.push_back(vec1);
        vec1.erase(vec1.begin(),vec1.end());
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<vecc[i];j++)
        {
            min1=INT_MAX;
            for(k=i;k<n;k++)
            {
                for(l=j;l<vecc[k];l++)
                {
                    if(vec[k][l]<min1)
                    {
                        min1=vec[k][l];
                        minx=k;
                        miny=l;
                    }
                }
            }
            if(minx!=i||miny!=j)
            {
                arr[counter][0]=i+1;
                arr[counter][1]=j+1;
                arr[counter][2]=minx+1;
                arr[counter][3]=miny+1;
                swap(vec[i][j],vec[minx][miny]);
                counter++;
            }

        }
    }
    cout<<counter<<"\n";
    for(i=0;i<counter;i++)
    {
        cout <<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[i][3]<<"\n";
    }
    return 0;
}

