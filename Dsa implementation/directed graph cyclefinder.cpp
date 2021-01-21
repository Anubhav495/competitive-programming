#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define int long long 
#define ll int
#define all(a) a.begin(),a.end()    
#define rev(a) a.rbegin(),a.rend()    
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //less_equal for multiset
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)
const double pi=acosl(-1);

int tim=0;
map<int,pair<int,int>> mapka;
vector<vector<int>> adj;
vector<int> vis;
vector<int> p;
void dfs(int node)
{
    vis[node]=1;
    for(auto i:adj[node])  
    {
        if(vis[i]==2) continue;
        if(vis[i])
        {
            vector<int> cyc;
            int cur=node;
            while(cur!=i&&cur!=-1)
            {
                cyc.pb(cur);
                cur=p[cur];
            }
            cyc.pb(i);
            reverse(all(cyc));
            cout<<"YES\n";
            for(auto x:cyc)
            {
                cout<<x+1<<' ';
            }
            cout<<'\n';
            exit(0);
        }
        p[i]=node;
        dfs(i);
    }
    p[node]=-1;
    vis[node]=2;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    adj=vector<vector<int>> (n);
    vis=vector<int> (n);
    p=vector<int> (n,-1);
    fi(0,m)
    {
        int x,y;
        cin>>x>>y;
        --x,--y;
        adj[x].pb(y);
    }
    fi(0,n)
    {
        if(!vis[i]) dfs(i);
    }
    cout<<"NO\n";
    
    
}

signed main()
{
    FAST;
    int tt=1;
    //cin>>tt;    
    while(tt--)
    {
        solve();
    }    
}
