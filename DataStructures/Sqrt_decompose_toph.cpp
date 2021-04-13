// codeforcs 1199D

// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
typedef long long ll;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
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
//#define D(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define case        \
    int t, cas = 1; \
    cin >> t;       \
    while (t--)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, n, a) for (int i = n; i >= a; i--)
#define sim template <class T
#define prec(x) fixed << setprecision(x)

/*------------------------------Graph Moves----------------------------*/
//const int fx[] = {+1, -1, +0, +0};
//const int fy[] = {+0, +0, +1, -1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
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
//using namespace __gnu_pbds;

#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ",\n"[++it == istream_iterator<string>()];
    err(it, args...);
}

const int maxn = 200005;

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

int a[maxn];

struct sqrtDecomposition
{
    static const int sz = 450;//sz = sqrt(N);
    int numberofblocks;
    
    struct node
	{
		int L, R;
		bool islazy = false;	
		int lazyval=0;
        int value[sz];
		//extra data needed for different problems
		
		void ini(int l, int r)
		{
			for(int i=l; i<=r; i++){
                value[i-l]=a[i];

				//...initialize as need 
			}
			L=l, R=r;
            islazy = 0;
            lazyval = 0;
		}
		void semiupdate(int l, int r, ll val){
			if(l>r) return;
			if(islazy){
				for(int i=L; i<=R; i++){
                    value[i-L] = max(value[i-L], lazyval);
					//...distribute lazy to everyone
				}
				islazy = 0;
				lazyval = 0;
			}
			for(int i=l; i<=r; i++){
                value[i-L]=val;
				//...do it manually
			}
		}
		void fullupdate(int val){
			if(islazy){
                lazyval = max(lazyval, val);
				//...only update lazyval
			}
			else{
				for(int i=L; i<=R; i++){
                    value[i-L] = max(value[i-L], lazyval);

					//...everyone are not equal, make them equal
				}
				islazy = 1;
                lazyval = val;
				//update lazyval
			}
		}
		void update(int l, int r, ll val){
			if(l<=L && r>=R) fullupdate(val);
			else semiupdate(max(l, L), min(r, R), val);
		}
		ll semiquery(int l, int r){
			if(l>r) return 0;
			if(islazy){
				for(int i=L; i<=R; i++){

                    value[i-L] = max(value[i-L], lazyval);
					//...distribute lazy to everyone
				}
				islazy = 0;
				lazyval = 0;
			}
			ll ret = 0;
			for(int i=l; i<=r; i++){
                ret+=value[i-L];
				//...take one by one
			}
			return ret;
		}
		ll fullquery(){
            return lazyval;
			//return stored value;
			
		}
		ll query(int l, int r){
			if(l<=L && r>=R) return fullquery();
			else return semiquery(max(l, L), min(r, R));
		}
	};
	
	vector<node> blocks;
	
	void init(int n){
		numberofblocks = n/sz +1;
		int curL = 1, curR = sz;
		blocks.resize(numberofblocks+5);
		for(int i=1; i<=numberofblocks; i++){
			curR = min(n, curR);
			blocks[i].ini(curL, curR);
			curL += sz;
			curR += sz;
		}
	}
	
	void update(int l, int r, ll val){
		int left = (l-1)/sz+1;
		int right = (r-1)/sz+1;
		for(int i=left; i<=right; i++){
			blocks[i].update(l, r, val);
		}
	}
	
	ll query(int l, int r){
		int left = (l-1)/sz+1;
		int right = (r-1)/sz+1;
		ll ret = 0;
		for(int i=left; i<=right; i++){
			ret += blocks[i].query(l, r);
		}
		return ret;
	}
	
};

void solve()
{
    int n;
    cin >> n;

    //sqrtDecomposition sq;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sqrtDecomposition sq;

    sq.init(n);

    //  for (int i = 1; i <= n; i++)
    //     {
    //         cout << sq.query(i, i) << " ";
    //     }

    //     cout << endl;

    int q;

    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll p, x;
            cin >> p >> x;
            sq.update(p, p, x);
        }
        else
        {
            ll x;
            cin >> x;
            sq.update(1, n, x);
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     cout << sq.query(i, i) << " ";
        // }

        // cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << sq.query(i, i) << " ";
    }
}

int main()
{
    fast_cin;

    // calc_fact_invfact();
    //si();

    // ll n;
    // int n;
    // while(cin>>n)

    // case
    {
        // if(n==0) break;
        //cout<<"Case "<<cas++<<": ";

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

// g++ -o A A.cpp
// g++ -o B B.cpp
// g++ -o C C.cpp
