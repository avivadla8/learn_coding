#include<bits/stdc++.h>
using namespace std;

void func(char *buff,string str,int j,int p,int n)
{
	if(j==n)
	{
		buff[p]='\0';
		printf("%s\n",buff);
		return;
	}
	buff[p] = str[j];
	func(buff,str,j+1,p+1,n);
	buff[p]= ' ';
	buff[p+1] = str[j];
	func(buff,str,j+1,p+2,n);
	return;
}
int main()
{
	string str;
	cin>>str;
	int len;
	len = str.length();
	char buff[2*len+1];
	buff[0]=str[0];
	func(buff,str,1,1,len);
	return 0;
}
