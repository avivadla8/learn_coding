#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;

int main()
{
	ll n,temp,ans[100001],left[100001],right[100001];
	vector<ll> vec;
	stack<ll> st;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		left[i] = -1;
		right[i] = n;
		cin>>temp;
		vec.pb(temp);
	}

	for(int i=0;i<n;i++)
	{
		while(!st.empty() && vec[st.top()]>=vec[i])
		{
			st.pop();
		}
		if(!st.empty())
			left[i] = st.top();
		st.push(i);
	}

	while(!st.empty())
	{
		st.pop();
	}

	for(int i=n-1;i>=0;i--)
	{
		while(!st.empty() && vec[st.top()]>=vec[i])
		{
			st.pop();
		}
		if(!st.empty())
			right[i] = st.top();
		st.push(i);
	}

	for(int i=0;i<=n;i++)
		ans[i]=0;

	for(int i=0;i<n;i++)
	{
		temp = right[i] - left[i] - 1;
		ans[temp] = max(ans[temp],vec[i]);
	}


	for(int i=n-1;i>=1;i--)
	{
		ans[i] = max(ans[i],ans[i+1]);
	}

	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	return 0;
}