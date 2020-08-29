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
		vector<pair<int,int>> pairs;
		int q;
		cin>>q;
		fi(0,q)
		{
			int x,y;
			cin>>x>>y;
			pairs.pb({x,y});
		}
		vector<int> p(n),c(n);
		vector<pair<char,int>> temp(n);
		fi(0,n)
		{
			temp[i]={s[i],i};
		}
		sort(temp.begin(),temp.end());
		int count=0;
		vector<vector<int>> C(22,vector<int> (n));
		C[0][temp[0].second]=count;
		c[temp[0].second]=count;
		p[0]=temp[0].second;
		fi(1,n)
		{
			if(temp[i-1].first!=temp[i].first)
			{
				count++;
			}
			c[temp[i].second]=count;
			C[0][temp[i].second]=count;
			p[i]=temp[i].second;
		}
		//return 0;
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
			C[k+1][index]=count;
			p[0]=index;
			fi(1,n)
			{
				if(trans[i-1].first!=trans[i].first)
				{
					count++;
				}
				index=trans[i].second;
				c[index]=count;
				C[k+1][index]=count;
				p[i]=index;
			}
			k++;
		}
		//sparse table can be created!!!
		sort(pairs.begin(),pairs.end(),[&](pair<int,int> a,pair<int,int> b)
		{
			int l1=a.second-a.first+1;
			int l2=b.second-b.first+1;
			int l=min(l1,l2);
			int k1=floor(log2(l));
			int y=C[k1][(a.first-1+l-(1<<k1))%(n)];
			int x=C[k1][a.first-1];
			pair<int,int> first={x,y};
			y=C[k1][(b.first-1+l-(1<<k1))%(n)];
			x=C[k1][b.first-1];
			pair<int,int> second={x,y};
			if(first==second)
			{
				if(l1!=l2)
				{
					return l1<l2;
				}
				else
				{
					return a<b;
				}
			}
			else
			{
				return first<second;
			}
		});
		fi(0,q)
		{
			cout<<pairs[i].first<<' '<<pairs[i].second<<'\n';
		}
	}
}
