#include<bits/stdc++.h>
using namespace std;

#define F(i,n,k) for(int i=0;i<n;i+=k)
typedef long long int ll;

int main()
{
    ll n,m,c[51],a[251][51];
    cin>>n>>m;
    F(i,251,1)
    {
        F(j,51,1)
        {
            a[i][j]=0;
        }
    }
    F(i,m,1)
    {
        cin>>c[i];
    }

    if(m==0)
        cout<<"0"<<endl;
    else
    {
        a[n][0]=0;
        func(a,i,n);
    }

    return 0;
}
