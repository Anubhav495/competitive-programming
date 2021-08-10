 #define pb push_back

vector<vector<int>> adj;
vector<int> is,low,in;
int t=1;
vector<vector<int>> ans;
void dfs(int node,int pa)
{
    in[node]=t;
    low[node]=t;
    t++;
    for(auto x:adj[node])
    {
        if(!in[x])
        {
            dfs(x,node);
            low[node]=min(low[node],low[x]);
            if(pa!=-1&&low[x]>=in[node])
            {
                is[node]=1;
            }
        }
        if(x!=pa)
        {
            low[node]=min(low[node],in[x]);
        }   
    }
}

vector<vector<int>> find_critical_connections(int n, vector<vector<int>> connections) {
    int extra=n;
    t=1;
    ans.clear();
    int m=connections.size();
    adj=vector<vector<int>> (2*m+n);
    is=low=in=vector<int> (2*m+n);
    // vector<vector<int>> temp(2*n+50); 
    for(auto x:connections)
    {
        adj[x[0]].pb(extra);
        adj[extra].pb(x[0]);
        adj[extra].pb(x[1]);
        adj[x[1]].pb(extra);
        extra++;
    }
    dfs(0,-1);
    for(int i=n;i<extra;i++)
    {
        if(is[i])
        {
            ans.pb(connections[i-n]);
        }
    }
    if(ans.size()==0) ans.pb({-1,-1});
    return ans;
    
    
}
