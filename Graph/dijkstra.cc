#include<bits/stdc++.h>
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define ff               first
#define ss               second
#define inf              1000000008

#define PRINT_CASE(z)    printf("Case %d: ",z)
#define print_line       printf("\n")
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define watch(x)         cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define MAX              100000007
#define MOD              1e9+7

const int MAXN=105;
using namespace std;
int dis[MAXN];
vector<int>adj[MAXN];
map<pair<int,int>,int>cost;

int n;
void dijkstra(int s)
{
    fill(dis, dis+MAXN, inf);
    // memset(mark,false,sizeof(mark));
    dis[s]=0;
    priority_queue<pair<int,int> >pq;
    pq.push(mp(-0,s));
    while(!pq.empty())
    {
        int u=pq.top().ss;
        int uc=-pq.top().ff;
        pq.pop();
        // cout<<uc<< " kh"<<endl;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            // cout<<v<<" hi "<<endl;
            if(dis[v]>dis[u]+cost[mp(u,v)])
            {
                // path[v]=u;
                dis[v]=dis[u]+cost[mp(u,v)];
                pq.push(mp(-dis[v],v));
            }

        }

    }


}


int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t, cas=1;

    scanf("%d", &t);
    while(t--)
    {
        //  scanf("%d%d",&n,&m);
        // memset(vis, 0, sizeof vis);
        cost.clear();

        int n, m, s, e;

        for(int i=0; i<MAXN; i++)
            adj[i].clear();

        scanf("%d%d", &n, &m);

        for(int i=0; i<m; i++)
        {
            int p,q,w;
            scanf("%d%d%d", &p, &q, &w);
            adj[p].pb(q);
            adj[q].pb(p);
            if(cost[ {p,q}]==0)
                cost[mp(p,q)]=w;
            else
                cost[mp(p,q)]=min(w,cost[mp(p,q)]) ;
            if(cost[ {q,p}]==0)
                cost[mp(q,p)]=w;
            else
                cost[mp(q,p)]=min(w,cost[mp(q,p)]) ;


        }
        dijkstra(1);
        printf("Case %d: ", cas++);

        if(dis[n]!=inf)
        {
            printf("%d\n", dis[n]);

        }
        else
            printf("Impossible\n");


    }


    return 0;
}
