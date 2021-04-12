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
const int maxn=10001;

vector<int>dfs_num,dfs_low,dfs_parent,vis;
int ti=0;
set<pair<int,int> > bridge;
vector <vector<int> > adj;

void init(int n)
{
//    dfsRoot=1;
    n=n+1;
//    rootChildren=0;
    dfs_low.resize(n);
    dfs_num.resize(n);
    vis.resize(n);
    vis.assign(n,0);
    adj.assign(n,vector<int>());
    ti=0;
    bridge.clear();
}


void findarticulation_bridge(int u,int p)
{
    vis[u]=1;
    dfs_low[u] = dfs_num[u] = ++ti; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)adj[u].size(); j++)
    {
        int v = adj[u][j];

        if(v==p)
            continue;

        if (vis[v] == false)   // a tree edge
        {
            findarticulation_bridge(v,u);

            if (dfs_low[v] > dfs_num[u]) // for bridge
            {
                int p=u,q=v;
                if(p>q)
                    {
                      swap(p,q) ;
                    }

                bridge.insert({p,q});

            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        }
        else // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
    }



}




int main()
{
    //fast_cin;
    int tt,cas=1;
    int n,c;

    scanf("%d",&tt);
    while(tt--)
    {
        int n, m;
        scanf("%d",&n);

        init(n);


        for(int i=1; i<=n; i++)
        {
            int nn;
            scanf("%d (%d)",&nn,&m);
            while(m--)
            {
                int p;
                scanf("%d",&p);
                adj[nn].pb(p);
                adj[p].pb(nn);
                //adj[q].pb(p);
            }
        }

        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                //dfsRoot=i;
                findarticulation_bridge(i,i);
            }
        }

       // sort(bridge.begin(),bridge.end());

        printf("Case %d:\n",cas++);

        printf("%d critical links\n",(int)bridge.size());

        for(set<pair<int,int> > :: iterator it=bridge.begin(); it!=bridge.end(); it++)
        {
            printf("%d - %d\n",(*it).ff,(*it).ss);
        }

    }


    return 0;
}

