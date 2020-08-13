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
#define mp make_pair
//hash base 177013

template <typename T> void max_self(T& a,T b)
{
	a=max(a,b);
}

bool row_col(pair<int,int> p)
{
	if(p.first==0||p.second==0)
		return 1;
	return 0;
}

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
		string a,b;
		cin>>a>>b;
		int n=a.size();
		int m=b.size();
		pair<int,pair<int,int>> dp[n+2][m+2];
		fi(0,n+2)
		{
			fj(0,m+2)
			{
				dp[i][j]={INT_MIN,{INT_MIN,INT_MIN}};
			}
		}
		dp[0][0]={0,{0,0}};
		fi(0,n)
		{
			fj(0,m)
			{
				if(a[i]==b[j])
				{
					max_self(dp[i+1][j+1],{dp[i][j].first+1,{i,j}});
				}
					
				max_self(dp[i+1][j],{dp[i][j].first,{i,j}});
				max_self(dp[i][j+1],{dp[i][j].first,{i,j}});
			}
		}
		pair<int,pair<int,int>> ans={0,{0,0}};
		fi(0,n+2)
		{
			fj(0,m+2)
			{
				max_self(ans,{dp[i][j].first,{i,j}});
			}
		}
		
		string c;
		pair<int,int> curr=ans.second;
		while(!row_col(curr))
		{
			int i=curr.first;
			int j=curr.second;
			pair<int,int> prev=dp[i][j].second;
			if(prev==make_pair(i-1,j-1))
			{
				c+=a[i-1];
			}
			curr=prev;
		}
		reverse(c.begin(),c.end());
		cout<<c<<'\n';
		
	}
}
