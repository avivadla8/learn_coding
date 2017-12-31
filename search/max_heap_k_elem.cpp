#include<bits/stdc++.h>
using namespace std;

#define F(i,n,k) for(int i=0;i<n;i+=k)
#define FF1(i,n,k) for(int i=1;i<=n;i+=k)
#define pb push_back
#define pob pop_back

int main()
{
    int n,temp,k;
    vector<int> v1,v2;

    cin>>n>>k;
    F(i,n,1)
    {
        cin>>temp;
        v1.pb(temp);
    }

    make_heap(v1.begin(),v1.end());
    F(i,k,1)
    {
        v2.pb(v1.front());
        pop_heap(v1.begin(),v1.end());
        v1.pop_back();
    }

    sort(v2.begin(),v2.end());
    F(i,k,1)
    {
        cout<<v2[i]<<" ";
    }
    return 0;
}
