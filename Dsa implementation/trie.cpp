const int mxn=1e5+5;
vector<vector<int>> t(mxn,vector<int> (27));
int n,k;
int siz = 0; //initially all numbers in x are -1
void add(string s){
	int i = 0, v = 0;
	while(i < (int)s.size()){
		if(t[v][(s[i]-'a')] == 0)
			v=t[v][(s[i++]-'a')]=++siz;
		else
			v=t[v][(s[i++]-'a')];
	}
}
 
void dfs(int node)
{
	fi(0,27)
	{
		if(t[node][i]!=0)
		{
			int child=t[node][i];
			dfs(child);
		}
	}
}
