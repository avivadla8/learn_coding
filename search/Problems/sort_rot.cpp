#include<bits/stdc++.h>
using namespace std;

#define F(i,n,k) for(int i=0;i<n;i+=k)
#define pb push_back

typedef long long int ll;

int findpivot(vector<int> vec)
{
    int len,val;
    val = 0;
    len = vec.size();
    int l,r,mid;
    l = 0;
    r = len-1;
    while(l<=r)
    {
        if(l==r)
            return l;
        mid = (l+r)/2;
        if(mid<r && vec[mid]>vec[mid+1])
            return mid;
        if(mid>l && vec[mid]<vec[mid-1])
            return (mid-1);
        if(vec[l]>=vec[mid])
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int bin_search(vector<int> vec,int start,int end,int num)
{
    int l,r,mid;
    l = start;
    r = end;

    while(l<=r)
    {
        mid = (l+r)/2;
        if(vec[mid]==num)
            return mid;
        else if(vec[mid]>num)
            r = mid-1;
        else if(vec[mid]<num)
            l = mid+1;
    }
    return -1;
}

int main()
{

    // valid only when all the elements are distinct
    int temp,n,ans,num,flag;
    vector<int> vec;
    cin>>n;
    F(i,n,1)
    {
        cin>>temp;
        vec.pb(temp);
    }
    cin>>num;

    int ind = findpivot(vec);
    if(vec[ind]==num)
        cout<<vec[ind]<<endl;
    else
    {
        flag = bin_search(vec,0,ind-1,num);
        if(flag==-1)
        {
            flag = bin_search(vec,ind+1,n-1,num);
            if(flag==-1)
                cout<<"Not present"<<endl;
            else
                cout<<vec[flag]<<endl;
        }
        else
            cout<<vec[flag]<<endl;
    }
    return 0;
}
