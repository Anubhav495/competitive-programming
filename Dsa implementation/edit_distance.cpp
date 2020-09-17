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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long int 
#define ar array
#define pb push_back
#define fi(a,b) for(ll i=a;i<(b);i++)
#define fj(a,b) for(ll j=a;j<(b);j++)
#define fk(a,b) for(ll k=a;k<(b);k++)

const int mod=1e9+7;

int main()
{
	FAST;
	//#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	//#endif
	//int tt;
	//cin>>tt;
	//while(tt--)
	{
		string s,t;
		cin>>s>>t;
		int n=s.size();
		int m=t.size();
		vector<vector<int>> dp(n+1,vector<int> (m+1,INT_MAX));
		fi(0,m+1)
		{
			dp[0][i]=i;
		}
		fi(0,n+1)
		{
			dp[i][0]=i;
		}
		fi(1,n+1)
		{
			fj(1,m+1)
			{
				if(s[i-1]!=t[j-1])
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
					dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
					dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
				}
				else
				{
					dp[i][j]=dp[i-1][j-1];
				}
			}
		}
		cout<<dp[n][m];
		// move to git
	}		
}
