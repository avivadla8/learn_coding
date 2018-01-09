#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;

ll findmaxarea(vector<ll> vec,ll n)
{
	ll ans,max_area,temp,ind;
	max_area = 0;
	stack<ll> st;
	ll i=0;
	while(i<n)
	{
		if(st.empty() || vec[st.top()]<=vec[i])
		{
			st.push(i);
			i++;
		}
		else
		{
			temp = st.top();
			st.pop();
			if(st.empty())
				ind = i;
			else
				ind = i-st.top()-1;
			ans = vec[temp]*(ind);
			if(max_area<ans)
				max_area = ans;
		}
	}
	return max_area;
}

int main()
{
	vector<ll> vec;
	ll temp,ans,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		vec.pb(temp);
	}
	ans = findmaxarea(vec,n);
	cout<<ans<<endl;
	return 0;
}