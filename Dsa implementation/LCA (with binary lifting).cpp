#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define ar array
#define pb push_back

// can be used to make path queries in a tree

const int mxn=2e5+2,ln=21;
vector<int> a;
vector<vector<int>> adj;
int h[mxn],p[mxn][ln+1];
bool vis[mxn];

void dfs(int node)
{
	vis[node]=true;
	for(auto i:adj[node])
	{
		if(!vis[i])
		{
			
			h[i]=h[node]+1;
			p[i][0]=node;
			dfs(i);
			
		}
	}
}

int lca(int x,int y)
{
	if(h[x]>h[y])
	{
		swap(x,y);
	}
	
	int diff=h[y]-h[x];
	
	for(int i=0;i<=ln;i++)
	{
		if(diff&(1LL<<i))
		{
			y=p[y][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	
	for(int i=ln;i>=0;i--)
	{
		if(p[x][i]==p[y][i])
		{
			continue;
		}
		x=p[x][i];
		y=p[y][i];
	}
	return p[x][0];
	
}

int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("outputc.txt","w",stdout);
	// #endif
	
  
  //question link -> https://www.codechef.com/LRNDSA08/problems/ENOC1
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		a=vector<int> (n+1,0);
		adj=vector<vector<int>> (n+1);
		for(int i=0;i<n;i++)
		{
			cin>>a[i+1];
		}
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		memset(p,0,sizeof(p));
		fill(h,h+mxn,0);
		memset(vis,false,sizeof(vis));
		dfs(1);
		
		//binary lifting
		
		for(int i=1;i<=ln;i++)
		{
			for(int j=1;j<=n;j++)
			{
				p[j][i]=p[p[j][i-1]][i-1];
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
		}
	}
		
}
