#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
#define int long long 
#define ll long long
#define all(a) a.begin(),a.end()    
#define rev(a) a.rbegin(),a.rend()    
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //less_equal for multiset
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)
//const double pi=acosl(-1);

template<typename T>
struct matrix {
    int N, M;
    std::vector<T> data;
 
    matrix(int _N, int _M, T value = T{}) : N(_N), M(_M), data(N * M, value) {}
 
    typename std::vector<T>::iterator operator[](int i) {
        return data.begin() + i * M;
    }
    typename std::vector<T>::const_iterator operator[](int i) const {
        return data.begin() + i * M;
    }
 
    friend matrix<T> operator * (const matrix<T>& a, const matrix<T>& b) {
        assert(a.M == b.N);
        matrix<T> res(a.N, b.M);
        for (int i = 0; i < a.N; i++)
            for (int k = 0; k < a.M; k++)
                for (int j = 0; j < b.M; j++)
                    res[i][j] += a[i][k] * b[k][j];
        return res;
    }
 
    friend std::vector<T> operator * (const std::vector<T>& v, const matrix<T>& m) {
        assert(sz(v) == m.N);
        std::vector<T> res(m.M);
        for (int i = 0; i < m.N; i++)
            for (int j = 0; j < m.M; j++)
                res[j] += v[i] * m[i][j];
        return res;
    }
 
    friend std::vector<T> operator * (const matrix<T>& m, const std::vector<T>& v) {
        assert(m.M == (int)v.size());
        std::vector<T> res(m.N);
        for (int i = 0; i < m.N; i++)
            for (int j = 0; j < m.M; j++)
                res[i] += m[i][j] * v[j];
        return res;
    }
 
    matrix pow(int64_t e) const {
        assert(N == M);
        if (e == 0) return matrix<T>(N, N, 0, 1);
        if (e&1) return *this * pow(e - 1);
        return (*this * *this).pow(e / 2);
    }
 
    friend void row_reduce(matrix<T> &m) {
        int rank = 0;
        for (int j = 0; j < m.M && rank < m.N; j++) {
            for (int i = rank; i < m.N; i++) {
                if (m[i][j] != 0) {
                    swap_ranges(m[rank], m[rank] + m.M, m[i]);
                    break;
                }
            }
            if (m[rank][j] == 0)
                continue;
 
            T inv = 1 / m[rank][j];
            for (int k = j; k < m.M; k++)
                m[rank][k] *= inv;
 
            for (int i = 0; i < m.N; i++) {
                if (i != rank) {
                    T c = m[i][j];
                    for (int k = j; k < m.M; k++)
                        m[i][k] -= c * m[rank][k];
                }
            }
            rank++;
        }
 
        m.N = rank;
        m.data.resize(m.N * m.M);
    }
 
    friend std::ostream& operator << (std::ostream& os, const matrix<T>& m) {
        for (int i = 0; i < m.N; i++) {
            os << (i ? i < m.N - 1 ? "\u2503" : "\u2517" : "\n\u250F");
            for (int j = 0; j < m.M; j++)
                os << std::setw(12) << m[i][j];
            os << "  " << (i ? i < m.N - 1 ? "\u2503" : "\u251B" : "\u2512") << "\n";
        }
        return os;
    }
};

using M = matrix<int>;

void solve()
{
    //each operation or equation can be represented by operation matrix
    //and multiplying by that operation matrix means we performed the operation



    
    
}

signed main()
{
    FAST;
    int tt=1;
    //cin>>tt;    
    while(tt--)
    {
        solve();
    }    
}
