#include<bits/stdc++.h>
#define ll long long 
using namespace std;
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)

const int mxn=1e6+1;
vector<int> pow2(mxn+1);
vector<vector<int>> table (mxn+1,vector<int> (22));

int query(int l,int r)
{
	int dist=pow2[r-l+1];
	int pow=(1<<dist);
	return min(table[l][dist],table[r-pow+1][dist]);
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
		int n,q;
		cin>>n>>q;
		int a[n];
		fi(0,n)cin>>a[i];
		
		//max powers of 2 till index i
		pow2[1]=0;
		fi(2,n+1)
		{
			pow2[i]=pow2[i/2]+1;
		}
		
		//creating table
		fj(0,21)
		{
			fi(0,n)
			{
				if(j==0)
				{
					table[i][0]=a[i];
					continue;
				}
				if(i+(1<<j)>n)continue;
				table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
			}
		}
		//queries
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			--x,--y;
			cout<<query(x,y)<<'\n';
		}
	}
		
}

