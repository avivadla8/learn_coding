#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool comp(ll a,ll b)
{
    return a>b;
}

ll c1[1000001],c2[1000001];
ll mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    ll q,m,n,poi1,poi2,ans;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>m>>n;
        ans=0;
        for(int j=0;j<m-1;j++)
            cin>>c1[j];
        for(int j=0;j<n-1;j++)
            cin>>c2[j];
        sort(c1,c1+m-1,comp);
        sort(c2,c2+n-1,comp);

        poi1=0;
        poi2=0;
        while(poi1<m-1 && poi2<n-1)
        {
            if(c2[poi2]>c1[poi1])
            {
                ll val = (((poi1+1)%mod)*(c2[poi2]%mod))%mod;
                ans = (ans%mod + ((val)%mod))%mod;
                poi2++;
            }
            else if(c2[poi2]<c1[poi1])
            {
                ll val = (((poi2+1)%mod)*(c1[poi1]%mod))%mod;
                ans = (ans%mod + ((val)%mod))%mod;
                poi1++;                
            }
            else
            {
                if(poi1>poi2)
                {
                    ll val = (((poi1+1)%mod)*(c2[poi2]%mod))%mod;
                    ans = (ans%mod + ((val)%mod))%mod;
                    poi2++;

                }
                else
                {
                    ll val = (((poi2+1)%mod)*(c1[poi1]%mod))%mod;
                    ans = (ans%mod + ((val)%mod))%mod;
                    poi1++;                

                }
            }
        }
        if(poi1<m-1)
        {
            while(poi1<m-1)
            {
                ll val = (((poi2+1)%mod)*(c1[poi1]%mod))%mod;
                ans = (ans%mod + ((val)%mod))%mod;
                poi1++;
            }
        }
        else if(poi2<n-1)
        {
            while(poi2<n-1)
            {
                ll val = (((poi1+1)%mod)*(c2[poi2]%mod))%mod;
                ans = (ans%mod + ((val)%mod))%mod;
                poi2++;
            }            
        }
        cout<<ans<<endl;
    }
    return 0;
}

