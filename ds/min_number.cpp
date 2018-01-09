#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;

string minNumber(string str)
{
	string str2;
	char c;
	stack<int> st;
	str2 = "";
	for(int i=0;i<=str.length();i++)
	{
		st.push(i+1);
		if(i==str.length() || str[i]=='I')
		{
			while(!st.empty())
			{
				c = st.top()+'0';
				str2 = str2 + (c);
				// str2 = str2 + " ";
				st.pop();
			}
		}
	}
	return str2;
}

int main()
{
	string str,s2;
	cin>>str;
	s2 = minNumber(str);
	cout<<s2<<endl;
	return 0;
}