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
#define mem(a,b)         memset(a, b, sizeof a)

#define filein       freopen("input.txt","r", stdin)

#define fileout       freopen("output.txt","w", stdout)

const int maxn=5100;
using namespace std;
vector<int>adj[maxn];
vector<int>b,w;
bool vis[maxn];
int dist[maxn];

int in_deg[maxn];
int n;
void bfs()
{
    memset(vis,0,sizeof vis);

    memset(dist,0,sizeof dist);
    queue<int>q;
    for(int i=1; i<=n; i++)
    {
       if(in_deg[i]==1)
        {
            q.push(i);
        }
    }

    int R=n;
    while(R>2)
    {
        int nn=q.size();
        for(int j=0;j<nn;j++)
        {
            int u=q.front();
            q.pop();
            R--;

            for(int i=0; i<adj[u].size(); i++)
            {
                int v=adj[u][i];
                in_deg[v]--;
                if(in_deg[v]==1) q.push(v);
            }
        }
    }


    while(q.size())
    {

        b.pb((int)q.front());
        q.pop();
    }

}


int bfs1()
{
    mem(dist,0);
    mem(vis,0);

    vis[1]=1;
    queue<int>q;

    q.push(1);
    int ans=-1,mx=-1;
    while(q.size())
    {
        int u=q.front();
        if(dist[u]>mx)
        {
            mx=dist[u];
            ans=u;
        }
        q.pop();

        for(auto v:adj[u])
        {
            if(!vis[v])
            {
                dist[v]=dist[u]+1;
                vis[v]=1;
                q.push(v);
            }
        }
    }

    return ans;
}

int bfs2(int src)
{
    mem(dist,0);
    mem(vis,0);

    vis[src]=1;
    queue<int>q;

    q.push(src);

    int mx=-1;

    while(q.size())
    {
        int u=q.front();
        q.pop();
        mx=max(mx,dist[u]);

        for(auto v:adj[u])
        {
            if(!vis[v])
            {
                dist[v]=dist[u]+1;
                vis[v]=1;
                q.push(v);
            }
        }
    }

    //w.clear();
    //w.pb(src);

    for(int i=1; i<=n; i++)
    {
        if(dist[i]==mx)
        {
            w.pb(i);
        }
    }

    if(w.size())
    {
        return w[0];
    }
    else return -1;

}

int main()
{
    //filein;
    //fileout;
    while(scanf("%d",&n)!=EOF)
    {
        memset(in_deg,0,sizeof in_deg);

        for(int i=0; i<=n; i++)
            adj[i].clear();

        b.clear();
        //w.clear();
        for(int i=1; i<=n; i++)
        {
            int m;
            scanf("%d",&m);
            while(m--)
            {
                int x;
                scanf("%d",&x);
                adj[i].pb(x);
               // adj[x].pb(i);
                //in_deg[x]++;
                in_deg[x]++;
            }
        }
        bfs();

        w.clear();

        sort(b.begin(),b.end());

        int p=bfs1();
        int q=bfs2(p);

        w.pb(p);

        if(q!=-1)
        {
            //w.pb(q);
            q=bfs2(q);
        }
        sort(w.begin(), w.end());
        w.erase(unique(w.begin(), w.end()),w.end());


        printf("Best Roots  : ");
        for(int i=0; i<b.size(); i++)
        {
            printf("%d",b[i]);
            if(i!=b.size()-1)printf(" ");
        }
        printf("\nWorst Roots : ");
        for(int i=0; i<w.size(); i++)
        {
            printf("%d",w[i]);
            if(i!=w.size()-1)printf(" ");
        }
        printf("\n");

    }
    return 0;
}
