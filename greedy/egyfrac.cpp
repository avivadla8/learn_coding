#include<bits/stdc++.h>
using namespace std;

void egyfrac(int nr,int nd)
{
	if(nr==0||nd==0)
	{
		cout<<"Invalid Input\n";
	}
	else if(nr>=nd)
	{
		cout<<floor(nr*1.0/nd)<<" + ";
		nr = nr-nd*floor(nr*1.0/nd);
		if(nr>0)
			egyfrac(nr,nd);
	}
	else if(nd%nr==0)
	{
		cout<<"1/"<<nd/nr;
	}
	else
	{
		int temp;
	        temp = ceil(nd*1.0/nr);
		cout<<"1/"<<temp<<" + ";
		nr = nr*temp - nd;
		nd = nd*temp;
		egyfrac(nr,nd);
	}
	return;
}

int main()
{
	int nr,nd;
	cin>>nr>>nd;

	if(nr==0||nd==0)
	{
		cout<<"Invalid input\n";
		return 0;
	}

	if(( nr xor nd) < 0)
	{
		
		cout<<"Negative Fraction\n";
		cout<<"-(";
		if(nr<0)
			nr = -1*nr;
		else
			nd = -1*nd;
	}
	else
	{
		if(nr<0 && nd<0)
		{
			nr=-1*nr;
			nd = -1*nd;
		}
		cout<<"Positive Fraction\n";
		cout<<"(";
	}

	egyfrac(nr,nd);
	cout<<")\n";
	return 0;
}
