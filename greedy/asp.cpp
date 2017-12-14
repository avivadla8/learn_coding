#include<bits/stdc++.h>
using namespace std;

bool func(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}

int asp(int n,vector<pair<int,int>> t)
{
	int count = 0,poi;
	sort(t.begin(),t.end(),func);
	count = 1;
	poi=0;
	for(int i=1;i<n;i++)
	{
		if(t[i].first>=t[poi].second)
		{
			count++;
			poi=i;
		}
	}
	return count;
}

int main()
{
	vector<pair<int,int>> t;
	int temp1,temp2,n,count;
	pair<int,int> temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp1>>temp2;
		temp = make_pair(temp1,temp2);
		t.push_back(temp);
	}
	count = asp(n,t);
	cout<<count<<endl;
	return 0;
}
