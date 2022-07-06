#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct edge 
{
	int from, to, cost;
};
struct node
{
	int v, c; 
};
void dfs(const vector<vector<node>> &g, vector<int> &visited, vector<int> &ans, int v, int cost, int d)
{
	static vector<int> depth(visited.size());
	visited[v] = true; 
	depth[v] = d;
	for (node n : g[v])
	{
		if (!visited[n.v])
		{
			dfs(g, visited, ans, n.v, n.c, d + 1);
			depth[v] = min(depth[v], depth[n.v]);
		}
		else 
		    if (n.c != cost) 
			depth[v] = min(depth[v], depth[n.v]);
	}
	if (depth[v] == d) 
		ans [cost] = 2; 
}
int main() 
{
	int V, E; 
	cin >> V >> E;
	vector<edge> edges(E + 1);
	vector<int> parent(E + 5); 
	for (int i = 1; i <= E; i++) 
	{ 
		cin >> edges[i].from >> edges[i].to >> edges[i].cost;
		parent [i] = i;
	}
	sort(parent.begin() + 1, parent.begin() + E + 1, [&edges](int L, int r)
	{return edges[L].cost < edges[r].cost;});
	vector<vector<node>> g(V + 1);
	vector<int> ans(E + 1, 0); 
	vector<int> visited(V + 1); 
	vector<int> h(V + 1); 
	vector<int> prev_node(V + 1); 
	auto root_parent = [&prev_node](int v) // will be automatically deducted from its initialize
	{
		while (prev_node[v] != 0) v = prev_node[v];
		return v; 
	};
	for ( int i = 1 , j = 0 ; i <= E ; i = j ) 
	{ 
	// For all edges with the same cost ( parent are indices is
	// sorted by cost , so we guarantee we get all of them )
	for (j=i;edges[parent[j]].cost==edges[parent[i]].cost; ++j) 
	{
		int f = root_parent ( edges [parent [ j ] ].from );
		int t = root_parent ( edges [parent [ j ] ].to ); 
		if ( f != t ) 
		{
			ans [ parent [ j ] ] = 1 ;
			g [f].push_back ( { t , parent [ j ] } ) ;
			g [t].push_back ( { f , parent [ j ] } ) ;
		}
	}
	// Do a DFS from the root of each node 
	for ( j = i ; edges[ parent [ j ] ].cost == edges [ parent [ i ] ].cost ; ++j )
	{
		int k = root_parent ( edges [ parent [ j ] ].from ) ;
		if ( !visited [ k ] ) 
			dfs ( g , visited , ans , k , 0 , 0 );
	}
	//Remove the nodes from the graph and find bridges 
	for (j = i; edges [parent[j]].cost == edges[parent[i]].cost; ++j)
	{
		int f = root_parent (edges [parent [j]].from); 
		int t = root_parent (edges[parent[j]].to); 
		g[f].clear(); g[t].clear(); 
		visited[f] = visited[t] = 0; 
		if (f != t)
		{
			if (h[f] > h[t]) 
			{
				prev_node[t] = f; 
			}
			else 
			{
				prev_node[f] = t;
				if (h[f] == h[t])
				{
					h[t]++;	
				}
			}
		}
	}
}
	for (int i = 1; i <= E; ++i)
	{
		if (ans[i] == 0)
			cout<<"none\n";
		else if (ans[i] == 1)
			cout<<"at least one\n";
		else 
			cout<<"any\n"; 
	}
	return 0;
}
