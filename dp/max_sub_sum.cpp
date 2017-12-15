#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,temp,val;
	vector<int> a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]>=0)
		{
			if(a[i-1]>=0)
				a[i]=a[i]+a[i-1];
			else
				a[i]=a[i];
		}
	}
	val = a[0];
	for(int i=1;i<n;i++)
	{
		if(val<a[i])
			val = a[i];
	}
	cout<<val<<endl;
	return 0;
}
