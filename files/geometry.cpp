#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define int long long 
#define ll long long
#define all(a) a.begin(),a.end()	
#define rev(a) a.rbegin(),a.rend()	
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //less_equal for multiset
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)
const double pi=acosl(-1);

struct p
{
	int x,y;
	void read()
	{
		cin>>x>>y;
	}
	p operator - (p second)
	{
		return p{x-second.x,y-second.y};
	}
	void operator -= (p second)
	{	
		x=x-second.x;
		y=y-second.y;
	}
	int operator * (p second)
	{
		//returns cross product (2*area)
		return (x*second.y-y*second.x);
	}
};

struct line
{
	int x1,y1,x2,y2;
	void read()
	{
		cin>>x1>>y1>>x2>>y2;
	}

};

bool intersect(line a,line b)
{
	p p1,p2,p3,p4;
	//line a
	p1={a.x1,a.y1};
	p2={a.x2,a.y2};
	//line b
	p3={b.x1,b.y1};
	p4={b.x2,b.y2};

	int first=(p3-p1)*(p3-p2);
	int second=(p4-p1)*(p4-p2);
	if((first>0&&second>0)||(first<0&&second<0))
	{
		return false;
	}
	first=(p3-p1)*(p4-p1);
	second=(p3-p2)*(p4-p2);
	if((first>0&&second>0)||(first<0&&second<0))
	{
		return false;
	}
	//parallel case
	if((p2-p1)*(p4-p3)==0)
	{
		fi(0,2)
		{
			if((max(p1.y,p2.y)<min(p3.y,p4.y))||(max(p1.x,p2.x)<min(p3.x,p4.x)))
			{
				return false;
			}
			swap(p1,p3);
			swap(p2,p4);
		}
	}
	return true;
}

const int mod=1e9+7;

void solve()
{
	//line intersection
	line a,b;
	a.read();b.read();
	if(intersect(a,b))
	{
		cout<<"YES\n";
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
