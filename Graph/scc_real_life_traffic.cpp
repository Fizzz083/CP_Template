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
#define lllim        2147483648
#define Pi           2*acos(0.0)
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define watch(x)   	 cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;
using namespace __gnu_pbds;
const int maxn=10005;
bool vis[maxn];
int low[maxn],d[maxn];
int scc[maxn];
int nbridges[maxn];
vector<int>adj[maxn];
set<int>adj2[maxn];
vector<pair<int,int> > bridges;
int timee;
void scc_find(int u, int p)
{
    vis[u]=1;
    d[u]=low[u]=timee++;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
       // cout<<u<<" "<<v<<" "<<low[u]<<" "<<low[v]<<endl;
        if(v!=p)
        {

            if(vis[v]==0)
            {

                scc_find(v,u);
                if(d[u]<low[v])
                {
                  //  cout<<" dde "<<u<<" "<<v<<endl;
                    bridges.pb({min(u,v),max(u,v)});
                    adj2[u].erase(v);
                    adj2[v].erase(u);
                }
                low[u]=min(low[u],low[v]);
            }
            else
                low[u]=min(low[u],d[v]);
        }


    }

}

int main()
{

    int t, cas=1;
    scanf("%d",&t);
    while(t--)
    {

        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++)
        {
            adj[i].clear();
            adj2[i].clear();
        }

        for(int i=0; i<m; i++)
        {
            int p, q;
            scanf("%d%d",&p,&q);
            adj[p].pb(q);
            adj[q].pb(p);
            adj2[p].insert(q);
            adj2[q].insert(p);
        }

        bridges.clear();
        timee=0;
        mem(vis,0);
        mem(nbridges,0);

        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
              //  cout<<"new "<<i<<endl;
                scc_find(i,-1);
            }
        }

        int scc_cnt=0;

        mem(vis,0);
        for(int i=0; i<n; i++)
        {
            if(vis[i])
                continue;

            queue<int>q;
            q.push(i);

           // cout<<i<<" ll "<<endl;

            while(!q.empty())
            {
                int now=q.front();
                q.pop();
                if(vis[now])
                    continue;
                vis[now]=1;
                scc[now]=scc_cnt;
                for(set<int>:: iterator it=adj2[now].begin(); it!=adj2[now].end(); it++)
                {
                  //  cout<<*it<<"   hhh  "<<endl;
                    q.push(*it);
                }
            }
            scc_cnt++;
        }

        for(int i=0; i<bridges.size(); i++)
        {
           // cout<<bridges[i].ff<<" "<<bridges[i].ss<<"     "<<scc[bridges[i].ff]<<" "<<scc[bridges[i].ss]<<endl;
            nbridges[scc[bridges[i].ff]]++;
            nbridges[scc[bridges[i].ss]]++;
        }

        int ans=0;

        for(int i=0; i<scc_cnt; i++)
        {
            if(nbridges[i]==1)
                ans++;
        }

        ans=(ans+1)/2;

        printf("Case %d: %d\n",cas++,ans);


    }


    return 0;
}
