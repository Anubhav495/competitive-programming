#include<bits/stdc++.h>
#define ll long long 
using namespace std;
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)

const int mxn=1e6;
int s[mxn],p[mxn];
//before doing any operation find the reprsentative of the set

void make_set(int node)
{
	p[node]=node;
	s[node]=1;
}

int find(int node)
{
	if(p[node]==node)
	{
		return node;
	}
	else
	{
		return p[node]=find(p[node]);
	}
}

void join(int a,int b)
{
	a=p[a];
	b=p[b];
	if(a!=b)
	{
		if(s[a]<s[b])
		{
			swap(a,b);
		}
		p[b]=a;
		s[a]+=s[b];
	}
}

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
		int a[n];
		fi(0,n) cin>>a[i];
	}
		
}
