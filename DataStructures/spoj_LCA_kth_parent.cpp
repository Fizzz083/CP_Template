#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define ff first
#define ss second
using namespace std;

const ll maxn= 10005;
ll n;
vector<pair<ll,ll> >adj[maxn];
ll level[maxn];
ll sparse[maxn][16];
ll dist[maxn];

void dfs(ll u, ll p, ll d)
{
    level[u]=d;
    ///initialize the first , 2^0 parent
    sparse[u][0]=p;
    for(ll i=0; i<adj[u].size(); i++)
    {
        ll v=adj[u][i].ff;
        if(v==p)
            continue;
        dist[v]=dist[u]+adj[u][i].ss;
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
    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            if(sparse[i][j-1]!=-1)
            {
                sparse[i][j]=sparse[sparse[i][j-1]][j-1];
              //  maxsparse[i][j]=max(maxsparse[i][j-1],maxsparse[sparse[i][j-1]][j-1]);
            }
        }
    }
    return;
}

int kth_par(int n, int k)
{

    for(int i=0; i<=15; i++)
    {
        if((1<<i)&k )
        {
            //  cout<<i<<" "<<sparse[n][i]<<" kklk"<<endl;
            n=sparse[n][i];
        }
    }
    return n;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t,cas=1;
    scanf("%d", &t);
    while(t--)
    {
        for(ll i = 0; i < maxn; i++)
        {
            adj[i].clear();
            for(ll j = 0; j < 14; j++)
            {
                sparse[i][j] = -1;
            }
        }

        ll m;
        scanf("%d", &n);
        m=n-1;

        for(ll i=0; i<m; i++)
        {
            ll p,q,c;
            scanf("%d%d%d", &p,&q, &c);
            adj[p].pb({q,c});
            adj[q].pb({p,c});
        }

        dfs(1,-1,0);

        lca_init();

        while(1)
        {
            string s;
            cin>>s;
            if(s=="DIST")
            {
                ll u, v;
                scanf("%d%d", &u, &v);
                ll ans=lca_query(u,v);

                ll s1=dist[u];
                ll s2=dist[v];
                ll s=dist[ans];

                ans=s1+s2-2*s;

                printf("%d\n", ans);
            }
            else if(s[0]=='K')
            {
                ll u, v, k;
                scanf("%d%d%d", &u, &v, &k);
                ll ans=lca_query(u,v);

                ll s1=level[u];
                ll s2=level[v];
                ll s=level[ans];

                ll t=s1-s;

                if(k-1<=t)
                {
                    /// v er *s2-(k-s-1)) th parent

                    ans=kth_par(u,k-1);
                }
                else
                {
                    t=t+s2-s+1;
                    t=t-k;

                    /// u er ((s1-k)th parent;
                    ans=kth_par(v,t);
                }
                printf("%d\n", ans);
            }
            else
                break;
        }
        printf("\n");
    }

    return 0;
}

/*
1
9
1 2 2
1 3 4
2 4 3
4 6 4
6 8 5
8 9 2
3 5 5
5 7 1
*/
