#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<ll, ll>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 2e5 + 5;

using ftype = array<ll, 3>;

ftype t[4 * MAXN];
ll add[4 * MAXN], ass[4 * MAXN]; // LLONG_MAX for no pending
ftype e = {0, LLONG_MIN, LLONG_MAX}; // Identity Element

ftype combine(ftype L, ftype R)
{
    ftype res;
    res[0] = L[0] + R[0];
    res[1] = max(L[1], R[1]);
    res[2] = min(L[2], R[2]);
    return res;
}

void push(int v, int tl, int tr)
{
    int tm = (tl + tr) >> 1;
    // first process assignment
    if(ass[v] != LLONG_MAX)
    {
        ass[v << 1] = ass[v];
        add[v << 1] = 0;
        ass[v << 1 | 1] = ass[v];
        add[v << 1 | 1] = 0;

        t[v << 1] = {ass[v] *(tm - tl + 1), ass[v], ass[v]};
        t[v << 1 | 1] = {ass[v] *(tr - tm), ass[v], ass[v]};

        ass[v] = LLONG_MAX;
    }

    // now process addition
    t[v << 1][0] += add[v] * (tm - tl + 1);
    t[v << 1][1] += add[v];
    t[v << 1][2] += add[v];
    t[v << 1 | 1][0] += add[v] * (tr - tm);
    t[v << 1 | 1][1] += add[v];
    t[v << 1 | 1][2] += add[v];

    add[v << 1] += add[v];
    add[v << 1 | 1] += add[v];

    add[v] = 0;
}

void build(int v, int tl, int tr, vector<int> &arr)
{
    if(tl == tr)
        t[v] = {arr[tl], arr[tl], arr[tl]}, add[v] = 0, ass[v] = LLONG_MAX;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, arr);
        build(v << 1 | 1, tm + 1, tr, arr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
        add[v] = 0, ass[v] = LLONG_MAX;
    }
}

// Point query
ftype querypt(int v, int tl, int tr, int pos)
{
    if(tl == tr)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        if(pos <= tm)
            return querypt(v << 1, tl, tm, pos);
        else
            return querypt(v << 1 | 1, tm + 1, tr, pos);
    }
}

void radd(int v, int tl, int tr, int l, int r, ll val)
{
    if(l > r) return;

    if(tl == l && tr == r)
    {
        t[v][0] += val * (tr - tl + 1);
        t[v][1] += val;
        t[v][2] += val;
        add[v] += val;
    }
    else
    {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        radd(v << 1, tl, tm, l, min(r, tm), val);
        radd(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void rmax(int v, int tl, int tr, int l, int r, ll val)
{
    if(tl > r || tr < l)
        return;

    if(tl != tr) push(v, tl, tr);

    if(t[v][2] > val)
        return;

    if(l <= tl && tr <= r)
    {
        if(t[v][1] <= val)
        {
            // assign
            t[v][0] = val * (tr - tl + 1);
            t[v][1] = t[v][2] = val;
            ass[v] = val;
            add[v] = 0;
            return;
        }
    }
    int tm = (tl + tr) >> 1;
    rmax(v << 1, tl, tm, l, r, val);
    rmax(v << 1 | 1, tm + 1, tr, l, r, val);
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}

void rmin(int v, int tl, int tr, int l, int r, ll val)
{
    if(tl > r || tr < l)
        return;

    if(tl != tr) push(v, tl, tr);

    if(t[v][1] < val)
        return;

    if(l <= tl && tr <= r)
    {
        if(t[v][2] >= val)
        {
            // assign
            t[v][0] = val * (tr - tl + 1);
            t[v][1] = t[v][2] = val;
            ass[v] = val;
            add[v] = 0;
            return;
        }
    }
    int tm = (tl + tr) >> 1;
    rmin(v << 1, tl, tm, l, r, val);
    rmin(v << 1 | 1, tm + 1, tr, l, r, val);
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}


void cp()
{
    int n, m;
    cin >> n;
    vector<int> A(n), T(n);
    for(int i = 0; i < n; i++)
        cin >> A[i] >> T[i];
    cin >> m;
    vector<int> X(m);
    for(int &x : X)
        cin >> x;

    build(1, 0, m - 1, X);
    for(int i = 0; i < n; i++)
    {
        if(T[i] == 1)
            radd(1, 0, m - 1, 0, m - 1, A[i]);
        else if(T[i] == 2)
            rmax(1, 0, m - 1, 0, m - 1, A[i]);
        else
            rmin(1, 0, m - 1, 0, m - 1, A[i]);

    }

    for(int i = 0; i < m; i++)
        cout << querypt(1, 0, m - 1, i)[0] << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
