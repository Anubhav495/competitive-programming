//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include <algorithm>
#include <array>
#include <cassert>
//#include <chrono>
#include <cmath>
//#include <cstring>
//#include <functional>
//#include <iomanip>
#include <iostream>
#include <map>
//#include <numeric>
//#include <queue>
//#include <random>
#include <set>
#include <vector>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
#define int long long 
#define ll int
#define all(a) a.begin(),a.end()    
#define rev(a) a.rbegin(),a.rend()    
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //less_equal for multiset
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)
const double pi=acosl(-1);

const int mod=1e9+7;

vector<vector<int>> mul(vector<vector<int>> first,vector<vector<int>> second,int dem)
{
    vector<vector<int>> res(dem,vector<int> (dem));
    fi(0,dem)
    {
        fj(0,dem)
        {
            fk(0,dem)
            {
                res[i][j]+=(first[i][k]*second[k][j])%mod;
                res[i][j]+=mod;
                res[i][j]%=mod;
            }
        }
    }
    return res;
}

int binpow(vector<vector<int>> base,int m,vector<int> init,int dem)
{
    vector<vector<int>> res(dem,vector<int> (dem));
    fi(0,dem)
    {
        res[i][i]=1;
    }
    while(m)
    {
        if(m%2)
        {
            res=mul(base,res,dem);
        }
        base=mul(base,base,dem);
        m=m>>1;
    }
    int val = 0;
    for(int i=0;i<dem;i++)
        val=(val+res[0][i]*init[dem-i-1]%mod)%mod;
    return (val+mod)%mod;
}

void solve()
{
    

    
    
    
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










//int dx[] = {+1,-1,+0,+0,-1,-1,+1,+1}; // Eight Directions
//int dy[] = {+0,+0,+1,-1,+1,-1,-1,+1}; // Eight Directions
//int dx[]= {-2,-2,-1,1,-1,1,2,2}; // Knight moves
//int dy[]= {1,-1,-2,-2,2,2,-1,1}; // Knight moves
// For (a^b)%mod, where b is large, replace b by b%(mod-1).
// a+b = (a|b)+(a&b)
// a+b = 2*(a&b)+(a^b)
