//#pragma GCC optimize("03,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb           push_back
#define ff           first
#define ss           second
#define gcd(a, b)    __gcd(a, b)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       v.begin(),v.end()
#define rall(v)      v.rbegin(),v.rend()
#define lllim        2147483648
#define Pi           2*acos(0.0)
#define pii          pair<int,int>
#define pll 	     pair<ll,ll>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define mod          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define D(x)         cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define case		 int t,cas=1;cin>>t;while(t--)
#define rep(i,a,n)   for(int i=a;i<n;i++)
#define rev(i,n,a)   for(int i=n;i>=a;i--)
#define sim 		 template<class T

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/



sim > void ckmin(T& a, const T& b) {
    a= b < a? b:a;
}
sim > void ckmax(T& a, const T& b) {
    a= b > a? b:a;
}

///.............................input.................................///
sim > void read(T& a) {
    std::cin>>a;
}
sim > void read(T& a, T& b) {
    std::cin>>a>>b;
}
sim > void read(T& a,T& b, T& c) {
    std::cin>>a>>b>>c;
}
sim > void readvec( std::vector<T>& v, const int n) {
    rep(i,0,n) {
        T p;
        std::cin>>p;
        v.pb(p);
    }
}
///...........................input end...............................///


using namespace std;
using namespace __gnu_pbds;

const int maxn=1e5+6;

///............................Number theory , si(), bigmod...................///
vector<int>pr;
ll bigmod(ll a, ll b, ll m);
void si();
///.................................Number theory end.........................///

const int INF = 1e8;
const int MAXN = 105, MAXE = 10005;
/// Maximum no of nodes and edges.
int fin[MAXN], pro[MAXN], dist[MAXN];
int cap[MAXE], cost[MAXE], nxt[MAXE], to[MAXE], from[MAXE];
struct MCMF
{
    int src, snk, nNode, nEdge;
    /// Parameters: (source, sink, no of nodes)
    void clear(int _src, int _snk, int nodes)
    {
        nNode = nodes, nEdge = 0;
        src = _src, snk = _snk;
        memset(fin, -1, sizeof fin);
    }
    /// Parameters: (from, to, capacity, cost per flow)
    void addEdge(int u, int v, int _cap, int _cost)
    {
        from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap;
        cost[nEdge] = _cost, nxt[nEdge] = fin[u], fin[u] = nEdge++;
        ///2nd capacity zero for directed edge
        from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0;
        cost[nEdge] = -_cost, nxt[nEdge] = fin[v], fin[v] = nEdge++;
    }
    bool bellmanford()
    {
        bool flag = true;
        for(int i = 0; i<nNode; i++)
        {
            dist[i] = INF;
            pro[i] = -1;
        }
        dist[src] = 0;
        for (int it = 1; it < nNode && flag; it++)
        {
            flag = false;
            for (int u = 0; u < nNode; u++)
            {
                for (int i = fin[u]; i >= 0; i = nxt[i])
                {
                    int v = to[i];
                    if (cap[i] && dist[v] > dist[u] + cost[i])
                    {
                        dist[v] = dist[u] + cost[i];
                        pro[v] = i;
                        flag = true;
                    }
                }
             
            }
        }
        return (dist[snk] < INF);
    }
    /// Returns pair {flow, cost}
    pii findMCMF()
    {
        int fflow = 0, fcost = 0;
        while (bellmanford())
        {
            int fw = INF;
            for (int u = pro[snk]; u >= 0; u = pro[from[u]])
            {
                fw = min(fw, cap[u]);
            }
            for (int u = pro[snk]; u >= 0; u = pro[from[u]])
            {
                cap[u] -= fw;
                cap[u^1] += fw;
                fcost += fw * cost[u];
            }
            fflow += fw;
        }
        return make_pair(fflow, fcost);
    }
} mcmf;


void solve(int t)
{
	int n;
	cin>>n;
	int total_node = 2*n + 2;
	
	mcmf.clear(0,total_node-1,total_node);
	
	for(int i=1;i<=n;i++)
	{
		mcmf.addEdge(0,i,1,0);
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int c;
			cin>>c;
			mcmf.addEdge(i,n+j,1,-c);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		mcmf.addEdge(n+i,total_node-1,1,0);
	}
	
	pii res = mcmf.findMCMF();
	
	cout<<"Case "<<t<<": "<<-res.ss<<endl;



}


int main()
{
    fast_cin;
    // si();

    //while(scanf("%d",&n)!=EOF)
case
    {
        //cout<<""<<cas++<<""<<endl;
        solve(cas++);
    }

    return 0;
}







///............................Number theory , si(), bigmod...................///

bool mark[maxn];

void si()
{
    mem(mark,0);
    for(int i=4; i<maxn; i+=2) mark[i]=1;
    for(int i=3; i*i<maxn; i+=2)
    {
        if(!mark[i])
            for(int j=i*i; j<maxn; j+=2*i)
                mark[j]=1;
    }

    pr.pb(2);
    for(int i=3; i<maxn; i+=2)
        if(!mark[i])
            pr.pb(i);
}


ll bigmod(ll a, ll b, ll m)
{
    if(b==0) return 1;
    if(b==1) return a;

    if(b%2)
    {
        ll res=bigmod(a,b/2,m)%m;
        return ((((res%m)*(res%m))%m)*(a))%m;
    }
    else
    {
        ll res=bigmod(a,b/2,m)%m;
        return (((res%m)*(res%m))%m);
    }
}

///.................................Number theory end.........................///

