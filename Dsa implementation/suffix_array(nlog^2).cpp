#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long int 
#define ar array
#define pb push_back
#define fi(a,b) for(ll i=a;i<(b);i++)
#define fj(a,b) for(ll j=a;j<(b);j++)
#define fk(a,b) for(ll k=a;k<(b);k++)
#define lb lower_bound
#define ub upper_bound
//hash base 177013

//finds suffixes of a string sorted in lexicographically sorted order


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
		string s;
		cin>>s;
		s+="$";
		int n=s.size();
		vector<int> p(n),c(n);
		vector<pair<char,int>> temp(n);
		fi(0,n)
		{
			temp[i]={s[i],i};
		}
		sort(temp.begin(),temp.end());
		int count=0;
		c[temp[0].second]=count;
		p[0]=temp[0].second;
		fi(1,n)
		{
			if(temp[i-1].first!=temp[i].first)
			{
				count++;
			}
			c[temp[i].second]=count;
			p[i]=temp[i].second;
		}
		int k=0;
 		while((1<<k)<n)
 		{
			vector<pair<pair<int,int>,int>> trans(n);
			fi(0,n)
			{
				trans[i]={{c[i],c[(i+(1<<k))%n]},i};
			}
			sort(trans.begin(),trans.end());
			count=0;
			int index=trans[0].second;
			c[index]=count;
			p[0]=index;
			fi(1,n)
			{
				if(trans[i-1].first!=trans[i].first)
				{
					count++;
				}
				index=trans[i].second;
				c[index]=count;
				p[i]=index;
			}
			k++;
		}
		fi(0,n)
		{
			cout<<p[i]<<' ';
		}
		cout<<'\n';
	}
}
