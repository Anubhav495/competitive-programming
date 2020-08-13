#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define ar array
#define pb push_back


int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("outputc.txt","w",stdout);
	// #endif
	
	//int t;
	//cin>>t;
	//while(t--)
	{
		int n;
		cin>>n;
		ll a[n][3];
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		ll dp[n][3];
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0]=a[0][0],dp[0][1]=a[0][1],dp[0][2]=a[0][2];
		for(int i=1;i<n;i++)
		{
			dp[i][0]=max({dp[i][0],dp[i-1][1]+a[i][0],dp[i-1][2]+a[i][0]});
			dp[i][1]=max({dp[i][1],dp[i-1][0]+a[i][1],dp[i-1][2]+a[i][1]});
			dp[i][2]=max({dp[i][2],dp[i-1][0]+a[i][2],dp[i-1][1]+a[i][2]});
		}
		cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
	}
}
