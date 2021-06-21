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
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //less_equal for multiset
#define int long long 
#define ll int
#define all(a) a.begin(),a.end()    
#define rev(a) a.rbegin(),a.rend()   
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)
const double pi=acosl(-1);



void solve()
{
    

    
    
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt=1;
    //cin>>tt;    
    while(tt--)
    {
        solve();
    }    
}










//int dx[] = {+1,-1,+0,+0,-1,-1,+1,+1}; // Eight Directions
//int dy[] = {+0,+0,+1,-1,+1,-1,-1,+1}; // Eight Directions
//int dx[]= {-2,-2,-1,1,-1,1,2,2}; // Knight moves
//int dy[]= {1,-1,-2,-2,2,2,-1,1}; // Knight moves
// For (a^b)%mod, where b is large, replace b by b%(mod-1)..{because we solve this by introducing log ..do same for general cases}
// a+b = (a|b)+(a&b)
// a+b = 2*(a&b)+(a^b)
