#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define ar array

const int mxn=4e5+2;
const int INF=1e15;
int n;
struct node
{
    ll s,m,lz=0,mini;
} st[1<<20];

void push(int node) {
    st[node*2+1].m += st[node].lz;
    st[node*2+2].m += st[node].lz;
    st[node*2+1].mini += st[node].lz;
    st[node*2+2].mini += st[node].lz;
    st[node*2+1].lz += st[node].lz;
    st[node*2+2].lz += st[node].lz;
    st[node].lz = 0;
}

void rupdate(int l,int r,int val,int l2=0,int r2=n-1,int ci=0)
{
    if(l>r) return ;
    if(l==l2&&r==r2)
    {
        st[ci].m+=val;
        st[ci].mini+=val;
        st[ci].lz+=val;
        return ;
    }
    push(ci);
    int mid=(l2+r2)/2;

    rupdate(l,min(r,mid),val,l2,mid,2*ci+1);
    rupdate(max(l,mid+1),r,val,mid+1,r2,2*ci+2);

    st[ci].m=max(st[2*ci+1].m,st[2*ci+2].m);
    st[ci].mini=min(st[2*ci+1].mini,st[2*ci+2].mini);
}

void update(int l,int r,int val,int l2=0,int r2=n-1,int ci=0)
{
    if(l>r) return ;
    if(l==l2&&r==r2)
    {
        st[ci].m=val;
        st[ci].mini=val;
        return ;
    }
    int mid=(l2+r2)/2;
    update(l,min(r,mid),val,l2,mid,2*ci+1);
    update(max(l,mid+1),r,val,mid+1,r2,2*ci+2);

    st[ci].m=max(st[2*ci+1].m,st[2*ci+2].m);
    st[ci].mini=min(st[2*ci+1].mini,st[2*ci+2].mini);
}

int query(int l1,int r1,int type,int l2=0,int r2=n-1,int ci=0)
{
    if(l1<=l2&&r1>=r2)
    {
        if(type==1)
            return st[ci].m;
        else return st[ci].mini;
    }
    if(l2>r1||r2<l1)
    {
        if(type==1)
            return -INF;
        else 
            return INF;
    }
    push(ci);
    int mid=(l2+r2)/2;
    if(type==1)
        return max(query(l1,r1,type,l2,mid,2*ci+1),query(l1,r1,type,mid+1,r2,2*ci+2));
    else
        return min(query(l1,r1,type,l2,mid,2*ci+1),query(l1,r1,type,mid+1,r2,2*ci+2));
}

void build(vector<int> &a) {
    fi(0,n)
    {
        update(i,i,a[i]);
    }
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
		vector<int> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		build(a);
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			// range minimum query
			cout<<query(--x,--y,type)<<'\n';
		}
		
	}
		
}

