#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;

int find_len1(string str)
{
	int n = str.length();
	int max_len = 0;
	int a[n][n];

	for(int i=0;i<n;i++)
		a[i][i]=str[i]-'0';

	for(int len=2;len<=n;len++)
	{
		for(int i=0;i<n-len+1;i++)
		{
			int j=i+len-1;
			int k=len/2;

			a[i][j]=a[i][j-k] + a[j-k+1][j];
			if(len%2==0 && a[i][j-k]==a[j-k+1][j])
			{
				if(len>max_len)
					max_len = len;
			}
		}
	}
	return max_len;
}

int find_len2(string str)
{
	int n = str.length();
	int max_len=0;
	for(int i=0;i<=n-2;i++)
	{
		int l=i;
		int r = i+1;
		int lsum = 0;
		int rsum = 0;
		while(r<n && l>=0)
		{
			lsum = lsum + (str[l]-'0');
			rsum = rsum + (str[r]-'0');
			if(lsum==rsum)
			{
				max_len = max(max_len,r-l+1);
			}
			r--;
			l++;
		}
	}
	return max_len;
}

int main()
{
	string str;
	cin>>str;
	int n = find_len1(str);
	cout<<n<<endl;
	return 0;
}
