#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define NINF -1000000000

typedef struct node{
	int val;
	int weight;
}node;

vector< vector<node> > MakeGraph(int n,int e,bool flag_directed)
{
	int u,v,w;
	vector< vector<node> > Node;
	for(int i=0;i<n;i++)
	{
		vector<node> temp;
		Node.pb(temp);
	}
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		node temp2;
		temp2.val = v;
		temp2.weight = w;
		Node[u].pb(temp2);
		if(!flag_directed)
		{
			node temp2;
			temp2.val = u;
			temp2.weight = w;
			Node[v].pb(temp2);
		}
	}
	return Node;
}

void dfs(vector< vector<node> > Node, vector<int> &flag,int start_node,stack<int> &stk)
{
	vector<node> temp;
	if(flag[start_node]==1)
		return;
	flag[start_node]=1;

	temp = Node[start_node];

	for(int i=0;i<temp.size();i++)
	{
		if(flag[temp[i].val]==1)
			continue;
		else
			dfs(Node,flag,temp[i].val,stk);
	}
	stk.push(start_node);
	return;
}

vector<int> topological_sort(vector< vector<node> > Node,int n,int e,int start_node)
{
	vector<int> flag;
	stack<int> stk;
	for(int i=0;i<n;i++)
	{
		flag.pb(0);
	}
	for(int i=0+start_node;i<n+start_node;i++)
	{
		if(flag[i]==0)
		{
			dfs(Node,flag,i,stk);
		}
	}
	vector<int> out;
	while(!stk.empty())
	{
		out.pb(stk.top());
		stk.pop();
	}
	return out;
}

vector<int> LongestPath(vector< vector<node> > Node,int n,int source,vector<int> topsort)
{
	vector<int> dist;
	vector<node> temp;
	for(int i=0;i<n;i++)
	{
		dist.pb(NINF);
	}
	dist[source]= 0;

	for(int i=0;i<topsort.size();i++)
	{
		temp = Node[topsort[i]];
		for(int j=0;j<temp.size();j++)
		{
			if(temp[j].val!=source)
				if(dist[temp[j].val] < dist[topsort[i]]+temp[j].weight)
					dist[temp[j].val] = dist[topsort[i]] + temp[j].weight;
		}
	}
	return dist;
}

int main()
{
	int n,e,u,v;
	vector< vector<node> > Node;
	vector<int> topsort;
	cin>>n>>e;

	Node = MakeGraph(n,e,true);
	topsort = topological_sort(Node,n,e,0);

	for(int i=0;i<topsort.size();i++)
		cout<<topsort[i]<<" ";
	cout<<endl;
	// below code assumes that index starts from 0
	int source;
	cin>>source;
	vector<int> dist = LongestPath(Node,n,source,topsort);

	for(int i=0;i<dist.size();i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	return 0;
}