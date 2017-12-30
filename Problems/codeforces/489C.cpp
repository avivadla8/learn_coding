#include<bits/stdc++.h>
using namespace std;


void Gen_min(int sum,int n)
{
    int count=0;
    if(sum>9)
    {
        while(sum>9)
        {
           sum = sum-9;
           count++;
        }
        if(sum==0 && count==n)
        {
            for(int i=0;i<count;i++)
                cout<<"9";
            return;
        }
        else if(sum==0 && count<n)
        {
            count--;
            sum = 9;
            cout<<"1";
            for(int i=0;i<n-count-1;i++)
            {
                cout<<"0";
            }
            cout<<sum-1;
            for(int i=0;i<count;i++)
                cout<<"9";
            return;
        }
        else
        {
            if(n-count-1==0)
            {
                cout<<sum;
                for(int i=0;i<count;i++)
                    cout<<"9";
                return;
            }
            cout<<"1";
            for(int i=1;i<n-count-1;i++)
                cout<<"0";
            cout<<sum-1;
            for(int i=0;i<count;i++)
                cout<<"9";
            return;
        }
    }
    else
    {
        if(n==1)
        {
            cout<<sum;
            return;
        }
        cout<<"1";
        for(int i=1;i<n-1;i++)
            cout<<"0";
        cout<<sum-1;
        return;
    }
    return;
}

void Gen_max(int sum,int n)
{
    int count=0;
    if(sum>9)
    {
        while(sum>9)
        {
           sum = sum-9;
           count++;
        }
        if(sum==0 && count==n)
        {
            for(int i=0;i<count;i++)
                cout<<"9";
            return;
        }
        else if(sum==0 && count<n)
        {
            for(int i=0;i<count;i++)
            {
                cout<<"9";
            }
            for(int i=0;i<n-count;i++)
                cout<<"0";
            return;
        }
        else
        {
            for(int i=0;i<count;i++)
                cout<<"9";
            cout<<sum;
            for(int i=0;i<n-count-1;i++)
                cout<<"0";
            return;
        }
    }
    else
    {
        cout<<sum;
        for(int i=1;i<n;i++)
            cout<<"0";
        return;
    }
    return;

}

int main()
{
    int sum,n;
    cin>>n>>sum;
    if(sum==0)
    {
        if(n>1)
            cout<<"-1 -1\n";
        else
            cout<<"0 0\n";
    }
    else if(sum>9*n)
    {
        cout<<"-1 -1\n";
    }
    else
    {
        Gen_min(sum,n);
        cout<<" ";
        Gen_max(sum,n);
        cout<<"\n";
    }
    return 0;
}
