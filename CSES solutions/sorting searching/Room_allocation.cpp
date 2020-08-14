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
#define f first
#define s second
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
		vector<pair<pair<int,int>,int>> a(n);
		fi(0,n)
		{
			cin>>a[i].f.f>>a[i].f.s;
			a[i].s=i;
		}
		sort(a.begin(),a.end());
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		int room=0;
		int ans[n];
		fi(0,n)
		{
			if(q.empty())
			{
				ans[a[i].s]=room;
				q.push({a[i].f.s,room});
				room++;
				continue;
			}
			if(q.top().f<a[i].f.f)
			{
				auto x=q.top();
				q.pop();
				q.push({a[i].f.s,x.s});
				ans[a[i].s]=x.s;
			}
			else
			{
				ans[a[i].s]=room;
				q.push({a[i].f.s,room});
				room++;
			}
		}
		cout<<*max_element(ans,ans+n)+1<<'\n';
		for(auto i:ans)
		{
			cout<<i+1<<' ';
		}
	}
}
