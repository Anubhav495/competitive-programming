#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //less_equal for multiset
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)
const double pi=acosl(-1);



void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	fi(1,n+1) cin>>a[i];
	const int mini=-1e18;
	vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>> (k+1,{mini,0LL}));
	dp[1][1].first=a[1];
	dp[1][1].second=1;
	//dp[i][j]--> till index i and have made j seg
	fi(2,n+1)
	{
		for(int seg=k;seg>=1;seg--)
		{
			if(dp[i-1][seg-1].first>0)
			{
				if(a[i]>dp[i][seg].first)
				{
					dp[i][seg].first=max(dp[i][seg].first,a[i]);
					dp[i][seg].second=1;
				}
			}
			if(dp[i][seg].first<dp[i-1][seg].first+a[i])
			{
				dp[i][seg].first=max(dp[i][seg].first,dp[i-1][seg].first+a[i]);
				dp[i][seg].second=dp[i-1][seg].second+1;
			}
		}
	}
	if(dp[n][k].first>0)
	{
		cout<<"YES\n";
		vector<int> out;
		int last=n;
		for(int seg=k;seg>=1;seg--)
		{
			for(int i=last;i>=1;i--)
			{
				if(dp[i][seg].first>0)
				{
					out.pb(dp[i][seg].second);
					last=last-dp[i][seg].second;
					break;
				}
			}
		}
		reverse(all(out));
		for(auto x:out){
			cout<<x<<' ';
		}
		cout<<'\n';
		
	}
	else
	{
		cout<<"NO\n";
	}
	
}

signed main()
{
	FAST;
	int tt=1;
	cin>>tt;	
	while(tt--)
	{
		solve();
	}	
}



