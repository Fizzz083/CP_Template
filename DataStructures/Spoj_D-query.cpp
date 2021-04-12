#include<bits/stdc++.h>
typedef int ll;
#define pb push_back
#define watch(x)         cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define seg_tree   ll left=node*2, right=node*2+1,mid=(b+e)/2
using namespace std;
#define MOD 1000000007
#define ff first
#define ss second

const ll maxn=300005;

ll tree[maxn*3];
ll id[1000006];
int ara[maxn];

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
         //cout<<b<<" "<<e<<" "<<" "<<tree1[node]<<endl;
        return tree[node];
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    ll p1=query(left, b, mid, i, j);
    ll p2=query(right, mid+1, e, i, j);


    return p1+p2;
}


void update_zero(ll node, ll b, ll e, ll i)
{
    if(i>e || i<b)
    {
        return ;
    }
    else if(b==i && e==i)
    {
        //ll p=tree[node];
        tree[node]=0;
        return;
        //return b;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    update_zero(left, b, mid,i);
    update_zero(right, mid+1, e,i);

    tree[node]=tree[left]+tree[right];
}
void update_one(ll node, ll b, ll e, ll i)
{
    if(i>e || i<b)
    {
        return ;
    }
    else if(b==i && e==i)
    {
        //ll p=tree[node];
        tree[node]=1;
        return;
        //return b;
    }

    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;

    update_one(left, b, mid,i);
    update_one(right, mid+1, e,i);

    tree[node]=tree[left]+tree[right];
}

pair< pair<int,int>, int>q[200000+5];
int main()
{

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%d", &ara[i]);

    memset(tree, 0, sizeof tree);
    memset(id, -1, sizeof id);

    int m;


    scanf("%d", &m);

    for(int i=0;i<m;i++)
    {
        int p, r;
        scanf("%d%d", &p, &r);
        q[i]={{r,p},i};
    }

    sort(q, q+m);

    int ans[m+5], cnt=1;

    for(int i=0;i<m;i++)
    {
        int f=q[i].ff.ss;
        int l=q[i].ff.ff;
        int ind=q[i].ss;

        for(int j=cnt;j<=l;j++)
        {
            int num=ara[j];
            if(id[num]==-1)
            {
                id[num]=j;
                update_one(1,1,n,j);

            }
            else
            {

                update_zero(1,1,n,id[num]);
                update_one(1,1,n,j);
                id[num]=j;
            }
        }
        cnt=l+1;

        int res=query(1,1,n,f,l);
        ans[ind]=res;
    }

    for(int i=0;i<m;i++)
    {
        printf("%d\n",ans[i]);
    }

    return 0;
}
