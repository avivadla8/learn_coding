#include<bits/stdc++.h>
using namespace std;

#define F(i,n,k) for(int i=0;i<n;i+=k)
#define pb push_back
int main()
{
    ios::sync_with_stdio(false);
    int n,temp;
    vector<int> vec;
    cin>>n;
    F(i,n,1)
    {
        cin>>temp;
        vec.pb(temp);
    }

    // print the reverse array
    
    reverse(vec.begin(),vec.end());
    F(i,n,1)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    return 0;
}
