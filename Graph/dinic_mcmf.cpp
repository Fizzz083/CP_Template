
//lightoj - internet bandwidth

// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
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
//#define D(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define case        \
    int t, cas = 1; \
    cin >> t;       \
    while (t--)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, n, a) for (int i = n; i >= a; i--)
#define sim template <class T
#define prec(x) fixed<<setprecision(x)


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

#define error(args...) \
{ \
    string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
    stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);\
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr<< *it << " = " << a <<",\n"[++it==istream_iterator<string>()];
    err(it, args...);
}


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



/*
max flow (dinitz algorithm)
works on undirected graph
can have loops, multiple edges, cycles
*/
 
struct Dinic
{
    struct Edge
    {
        int u,v;
        ll cap,flow=0;
        Edge(){}
        Edge(int u,int v,ll cap):u(u),v(v),cap(cap){}
    };
    int N;
    vector<Edge>edge;
    vector<vector<int>>adj;
    vector<int>d,pt;
    Dinic(int N):N(N),edge(0),adj(N),d(N),pt(N){}
    void addEdge(int u,int v,ll cap)
    {
        if(u==v) return;
        edge.eb(u,v,cap);
        adj[u].eb(edge.size()-1);
        edge.eb(v,u,0);
        adj[v].eb(edge.size()-1);
    }

    bool bfs(int s,int t)
    {
        queue<int>q({s});
        fill(d.begin(),d.end(),N+1);
        d[s]=0;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            if(u==t) break;
            for(int k:adj[u])
            {
                Edge &e = edge[k];
                if(e.flow<e.cap && d[e.v]>d[e.u]+1)
                {
                    d[e.v]=d[e.u]+1;
                    q.emplace(e.v);
                }
            }
        }
        return d[t]!=N+1;
    }
    ll dfs(int u,int T,ll flow = -1)
    {
        if(u==T|| flow==0) return flow;
        for(int &i = pt[u];i<adj[u].size();i++)
        {
            Edge &e = edge[adj[u][i]];
            Edge &oe = edge[adj[u][i]^1];
            if(d[e.v]==d[e.u]+1)
            {
                ll amt = e.cap-e.flow;
                if(flow!=-1 && amt>flow) amt = flow;
                if(ll pushed = dfs(e.v,T,amt))
                {
                    e.flow+=pushed;
                    oe.flow-=pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    ll maxFlow(int s,int t)
    {
        ll total=0;
        while(bfs(s,t))
        {
            fill(pt.begin(),pt.end(),0);
            while(ll flow = dfs(s,t))
            {
                total+=flow;
            }
        }
        return total;
    }

};

void solve()
{
    int s, t,n, m;
    cin>>n>>s>>t>>m;
    s--;
    t--;

    

    Dinic Di(n);
    for(int i=0;i<m;i++)
    {
        int u, v, c;
        cin>>u>>v>>c;
        u--;v--;
        Di.addEdge(u, v, c);
        Di.addEdge(v, u, c);
    }
  //  error(n, s, t, m);
    ll ans = Di.maxFlow(s, t);
    cout<<ans<<endl;
    

}

int main()
{
    fast_cin;



    // calc_fact_invfact();
    //si();

    // ll n;
    // int n;
    // while(cin>>n)

    case
    {
        // if(n==0) break;
        cout<<"Case "<<cas++<<": ";

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