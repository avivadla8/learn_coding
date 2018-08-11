#include <bits/stdc++.h>
using namespace std;

vector<int> slid_win_max(vector<int> vec,int w)
{
    vector<int> vec2;
    deque<int> dq;
    int n = vec.size();
    if(w>n)
        return vec2;
    
    for(int i=0;i<w;i++)
    {
        while(!dq.empty() && vec[dq.back()]<=vec[i])
            dq.pop_back();
        dq.push_back(i);
    }
    vec2.push_back(vec[dq.front()]);
    for(int i=1;i<n-w+1;i++)
    {
        while(!dq.empty() && vec[dq.back()]<=vec[w+i-1])
            dq.pop_back();
        while(!dq.empty() && dq.front()<i)
            dq.pop_front();
        dq.push_back(w+i-1);
        vec2.push_back(vec[dq.front()]);
    }
    return vec2;
}

int main()
{
    int n,val,w;
    vector<int> vec,vec2;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        vec.push_back(val);
    }
    cin>>w;
    vec2 = slid_win_max(vec,w);
    for(int i=0;i<vec2.size();i++)
        cout<<vec2[i]<<" ";
    cout<<endl;

    return 0;
}