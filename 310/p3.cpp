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


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    LL flag1,n,k,i,m,var,counter=0,piece=0,counter1,x,j,flag,p=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >>n>>k;
    piece=0,counter=0,flag1=0;
    for(i=0;i<k;i++)
    {
        cin >>m;
        flag=0,x=0,p=0;
        for(j=0;j<m;j++)
        {
            cin >>var;
            if(var==1||flag==1)
            {
                flag=1;
                if(var==x+1)
                    p++;
                x++;
            }
        }
        if(flag==1)
        {
            piece=piece+m-p+1;
            counter=counter+m-p;
        }
        else{
            counter=counter+(m-1);
            piece=piece+m;
        }
    }
    cout <<piece+counter-1<<"\n";
    return 0;
}
