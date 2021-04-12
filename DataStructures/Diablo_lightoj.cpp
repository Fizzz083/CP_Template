#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define watch(x)         cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define seg_tree   ll left=node*2, right=node*2+1,mid=(b+e)/2
using namespace std;
#define MOD 1000000007

const ll maxn=200005;
ll ara[maxn];

ll tree[maxn*5];


void init(ll node,ll b, ll e)
{

    if(b==e)
    {
        if(ara[b]!=0)
            tree[node]=1;
        else
            tree[node]=0;
        return ;
    }

    ll left=node*2, right=node*2+1,mid=(b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);

    tree[node]=tree[left]+tree[right];

}

ll query(ll node, ll b, ll e, ll i)
{

    if(b==e)
    {
        tree[node]=0;
        ll q=ara[b];
        ara[b]=0;
        return q;
    }

    ll left=node*2, right=node*2+1,mid=(b+e)/2;

    ll p;
    if(tree[left]<i)
        p=query(right,mid+1,e,i-tree[left]);
    else
        p=query(left,b,mid,i);

    tree[node]=tree[left]+tree[right];

    return p;




}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i>e || i<b)
    {
        return ;
    }
    else if(b==e && b==i)
    {
        //ll p=tree[node];
        ara[b]=val;
        tree[node]=1;
        return;
        //return b;
    }

    ll left=node*2, right=node*2+1,mid=(b+e)/2;
    update(left, b, mid,i,val);
    update(right, mid+1, e,i,val);

    tree[node]=tree[left]+tree[right];


}



int main()
{

    int t;
    scanf("%d", &t);
    for(int cas=1; cas<=t; cas++)
    {
        memset(tree,0,sizeof tree);
        ll n,m,k,i,h;
        scanf("%lld%lld", &n,&m);

        // ll a[n+5];
        ll p=0;
       // initf(1,1,100002);
       // ll b[n+5];
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&ara[i]);

        }
        for(i=n+1; i<=m+n; i++)
            ara[i]=0;
        init(1,1,n+m);
        printf("Case %d:\n", cas);
        ll siz=n;


        for(i=1; i<=m; i++)
        {

            char cc;
            scanf(" %c %lld", &cc, &k);

            if(cc=='c')
            {
                p=query(1,1,n+m,k);
                if(p==0)
                    printf("none\n");
                else
                    printf("%lld\n", p);

            }
            if(cc=='a')

            {
                update(1,1,n+m,siz+1,k);
                siz++;
            }


        }




    }

    return 0;



}
