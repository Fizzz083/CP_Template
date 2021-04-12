// probem : http://acm.hdu.edu.cn/showproblem.php?pid=3948

// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * ((b) / gcd(a, b)))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define lllim 2147483648
#define Pi 2 * acos(0.0)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mem(a, b) memset(a, b, sizeof(a))
#define fill_(a, b) fill(a, a + n, b);
#define MOD 1000000007
#define fast_cin                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define filein freopen("input.txt", "r", stdin)
#define D(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define case        \
    int t, cas = 1; \
    cin >> t;       \
    while (t--)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, n, a) for (int i = n; i >= a; i--)
#define sim template <class T

/*------------------------------Graph Moves----------------------------*/
//const int fx[] = {+1, -1, +0, +0};
//const int fy[] = {+0, +0, +1, -1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

inline ll _gcd(ll a, ll b) {a = abs(a);b = abs(b);if (!b)return a;return _gcd(b, a % b);}
inline ll _pow(ll a, ll y) {ll z = 1;rep(i, 1, y){z *= a;}return z;}
inline ll _lcm(ll a, ll b) {a = abs(a);b = abs(b);return (a / _gcd(a, b)) * b;}
inline ll bigmod(ll n, ll m, ll mod) {ll ret = 1, a = n % mod;while (m){if (m & 1)ret = (ret * a) % mod;m >>= 1;a = (a * a) % mod;}ret %= mod;return ret;}
sim > void ckmin(T &a, const T &b) {a = b < a ? b : a;}
sim > void ckmax(T &a, const T &b) {a = b > a ? b : a;}

///.............................input.................................///
sim > void readvec(std::vector<T> &v, const int n) {rep(i, 0, n){T p;std::cin >> p;v.pb(p);}}
///...........................input end...............................///

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1000001;

///............................sieve, nCr, Fact_invFact...................///

vector<int> pr;
bool mark[maxn];
ll mod = 1e9 + 7;
ll fib[maxn];
ll finv[maxn];
ll inv[maxn];
void si();
void calc_fact_invfact();
ll nCr(ll n, ll r);

///.................................Number theory end.........................///


 
struct Node {
    int length;
    map<char, int> edges;
    int suffix;
 
    Node(int l) : length(l), suffix(0) {
        /* empty */
    }
 
    Node(int l, const std::map<char, int>& m, int s) : length(l), edges(m), suffix(s) {
        /* empty */
    }
};
 
constexpr int evenRoot = 0;
constexpr int oddRoot = 1;
 
vector<Node> eertree(const string& s) {
    vector<Node> tree = {
        Node(0, {}, oddRoot),
        Node(-1, {}, oddRoot)
    };
    int suffix = oddRoot;
    int n, k;
 
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        for (n = suffix; ; n = tree[n].suffix) {
            k = tree[n].length;
            int b = i - k - 1;
            if (b >= 0 && s[b] == c) {
                break;
            }
        }
 
        auto it = tree[n].edges.find(c);
        auto end = tree[n].edges.end();
        if (it != end) {
            suffix = it->second;
            continue;
        }
        suffix = tree.size();
        tree.push_back(Node(k + 2));
        tree[n].edges[c] = suffix;
        if (tree[suffix].length == 1) {
            tree[suffix].suffix = 0;
            continue;
        }
        while (true) {
            n = tree[n].suffix;
            int b = i - tree[n].length - 1;
            if (b >= 0 && s[b] == c) {
                break;
            }
        }
        tree[suffix].suffix = tree[n].edges[c];
    }
 
    return tree;
}
 
vector<string> subPalindromes(const vector<Node>& tree) {
    std::vector<string> s;
 
    std::function<void(int, string)> children;
    children = [&children, &tree, &s](int n, string p) {
        auto it = tree[n].edges.cbegin();
        auto end = tree[n].edges.cend();
        for (; it != end; it = next(it)) {
            auto c = it->first;
            auto m = it->second;
 
            std::string pl = c + p + c;
            s.push_back(pl);
            children(m, pl);
        }
    };
    children(0, "");
 
    auto it = tree[1].edges.cbegin();
    auto end = tree[1].edges.cend();
    for (; it != end; it = next(it)) {
        auto c = it->first;
        auto n = it->second;
 
        string ct(1, c);
        s.push_back(ct);
 
        children(n, ct);
    }
 
    return s;
}
 


void solve()
{
	string s;
	cin>>s;
	
	auto tr = eertree(s);
	cout<<tr.size()-2<<endl;
	//auto pal = subPalindromes(tr);
	
	//cout<<pal.size()<<endl;
	


}

int main()
{
   // fast_cin;

    // calc_fact_invfact();
    //si();

    // ll n;
    // int n;
    // while(cin>>n)

    case
    {
        // if(n==0) break;
         cout<<"Case #"<<cas++<<": ";

        solve();
    }

    return 0;
}

void si()
{
    mem(mark, 0);
    for (int i = 4; i < maxn; i += 2)
        mark[i] = 1;
    for (int i = 3; i * i < maxn; i += 2)
    {
        if (!mark[i])
            for (int j = i * i; j < maxn; j += 2 * i)
                mark[j] = 1;
    }

    pr.pb(2);
    for (int i = 3; i < maxn; i += 2)
        if (!mark[i])
            pr.pb(i);
}


void calc_fact_invfact()
{
    inv[1] = 1;
    for (int i = 2; i < maxn; ++i)
        inv[i] = (mod - ((mod / i) * inv[mod % i]) % mod) % mod;

    fib[0] = 1;
    finv[0] = 1;
    for (ll i = 1; i < maxn; i++)
    {
        fib[i] = (fib[i - 1] * i) % mod;
        finv[i] = (finv[i - 1] * inv[i]) % mod;
    }
}

ll nCr(ll n, ll r)
{
    if (n < 0LL || r < 0LL || r > n)
        return 0LL;
    if (r == 0ll)
        return 1ll;
    return (fib[n] * finv[r] % mod * finv[n - r] % mod) % mod;
}