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
// const int fx[] = {+1, -1, +0, +0};
// const int fy[] = {+0, +0, +1, -1};
// const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
// const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

inline ll _gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (!b)
        return a;
    return _gcd(b, a % b);
}
inline ll _pow(ll a, ll y)
{
    ll z = 1;
    rep(i, 1, y) { z *= a; }
    return z;
}
inline ll _lcm(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    return (a / _gcd(a, b)) * b;
}
inline ll bigmod(ll n, ll m, ll mod)
{
    ll ret = 1, a = n % mod;
    while (m)
    {
        if (m & 1)
            ret = (ret * a) % mod;
        m >>= 1;
        a = (a * a) % mod;
    }
    ret %= mod;
    return ret;
}
sim > void ckmin(T &a, const T &b) { a = b < a ? b : a; }
sim > void ckmax(T &a, const T &b) { a = b > a ? b : a; }

///.............................input.................................///
sim > void readvec(std::vector<T> &v, const int n)
{
    rep(i, 0, n)
    {
        T p;
        std::cin >> p;
        v.pb(p);
    }
}
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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

string k;
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }

    auto res = manacher_odd(t + "#");
    k = t+"#";

    return res;
}

void solve()
{
    string s;
    cin >> s;
    
    vector<int> vs = manacher(s);

    string ans  = "";
    int l = 1;
    //cout<<k<<endl;
    // for(int i=0;i<k.size();i++)
    // {
    //     cout<<k[i]<<' ';
    // }
    // cout<<endl;

    int pos =0;

    for(int i=0;i<vs.size();i++)
    {
        //cout<<vs[i]<<' ';
        if(vs[i]>l)
        {
            l = vs[i];
            pos = i;
            // if(k[i]=='#'){
            //     ans = k.substr(i-vs[i]+1, 2*vs[i]-1);
            // }
            // else
            // {
            //     ans = k.substr(i - vs[i]+1, 2*vs[i]-1);
            // }
            // //ans = k.substr(i - vs[i]+1, 2*vs[i]);
            
            
        }
    }

    ans = k.substr(pos - vs[pos]+1, 2*vs[pos]-1);
    // cout<<endl;
    // cout<<l<<endl;

    //cout<<ans<<endl;
    for(auto x: ans)
    {
        if(x!='#')cout<<x;
    }
    cout<<endl;


}

int main()
{
     fast_cin;

    // calc_fact_invfact();
    // si();

    // ll n;
    // int n;
    // while(cin>>n)

    // case
    {
        // if(n==0) break;
        // cout<<"Case #"<<cas++<<": ";

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