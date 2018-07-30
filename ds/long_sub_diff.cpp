#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    int ind;
};

class ComparisonClass {
    public:
    bool operator() (node a, node b) {
        //comparison code here
        return a.val<b.val;
    }
};

class ComparisonClass2 {
    public:
    bool operator() (node a,node b)
    {
        return a.val>b.val;
    }
};

int solve(vector<int> &A, int B) {
    int n = A.size();
    if(n==0)
        return 0;
    
    int l[n],r[n],ls,rs,ans;
    ans = 1;
    ls = 0;
    rs = 0;
    node temp;
    node2 temp2;
    temp.val = A[0];temp.ind = 0;
    temp2.val = A[0];temp2.ind = 0;
    
    priority_queue<node,vector<node>,ComparisonClass > pq;
    priority_queue<node,vector<node>,ComparisonClass2 > pq_min;
    pq.push(temp);
    pq_min.push(temp);
    while(rs<n && ls<=rs)
    {
        while(!pq.empty() && pq.top().ind<ls)
            pq.pop();
        while(!pq_min.empty() && pq_min.top().ind<ls)
            pq_min.pop();

        if(abs(pq.top().val-pq_min.top().val)<B)
        {
            if(ans<(rs-ls+1))
                ans = rs-ls+1;
            rs++;
            if(rs<n)
            {
                node temp;
                node2 temp2;
                temp.ind = rs;temp.val = A[rs];
                temp2.ind = rs;temp2.val = A[rs];
                pq.push(temp);pq_min.push(temp);
            }
            
        }
        else
            ls++;
    }
    return ans;
}

int main()
{
    vector<int> vec;
    int n;
    int temp;
    int b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        vec.push_back(temp);
    }
    cin>>b;
    temp = solve(vec,b);
    cout<<temp<<endl;
    return 0;
}