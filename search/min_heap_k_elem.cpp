#include<bits/stdc++.h>
using namespace std;

#define F(i,n,k) for(int i=0;i<n;i+=k)
#define pb push_back
#define pob pop_back

int main()
{
    int n,k,temp;
    vector<int> vec;
    cin>>n>>k;
    F(i,n,1)
    {
        cin>>temp;
        vec.pb(temp);
    }
    priority_queue< int, vector<int>,greater<int> > pq;
    F(i,k,1)
    {
        pq.push(vec[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(pq.top()<vec[i])
        {
            pq.pop();
            pq.push(vec[i]);
        }
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}
