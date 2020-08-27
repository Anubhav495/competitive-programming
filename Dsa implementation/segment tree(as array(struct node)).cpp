#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define ar array

const int mxn=2e5+2;
int n,q;
vector<ll> a(mxn);
struct node
{
	ll s,m,lz;
} st[1<<19];


void update(int index,int val,int l2=0,int r2=n-1,int ci=0)
{
	if(l2==r2)
	{
		st[ci].m=val;
		return ;
	}
	int mid=(l2+r2)/2;
	if(index<=mid)
		update(index,val,l2,mid,2*ci+1);
	else
	{
		update(index,val,mid+1,r2,2*ci+2);
	}
	st[ci].s=st[2*ci+1].s+st[2*ci+2].s;
	st[ci].m=min(st[2*ci+1].m,st[2*ci+2].m);
}
	
int query(int l1,int r1,int l2=0,int r2=n-1,int ci=0)
{
	if(l1<=l2&&r1>=r2)
	{
		return st[ci].m;
	}
	if(l2>r1||r2<l1)
	{
		return INT_MAX;
	}
	int mid=(l2+r2)/2;
	
	return min(query(l1,r1,l2,mid,2*ci+1),query(l1,r1,mid+1,r2,2*ci+2));
}
int main()
{
	//#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	//#endif
	
	//int t;
	//cin>>t;
	//while(t--)
	{
		cin>>n>>q;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			update(i,a[i]);
			
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			// range minimum query
			cout<<query(--x,--y)<<'\n';
		}
		
	}
		
}

