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
			Node[v].pb(u);
	}
	return Node;
}

void dfs(vector< vector<int> > Node,int start_node,int dest,vector<int> &flag,int &count)
{
	vector<int> temp;
	if(flag[start_node]==1)
		return;
	flag[start_node]=1;

	if(start_node == dest)
		count++;
	else
	{
		temp = Node[start_node];
		for(int i=0;i<temp.size();i++)
		{
			if(flag[temp[i]]==0)
				dfs(Node,temp[i],dest,flag,count);
		}
	}
	flag[start_node]=0;
	return;
}

int count_path(vector< vector<int> > Node,int source,int dest,vector<int> &flag)
{
	int count = 0;
	dfs(Node,source,dest,flag,count);
	return count;
}

int main()
{
	int n,e;
	int source,dest;
	vector<int> flag;
	vector< vector<int> > Node;

	cin>>n>>e;
	Node = MakeGraph(n,e,true);

	for(int i=0;i<n;i++)
		flag.pb(0);


	cin>>source>>dest;

	int val = count_path(Node,source,dest,flag);
	cout<<val<<endl;
}