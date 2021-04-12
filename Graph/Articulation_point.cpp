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
const int maxn=20;
int dfsRoot, rootChildren;
int dfs_num[maxn],dfs_low[maxn],dfs_parent[maxn],articulation_vertex[maxn];
int cnt_point,ti=0;
vector <int> adj[maxn];

void init()
{
    dfsRoot=1;
    rootChildren=0;
    mem(dfs_num,0);
    mem(dfs_low,0);
    ti=0;
    for(int i=0;i<maxn;i++)
        dfs_parent[i]=i;
    mem(articulation_vertex,0);
   // cnt_point=0;

    for(int i=0;i<maxn;i++)
            adj[i].clear();
}


void findarticulation_point(int u)
{
    dfs_low[u] = dfs_num[u] = ++ti; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)adj[u].size(); j++)
    {
        int v = adj[u][j];
        if (dfs_num[v] == false)   // a tree edge
        {
            dfs_parent[v] = u;
            if (u == dfsRoot)
                rootChildren++; // special case if u is a root
            findarticulation_point(v);
            if (dfs_low[v] >= dfs_num[u] && u!=dfsRoot) // for articulation point
               {
                 //  cout<<u<<endl;
                   articulation_vertex[u] = true;
                  // cnt_point++;
                }// store this information first
//            if (dfs_low[v.first] > dfs_num[u]) // for bridge
//                printf(" Edge (%d, %d) is a bridge\n", u, v.first);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        }
        else if (v != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
    }



}




int main()
{
    //fast_cin;
    int t,cas=1;
    int n,c;

    scanf("%d",&t);
    while(t--)
    {
        int n, m;
        scanf("%d%d",&n,&m);

        init();


        for(int i=0; i<m; i++)
        {
            int p,q;
            scanf("%d%d",&p,&q);
            adj[p].pb(q);
            adj[q].pb(p);
        }

        findarticulation_point(1);

        if(rootChildren>1)
            articulation_vertex[1]=1;
        cnt_point=0;
        for(int i=1;i<=n;i++)
            if(articulation_vertex[i])
             cnt_point++;

        printf("Case %d: %d\n",cas++,cnt_point);


    }


    return 0;
}

