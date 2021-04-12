#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define ff first
#define ss second
using namespace std;

const ll maxn=100005;

ll n;
vector<pair<ll,ll> >adj[maxn];
ll level[maxn];
ll sparse[maxn][22];
ll maxsparse[maxn][22];
ll minsparse[maxn][22];

void dfs(ll u, ll p, ll cost, ll d)
{
    level[u]=d;
    ///initialize the first , 2^0 parent
    sparse[u][0]=p;
    maxsparse[u][0]=cost;
    minsparse[u][0]=cost;
    for(ll i=0; i<adj[u].size(); i++)
    {

        ll v=adj[u][i].ff;
        if(v==p)
            continue;
        //  cout<<v<<" "<<u<<endl;
        dfs(v, u,adj[u][i].ss, d+1);
    }
    return;
}

ll ansmax=0,ansmin=1000000009;

void lca_query(ll p, ll q)
{
    if(level[p]<level[q])
        swap(p,q);

    ll log=1;

    ///initialize the height of node p
    while((1<<log)<=level[p])
        log++;
    log--;



    for(ll i=log; i>=0; i--)
    {
        if((level[p]-(1<<i))>=level[q])
        {
            ansmax=max(maxsparse[p][i], ansmax);
            ansmin=min(minsparse[p][i], ansmin);

            ///move p node to upper parent , which is lower/equal level of q node
            p=sparse[p][i];
        }
    }

    if(p==q)
        return ;
    for(ll i=log; i>=0; i--)
    {
        if(sparse[p][i]!=-1 && sparse[p][i]!=sparse[q][i])
        {
            ///move two node together to the LCA;
            ansmax=max(maxsparse[p][i], ansmax);
            ansmax=max(maxsparse[q][i], ansmax);

            ansmin=min(minsparse[p][i], ansmin);
            ansmin=min(minsparse[q][i], ansmin);

            p=sparse[p][i];
            q=sparse[q][i];
        }
    }

    /// final parent of p,q both,..
    ansmax= max(ansmax, max(maxsparse[p][0], maxsparse[q][0]));
    ansmin= min(ansmin, min(minsparse[p][0], minsparse[q][0]));


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
                minsparse[i][j]=min(minsparse[i][j-1],minsparse[sparse[i][j-1]][j-1]);
                maxsparse[i][j]=max(maxsparse[i][j-1],maxsparse[sparse[i][j-1]][j-1]);
            }
        }
    }
    return;

}

int main()
{
    //freopen("input.txt", "r", stdin);



        for(ll i = 0; i < maxn; i++)
        {
            for(ll j = 0; j < 22; j++)
            {
                maxsparse[i][j] = -1;
                sparse[i][j] = -1;
                minsparse[i][j]=1000000009;
            }
        }

        ll m;
        scanf("%d", &n);


        for(ll i=0; i<n-1; i++)
        {
            ll p,q,c;
            scanf("%d%d%d", &p,&q, &c);
            adj[p].pb({q,c});
            adj[q].pb({p,c});

        }

        //cout<<"hi"<<endl;
        dfs(1,-1,0,0);
        // cout<<" gjjg "<<endl;

        lca_init();

        // cout<<" kjp pu "<<endl;
        ll q;
        scanf("%d", &q);

        while(q--)
        {
            ansmax=0,ansmin=1000000009;

            ll u, v;
            scanf("%d%d", &u, &v);
           lca_query(u,v);

            printf("%d %d\n", ansmin, ansmax);
        }


    return 0;
}

