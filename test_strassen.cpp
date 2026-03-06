// ======================================================
//  Author       : spexcher | Gourab Modak
//  Created      : 03.03.2026 at 19:56:49
//  Contact      : spexcher@gmail.com
//  Linktree     : https://linktr.ee/spexcher/
//  GitHub       : https://github.com/spexcher/
//  LinkedIn     : https://www.linkedin.com/in/gourabmodak/
//  YouTube      : https://www.youtube.com/@spexcher
//
//  Happy Coding! Build, learn, and ship with confidence.
// ======================================================

// Pragmas
// #pragma GCC target("avx2")
#pragma GCC optimization("O3")
// #pragma GCC optimization ("O2")
//  #pragma GCC target("unroll-loops")

// Includes and namespaces
#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set and Ordered Map
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class value, class cmp = less_equal<key>>
using omap = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// 1D Stuff
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i64 = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;

// 2D Vectors
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvb = vector<vb>;
using vvc = vector<vc>;
using vvs = vector<vs>;
using vvpii = vector<vpii>;
using vvpll = vector<vpll>;

// Maps
using mii = map<int, int>;
using mci = map<char, int>;
using msi = map<string, int>;
using umii = unordered_map<int, int>;
using umci = unordered_map<char, int>;
using umsi = unordered_map<string, int>;
using mll = map<ll, ll>;
using mcll = map<char, ll>;
using msll = map<string, ll>;
using umll = unordered_map<ll, ll>;
using umcll = unordered_map<char, ll>;
using umsll = unordered_map<string, ll>;

// Sets
using si = set<int>;
using sll = set<ll>;
using sc = set<char>;

// Heaps
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T>;

// Shorthands
#define F first
#define S second
#define eb emplace_back
#define pb push_back
#define ppb pop_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// Functions
#define sqrt(x) sqrtl((x))
#define ceil(x) ceill((x))
#define abs(x) labs((x))
#define floor(x) floorl((x))
#define ceildiv(a, b) ((a + b - 1) / b)
#define sz(x) (ll) x.size()
#define getunique(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define print(x) cout << x << " "
#define printsp(x) cout << x << " "
#define println(x) cout << x << "\n"
#define upper(s1) transform(s1.begin(), s1.end(), s1.begin(), ::toupper)
#define lower(s1) transform(s1.begin(), s1.end(), s1.begin(), ::tolower)
#define sum(v) accumulate(all(v), 0ll)
#define maxe(v) *max_element(v.begin(), v.end())
#define mine(v) *min_element(v.begin(), v.end())

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cout << fixed << setprecision(5)

// Prints
#define py cout << "YES\n"
#define pm cout << "-1\n"
#define pn cout << "NO\n"
#define pm cout << "-1\n"
#define pl cout << '\n'
#define nl '\n'
#define sp ' '

// Returns
#define r0 return 0
#define r1 return 1
#define rt return true
#define rf return false

// Loops
#define ff(i, k, n) for (int i = k; i <= n; i++)
#define fr(i, k, n) for (int i = k; i >= n; i -= 1)
#define rep(i, k, n, s) for (int i = k; i <= n; i += s)
#define per(i, k, n, s) for (int i = k; i >= n; i -= s)

/* ===================== RAW INPUT OVERLOADS ===================== */

template <class A, class B>
istream &operator>>(istream &in, pair<A, B> &p)
{
    return in >> p.first >> p.second;
}

template <class T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <class T>
istream &operator>>(istream &in, vector<vector<T>> &v)
{
    for (auto &r : v)
        for (auto &x : r)
            in >> x;
    return in;
}

template <class T>
istream &operator>>(istream &in, deque<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <class T, size_t N>
istream &operator>>(istream &in, array<T, N> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
}
/* ===================== RAW OUTPUT OVERLOADS ===================== */

template <class A, class B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << p.first << " " << p.second;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &x : v)
        os << x << " ";
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (auto &r : v)
    {
        for (auto &x : r)
            os << x << " ";
        os << '\n';
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const deque<T> &v)
{
    for (auto &x : v)
        os << x << " ";
    return os;
}

template <class T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &a)
{
    for (auto &x : a)
        os << x << " ";
    return os;
}

//--------------Snippet area-------------

template <typename T>
vector<vector<T>> MatrixMultiply(const vector<vector<T>> &a,
                                 const vector<vector<T>> &b,
                                 int n, int l, int m)
{
    vector<vector<T>> c(n, vector<T>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < l; k++)
                c[i][j] += a[i][k] * b[k][j];

    return c;
}

// Strassen's Algorithm
template <typename T>
vector<vector<T>> Strassen(const vector<vector<T>> &a,
                           const vector<vector<T>> &b,
                           int n, int l, int m)
{

    if (n == 1 || l == 1 || m == 1)
        return MatrixMultiply(a, b, n, l, m);

    vector<vector<T>> c(n, vector<T>(m, 0));

    int adjN = (n >> 1) + (n & 1);
    int adjL = (l >> 1) + (l & 1);
    int adjM = (m >> 1) + (m & 1);

    // Initialize submatrices
    vector<vector<vector<vector<T>>>> As(2,
                                         vector<vector<vector<T>>>(2,
                                                                   vector<vector<T>>(adjN, vector<T>(adjL, 0))));

    vector<vector<vector<vector<T>>>> Bs(2,
                                         vector<vector<vector<T>>>(2,
                                                                   vector<vector<T>>(adjL, vector<T>(adjM, 0))));

    // Fill A submatrices
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            for (int i = 0; i < adjN; i++)
                for (int j = 0; j < adjL; j++)
                {
                    int I = i + x * adjN;
                    int J = j + y * adjL;
                    if (I < n && J < l)
                        As[x][y][i][j] = a[I][J];
                }

    // Fill B submatrices
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            for (int i = 0; i < adjL; i++)
                for (int j = 0; j < adjM; j++)
                {
                    int I = i + x * adjL;
                    int J = j + y * adjM;
                    if (I < l && J < m)
                        Bs[x][y][i][j] = b[I][J];
                }

    // Auxiliary matrices S
    vector<vector<vector<T>>> s(10);

    s[0] = vector<vector<T>>(adjL, vector<T>(adjM));
    s[1] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[2] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[3] = vector<vector<T>>(adjL, vector<T>(adjM));
    s[4] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[5] = vector<vector<T>>(adjL, vector<T>(adjM));
    s[6] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[7] = vector<vector<T>>(adjL, vector<T>(adjM));
    s[8] = vector<vector<T>>(adjN, vector<T>(adjL));
    s[9] = vector<vector<T>>(adjL, vector<T>(adjM));

    // Compute S matrices
    for (int i = 0; i < adjL; i++)
        for (int j = 0; j < adjM; j++)
        {
            s[0][i][j] = Bs[0][1][i][j] - Bs[1][1][i][j];
            s[3][i][j] = Bs[1][0][i][j] - Bs[0][0][i][j];
            s[5][i][j] = Bs[0][0][i][j] + Bs[1][1][i][j];
            s[7][i][j] = Bs[1][0][i][j] + Bs[1][1][i][j];
            s[9][i][j] = Bs[0][0][i][j] + Bs[0][1][i][j];
        }

    for (int i = 0; i < adjN; i++)
        for (int j = 0; j < adjL; j++)
        {
            s[1][i][j] = As[0][0][i][j] + As[0][1][i][j];
            s[2][i][j] = As[1][0][i][j] + As[1][1][i][j];
            s[4][i][j] = As[0][0][i][j] + As[1][1][i][j];
            s[6][i][j] = As[0][1][i][j] - As[1][1][i][j];
            s[8][i][j] = As[0][0][i][j] - As[1][0][i][j];
        }

    // P matrices
    vector<vector<vector<T>>> p(7);

    p[0] = Strassen(As[0][0], s[0], adjN, adjL, adjM);
    p[1] = Strassen(s[1], Bs[1][1], adjN, adjL, adjM);
    p[2] = Strassen(s[2], Bs[0][0], adjN, adjL, adjM);
    p[3] = Strassen(As[1][1], s[3], adjN, adjL, adjM);
    p[4] = Strassen(s[4], s[5], adjN, adjL, adjM);
    p[5] = Strassen(s[6], s[7], adjN, adjL, adjM);
    p[6] = Strassen(s[8], s[9], adjN, adjL, adjM);

    // Combine results
    for (int i = 0; i < adjN; i++)
        for (int j = 0; j < adjM; j++)
        {
            if (i < n && j < m)
                c[i][j] = p[4][i][j] + p[3][i][j] - p[1][i][j] + p[5][i][j];

            if (i < n && j + adjM < m)
                c[i][j + adjM] = p[0][i][j] + p[1][i][j];

            if (i + adjN < n && j < m)
                c[i + adjN][j] = p[2][i][j] + p[3][i][j];

            if (i + adjN < n && j + adjM < m)
                c[i + adjN][j + adjM] =
                    p[4][i][j] + p[0][i][j] - p[2][i][j] - p[6][i][j];
        }

    return c;
}

//--------------End Snippet area---------

// Constants
#define PI 3.1415926535897932384626
#define linf 1e18
#define inf INT_MAX
#define EPS 1e-9

#define int long long

void solve();
signed main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    ff(i, 1, t)
        solve();
    return 0;
}

void solve()
{
    vector<vector<long double>> A = {{1.0, 2, 3}, {4, 5, 6}};
    vector<vector<long double>> B = {{7, 8}, {9.0, 10}, {11, 12}};

    vector<vector<long double>> C = Strassen(A, B, 2, 3, 2);
    println(C);
}
// ======================================================
//  Thank You for Viewing
//  Hope this code helped you today
//  Reminder    : It's a game - we are awarded points.
//                   First to reach 1,000 points wins a tank!
//  Inspiration : Life is beautiful (1997)
//
//  Have a great day & happy coding.
// ======================================================