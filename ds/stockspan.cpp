#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;

struct node
{
    int val,ind;
};

int main()
{
    int n,temp;
    stack<node> vec;
    node temp2;
    vector<int> h;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(i==0)
        {
            h.pb(-1);
            temp2.val = temp;
            temp2.ind = i;
            vec.push(temp2);

        }
        else
        {
            int flag=0;
            while(!vec.empty())
            {
                if(vec.top().val>temp)
                {
                    h.pb(vec.top().ind);
                    temp2.val = temp;
                    temp2.ind = i;
                    vec.push(temp2);
                    flag = 1;
                    break;
                }
                else
                {
                    vec.pop();
                }
            }
            if(flag==0)
            {
                h.pb(-1);
                temp2.val = temp;
                temp2.ind = i;
                vec.push(temp2);
            }
        }
        
    }

    for(int i=0;i<n;i++)
    {
        cout<<i-h[i]<<" ";
    }
    cout<<endl;
    return 0;
}
