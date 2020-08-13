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
#define lb lower_bound
#define ub upper_bound
//hash base 177013



int main()
{
	FAST;
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	//#endif
	//ll testcase;
	//cin>>testcase;
	//while(testcase--)
	{
		int n;
		cin>>n;
		int a[n];
		fi(0,n) cin>>a[i];
		int dp[n];
		fill(dp,dp+n,1000000000);
		dp[0]=0;
		fi(1,n)
		{
			if(i-1>=0)
			dp[i]=min(dp[i],dp[i-1]+abs(a[i]-a[i-1]));
			if(i-2>=0)
			dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-2]));
		}
		cout<<dp[n-1];
	}
}
