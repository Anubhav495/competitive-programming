void dfs(int nod)
{
	vis[nod]=true;
	t[temp]=nod;
	for(auto i:adj[nod])
	{
		if(!vis[i])
		{
			temp++;
			dfs(i);
		}
	}
	t[temp]=nod;
}
