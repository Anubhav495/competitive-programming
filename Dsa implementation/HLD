#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long int 
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)

const int N=1e5+1;
const int LN = 19;

vector <int> adj[N], costs[N], indexx[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];
int st[N*6], qt[N*6];

void make_tree(int cur, int s, int e) {
	if(s == e-1) {
		st[cur] = baseArray[s];
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
	//st[cur]=st[c1]+st[c2];
}

void update_tree(int cur, int s, int e, int x, int val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		st[cur] = val;
		return;
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m, e, x, val);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
	//st[cur]=st[c1]+st[c2];
}

int query_tree(int cur, int s, int e, int S, int E) {
	if(s >= E || e <= S) {
		return -1;
		//return 0;
	}
	if(s >= S && e <= E) {
		return st[cur];
	}
	int c1 = (cur<<1), c2 = c1 | 1, m = (s+e)>>1;
	int a=query_tree(c1, s, m, S, E);
	int b=query_tree(c2, m, e, S, E);
	return max(a,b);
	//return (a+b);
}


int query_up(int u, int v) {
	if(u == v) return 0;
	int uchain, vchain = chainInd[v], ans = -1;
	//ans = 0;
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			if(u==v) break;
			int x=query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
			ans=max(ans,x);
			//ans+=x;
			break;
		}
		int x=query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
		ans=max(ans,x);
		//ans+=x;
		u = chainHead[uchain];
		u = pa[0][u]; 
	}
	return ans;
}

int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

int query(int u, int v) {
	int lca = LCA(u, v);
	int ans = query_up(u, lca); 
	int temp = query_up(v, lca); 
	if(temp > ans) ans = temp;
	//ans+=temp;
	return ans;
}

void change(int i, int val) {
	int u = otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
}

void HLD(int curNode, int cost, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode;
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr;
	baseArray[ptr++] = cost;

	int sc = -1, ncost;
	for(int i=0; i<(int)adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
			sc = adj[curNode][i];
			ncost = costs[curNode][i];
		}
	}

	if(sc != -1) {
		HLD(sc, ncost, curNode);
	}

	for(int i=0; i<(int)adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc != adj[curNode][i]) {
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
	}
}
void dfs(int cur, int prev, int _depth=0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	for(int i=0; i<(int)adj[cur].size(); i++)
		if(adj[cur][i] != prev) {
			otherEnd[indexx[cur][i]] = adj[cur][i];
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}

int main() {
	FAST;
	int t;
	cin>>t;
	while(t--) {
		ptr = 0;
		int n;
		cin>>n;
		for(int i=0; i<n; i++) {
			adj[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chainHead[i] = -1;
			for(int j=0; j<LN; j++) pa[j][i] = -1;
		}
		for(int i=1; i<n; i++) {
			int u, v, c;
			cin>>u>>v>>c;
			u--; v--;
			adj[u].push_back(v);
			costs[u].push_back(c);
			indexx[u].push_back(i-1);
			adj[v].push_back(u);
			costs[v].push_back(c);
			indexx[v].push_back(i-1);
		}

		chainNo = 0;
		dfs(0, -1);
		HLD(0, -1, -1);
		make_tree(1, 0, ptr);
		for(int i=1; i<LN; i++)
			for(int j=0; j<n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
		
		while(1) {
			char s[100];
			cin>>s;
			if(s[0]=='D') {
				break;
			}
			int a, b;
			cin>>a>>b;
			if(s[0]=='Q') {
				int ans=query(a-1, b-1);
				cout<<ans<<'\n';
			} else {
				change(a-1, b);
			}
		}
	}
}
