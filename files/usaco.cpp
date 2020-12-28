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
	int n;
	cin>>n;
	vector<ar<int,3>> a(n);
	fi(0,n)
	{
		char c;
		cin>>c;
		int dir=0;
		if(c=='N')
		{
			dir=1;
		}
		else
		{
			dir=-1;
		}
		int x,y;
		cin>>x>>y;
		a[i]={dir,x,y};
	}
	auto find_intersect=[&](int dir,int x,int y)
	{
		vector<ar<int,3>> temp=a;
		vector<ar<int,3>> ret;
		if(dir==1)
		{
			//moving north
			sort(all(temp),[&](ar<int,3> first,ar<int,3> second)
			{
				return first[2]<second[2];
			});
		}
		else
		{
			//moving east
			sort(all(temp),[&](ar<int,3> first,ar<int,3> second)
			{
				return first[1]<second[1];
			});
		}
		fi(0,n)
		{
			if(temp[i][0]==dir)
			{
				if(dir==1)
				{
					if(temp[i][1]==x&&temp[i][2]>y) ret.pb(temp[i]);
				}
				else
				{
					if(temp[i][2]==y&&temp[i][1]>x) ret.pb(temp[i]);
				}
			}
			if(temp[i][0]!=dir)
			{
				if(dir==1)
				{
					if(temp[i][2]<y) continue;
					//i am moving north
					if(temp[i][1]<=x)
					{
						int my_time=temp[i][2]-y;
						int his_time=x-temp[i][1];
						if(my_time>his_time)
						{
							ret.pb(temp[i]);
						}
					}
				}
				else
				{
					if(temp[i][1]<x) continue;
					// i am moving east
					if(temp[i][2]<=y)
					{
						int my_time=temp[i][1]-x;
						int his_time=y-temp[i][2];
						if(my_time>his_time)
						{
							ret.pb(temp[i]);
						}
					}
				}
			}
		}
		return ret;
	};
	fi(0,n)
	{
		int dir=a[i][0];
		vector<ar<int,3>> ret=find_intersect(a[i][0],a[i][1],a[i][2]);
		if((int)ret.size()==0)
		{
			cout<<"Infinity\n";
			continue;
		}
		//cout<<ret.size()<<'\n';
		//cout<<ret[0][1]<<' '<<ret[0][2]<<'\n';
		bool done=false;
		//int ans=INF;
		for(auto j:ret)
		{
			vector<ar<int,3>> ret1=find_intersect(j[0],j[1],j[2]);
			//cout<<"ret1: "<<ret1.size()<<'\n';
			if(ret1.size()==0)
			{
				done=true;
				if(dir==1)
				{
					cout<<j[2]-a[i][2]<<'\n';
				}
				else
				{
					cout<<j[1]-a[i][1]<<'\n';
				}
				break;
			}
			if(dir==1)
			{
				sort(all(ret1),[&](ar<int,3> first,ar<int,3> second)
				{
					return first[2]<second[2];
				});
			}
			else
			{
				sort(all(ret1),[&](ar<int,3> first,ar<int,3> second)
				{
					return first[1]<second[1];
				});
			}
			bool pass=false;
			for(auto k:ret1)
			{
				if(dir==1)
				{
					//i am moving north
					if(k[1]<a[i][1])
					{
						//can pass
						pass=true;
					}
				}
				else
				{
					// i am moving east
					if(k[2]<a[i][2])
					{
						//can pass
						pass=true;
					}
				}
			}
			if(!pass)
			{
				done=true;
				if(dir==1)
				{
					cout<<j[2]-a[i][2]<<'\n';
				}
				else
				{
					cout<<j[1]-a[i][1]<<'\n';
				}
				break;
			}
			
		}
		if(done)
		{
			//cout<<ans<<'\n';
			continue;
		}
		cout<<"Infinity\n";
		
	}
	
	
	
} 

 
signed main() {
	//freopen("bteams.in", "r", stdin);
	//freopen("bteams.out", "w", stdout);
	FAST;
	solve();
	
	
}
 
