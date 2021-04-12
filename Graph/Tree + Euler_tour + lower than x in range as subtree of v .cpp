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
#define sci(n)	     scanf("%d",&n)
#define scii(n,m)    scanf("%d%d",&n,&m)
#define scl(n)       scanf("%lld",&n)
#define scll(n,m)    scanf("%lld%lld",&n,&m)
#define pii          pair<int,int>
#define pll 	     pair<ll,ll>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define watch(x)     cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;
//using namespace __gnu_pbds;
const int maxn=200105;

ll ara[maxn];
vector<pair<ll,ll> >adj[maxn];
ll dist[maxn];
ll start[maxn],end_[maxn],base_ara[3*maxn];
ll timee;
ll level[maxn];
void dfs(ll u, ll p)
{
    start[u]=timee;
    base_ara[timee++]=u;


    for(auto x: adj[u])
    {
        if(x.ff==p) continue;

        dist[x.ff]=dist[u]+x.ss;
        level[x.ff]=level[u]+1LL;
        dfs(x.ff,u);
    }
    base_ara[timee]=u;
    end_[u]=timee++;

}


ll tree[maxn*6];

struct node
{
    ll f;
    ll l;
    ll r;
    ll id;

} que[maxn*3];

bool cmp(node a, node b)
{
    if(a.f>b.f)
        return 1;
    else if(a.f<b.f)
        return 0;
    else if(a.l>b.l)
    {
        return 1;
    }
    else
        return 0;

}


void update(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e || j<b)
        return ;
    if(b>=i && e<=j)
    {
        tree[node]=1LL;
        return ;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;

    update(left, b, mid, i, j);
    update(right, mid+1, e, i,j);
    tree[node]=tree[left]+tree[right];
    // tree1[node]=tree1[left]+tree1[right];
}


ll query(ll node, ll b, ll e, ll i, ll j)
{
    // cout<<" j "<<node<<endl;
    if(i>e || j<b)
        return 0LL;
    if(b>=i && e<=j)
    {
        //cout<<b<<" "<<e<<" "<<" "<<tree1[node]<<endl;
        return tree[node];
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;

    ll p1=query(left, b, mid, i, j);
    ll p2=query(right, mid+1, e, i, j);


    return p1+p2;

}

int main()
{
    // fast_cin;
    memset(tree,0,sizeof tree);
    ll t,cas=1;
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>ara[i];
    }
    for(ll i=2; i<=n; i++)
    {
        ll q,w;
        cin>>q>>w;
        adj[i].pb({q,w});
        adj[q].pb({i,w});
    }

    timee=1LL;
    level[1]=1LL;
    dfs(1LL,0LL);


    t=n;
    n=timee-1LL;

    for(ll i=1; i<=n; i++)
    {
        ll q;

        q=dist[base_ara[i]]-ara[base_ara[i]];

        que[i-1].f=q;
        que[i-1].l=-1ll;
        que[i-1].r=i;
        que[i-1].id=0ll;

        // vp.pb({q,{-1,i}});

    }

//    for(int i=1; i<=n; i++)
//    {
//        cout<<base_ara[i]<<" ";
//    }
//    cout<<endl;
//
//    for(int i=1; i<=n; i++)
//    {
//        cout<<que[i-1].f<<" ";
//    }
//    cout<<endl;
//    for(int i=1; i<=t; i++)
//        cout<<dist[i]<<" ";
//    cout<<endl;


    ll an[t+5]= {0LL};

    ll idx=n;

    for(ll i=0LL; i<t; i++)
    {
        ll p,q,rr;

        rr=dist[i+1];
        p=start[i+1]+1;
        q=end_[i+1]-1;

        if(p>=q) continue;

        que[idx].f=rr;
        que[idx].l=p;
        que[idx].r=q;
        que[idx++].id=i+1;

       // cout<<p<<" "<<q<<" "<<i+1<<" "<<dist[i+1]<<endl;

        //   cout<<67<<endl;
        // vp.pb({r,{p,q}});
        //vp2.pb({r,{p,q}});
    }

    //   cout<<643437<<endl;


    sort(que,que+idx,cmp);
    for(ll i=0; i<idx; i++)
    {
        //cout<<que[i].f<<" "<<que[i].l<<" "<<que[i].r<<" "<<que[i].id<<endl;
        // cout<<vp[i].first<<" "<<vp[i].second.first<<" "<<vp[i].second.second<<endl;
        if(que[i].l==-1)
        {
            update(1,1,n,que[i].r,que[i].r);

        }
        else if(que[i].l!=-1)
        {
            ll ans=query(1,1,n,que[i].l,que[i].r);
            ans=(que[i].r-que[i].l+1-ans);
            an[que[i].id]=ans/2;
            //cout<<ans<<endl;

           // cout<<que[i].l<<" "<<que[i].r<<" "<<que[i].f<<"   id "<<que[i].id<<" ans: "<<ans<<endl;
            //mpp[{vp[i].first,{vp[i].second.first, vp[i].second.second}}]=ans;
        }

    }

    // cout<<" lkjds h"<<endl;

    for(ll i=1; i<=t; i++)
    {
        //  cout<<" hi"<<endl;
        //printf("%d\n", mpp[{vp2[i].first,{vp2[i].second.first, vp2[i].second.second}}] );
        printf("%lld ", an[i]);

    }





    return 0;
}


/*

8
1 1 3 5 4 3 2 1
1 9
1 8
3 3
3 3
4 2
4 5
4 2

*/
