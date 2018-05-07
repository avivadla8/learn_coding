#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back

typedef long long int ll;


vector<int> bfs(vector< vector<int> > Node,vector<int> flag,int start_node)
{
	vector<int> temp;
	vector<int> out;

	queue<int> que;
	que.push(start_node);

	while(!que.empty())
	{
		if(flag[que.front()]==1)
		{
			que.pop();
			continue;
		}
		else
			flag[que.front()]=1;

		out.pb(que.front());
		temp = Node[que.front()];
		que.pop();
		for(int i=0;i<temp.size();i++)
		{
			if(flag[temp[i]]==1)
				continue;
			else
				que.push(temp[i]);
		}
	}
	return out;
}

void dfs(vector< vector<int> > Node, vector<int> flag,int start_node)
{
	vector<int> temp;

	if(flag[start_node]==1)
		return;
	else
		flag[start_node]=1;

	// cout<<start_node<<" ";
	temp = Node[start_node];
	for(int i=0;i<temp.size();i++)
	{
		if(flag[temp[i]]==1)
			continue;
		else
			dfs(Node,flag,temp[i]);
	}
	return;
}

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

int main()
{
	int u,v,n,e;
	vector< vector<int> > Node;
	vector<int> flag;

	cin>>n>>e;

	Node = MakeGraph(n,e,true);	

	flag.clear();
	for(int i=0;i<n;i++)
	{
		flag.pb(0);
	}

	/* BFS Usage:
	vector<int> out = bfs(Node,flag,0);
	for(int i=0;i<out.size();i++)
		cout<<out[i]<<" ";
	cout<<endl;
	*/

	/* DFS Usage:
	dfs(Node,flag,2);
	*/
	return 0;
}