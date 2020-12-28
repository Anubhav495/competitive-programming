#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define all(a) a.begin(),a.end()	
#define rev(a) a.rbegin(),a.rend()	
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //less_equal for multiset
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)
const double pi=acosl(-1);

int main(int argc,char* argv[])
{
	FAST;
	srand(atoi(argv[1]));
	cout<<1<<'\n';
	long long n=1+rand()%10;
	cout<<n<<'\n';
	fi(0,n)
	{
		cout<<1+rand()%n<<' ';
	}
	cout<<'\n';
	
	
	
}


