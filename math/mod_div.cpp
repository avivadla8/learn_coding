#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll pow(ll val1,ll val2,ll mod)
{
    ll ar[65],ans,poi;
    ans = 1;
    ar[0]=val1;
    for(int i=1;i<64;i++)
    {
        ar[i]=((ar[i-1]%mod)*(ar[i-1]%mod))%mod;
    }
    poi=0;
    while(val2>0)
    {
        if(val2%2)
            ans = ((ans%mod)*(ar[poi]%mod))%mod;
        poi++;
        val2 = val2/2;
    }
    return ans;
}

ll mod_div(ll val1,ll val2,ll mod)
{
    ll ans,temp;

    temp = pow(val2,mod-2);
    ans = ((val1%mod)*(temp%mod))%mod;
    return ans;
}

int main()
{
    ll a,b,m,ans;
    cin>>a>>b>>m;
    ans = mod_div(a,b,m);
    cout<<ans<<endl;
    return 0;
}
