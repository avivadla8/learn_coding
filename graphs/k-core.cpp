#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector< vector<int> > MakeGraph(int n,int e,bool flag_directed)
{
	int u,v;
	vector< vector<int> > Node;
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		Node.pb(temp);
	}
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		Node[u].pb(v);
		if(!flag_directed)
		{
			Node[v].pb(u);
		}
	}
	return Node;
}

bool dfs(vector< vector<int> > Node, vector<int> &flag,int start_node,vector<int> &degree,int k)
{
	vector<int> temp;
	
	flag[start_node]=1;

	temp = Node[start_node];
	for(int i=0;i<temp.size();i++)
	{
		if(degree[start_node]<k)
			degree[temp[i]]--;

		if(flag[temp[i]]==0)
		{
			if(dfs(Node,flag,temp[i],degree,k))
				degree[start_node]--;
		}
	}
	return (degree[start_node]<k);
}

int main()
{
	int n,e,k;
	vector< vector<int> > Node;

	cin>>n>>e;
	Node = MakeGraph(n,e,false);

	cin>>k;

	vector<int> degree,flag;
	int min_degree = INT_MAX,min_node;
	for(int i=0;i<n;i++)
	{
		flag.pb(0);
		degree.pb(Node[i].size());
		if(Node[i].size()<min_degree)
		{
			min_degree = Node[i].size();
			min_node = i;
		}
	}

	cout<<"Degree of Nodes"<<endl;
	for(int i=0;i<degree.size();i++)
		cout<<degree[i]<<" ";
	cout<<endl;

	dfs(Node,flag,min_node,degree,k);

	for(int i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			dfs(Node,flag,i,degree,k);
		}
	}

	cout<<"K-core, Here k is "<<k<<endl;
	for(int i=0;i<n;i++)
	{
		if(degree[i]>=k)
			cout<<i<<" :- ";
		else
			continue;

		vector<int> temp;
		temp = Node[i];
		for(int i=0;i<temp.size();i++)
		{
			if(degree[temp[i]]>=k)
				cout<<temp[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}