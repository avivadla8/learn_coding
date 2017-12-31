#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define F(i,n,k) for(int i=0;i<n;i+=k)

int bin_search(vector<int> vec,int temp)
{
    int len = vec.size(),l,r,mid;
    l = 0;
    r = len-1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(vec[mid]==temp)
        {
            return mid;
        }
        else if(vec[mid]<temp)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    return -1;
}

int main()
{
    int n,temp;
    vector<int> vec;

    cin>>n;
    F(i,n,1)
    {
        cin>>temp;
        vec.pb(temp);
    }
    cin>>temp;
    //n = bin_search(vec,temp);
    n = lower_bound(vec.begin(),vec.end(),temp) - vec.begin();
    if(n==-1)
        cout<<"No Existence\n";
    else
        cout<<vec[n]<<endl;
    return 0;
}
