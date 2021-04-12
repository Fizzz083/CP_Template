#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

const int maxn=1005;

int n;
vector<int> adj[maxn];
int level[maxn];
int sparse[maxn][11];

void dfs(int u, int p, int d)
{
    level[u]=d;
    ///initialize the first , 2^0 parent
    sparse[u][0]=p;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(v==p)
            continue;
        dfs(v, u, d+1);
    }
    return;
}

int lca_query(int p, int q)
{
    if(level[p]<level[q])
        swap(p,q);

    int log=1;

    ///initialize the height of node p
    while((1<<log)<=level[p])
        log++;
    log--;

    for(int i=log; i>=0; i--)
    {
        if((level[p]-(1<<i))>=level[q])
        {
            ///move p node to upper parent , which is lower/equal level of q node
            p=sparse[p][i];
        }
    }

    if(p==q)
        return p;
    for(int i=log; i>=0; i--)
    {
        if(sparse[p][i]!=-1 && sparse[p][i]!=sparse[q][i])
        {
            ///move two node together to the LCA;
            p=sparse[p][i];
            q=sparse[q][i];
        }
    }

    /// final parent of p,q both,..
    return sparse[p][0];

}

void lca_init()
{
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sparse[i][j-1]!=-1)
            {
                sparse[i][j]=sparse[sparse[i][j-1]][j-1];
            }
        }
    }
    return;

}

int main()
{
    int t,cas=1;
    scanf("%d", &t);
    while(t--)
    {
        memset(sparse, -1, sizeof sparse);
        scanf("%d", &n);

        for(int i=1;i<=n;i++)
            adj[i].clear();

        printf("Case %d:\n", cas++);


        for(int i=1; i<=n; i++)
        {
            int m;
            scanf("%d", &m);
            for(int j=0; j<m; j++)
            {
                int p;
                scanf("%d", &p);
                adj[i].pb(p);
                //adj[p].pb(i);
            }
        }
        dfs(1,-1,0);
        lca_init();
        int q;
        scanf("%d", &q);

        while(q--)
        {

            int u, v;
            scanf("%d%d", &u, &v);
            int ans=lca_query(u,v);

            printf("%d\n", ans);
        }
    }

    return 0;
}
