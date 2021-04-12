#include<bits/stdc++.h>
typedef long long ll;
#define pb           push_back
#define ff           first
#define ss           second
#define gcd(a, b)    __gcd(a, b)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       (v.begin(),v.end())
#define lllim       2147483648
#define Pi           2*acos(0.0)
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define watch(x)   	 cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'

using namespace std;
const ll maxn=100005;

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

ll tree[maxn*3];
ll lazy[maxn*3];

//void init(int node, int b, int e)
//{
//    if(b==e)
//    {
//        tree[node]=0;
//        return;
//    }
//    int mid=(b+e)>>1;
//    int left=node<<1;
//    int right=left+1;
//    init(left, b, mid);
//    init(right, mid+1, e);
//    tree[node]=tree[left]+tree[right];
//}

void update(ll node, ll b, ll e, ll i, ll j, ll value)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(e-b+1)*lazy[node];
        if(b!=e)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(e<i || b>j)
        return;
    if(b>=i && e<=j)
    {
        tree[node]+=(e-b+1)*value;
        if(b!=e)
        {
            lazy[node*2]+=value;
            lazy[node*2+1]+=value;
        }
        return;
    }
    ll mid=(b+e)/2;
    ll left=node*2;
    ll right=left+1;
    update(left, b, mid, i, j, value);
    update(right, mid+1, e, i, j, value);
    tree[node]=tree[left]+tree[right];
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
   // cout<<"     query      "<<endl;
    if(lazy[node])
    {
        tree[node]+=(e-b+1)*lazy[node];
        if(b!=e)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(e<i or b>j)
        return 0;
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    ll mid=(b+e)/2;
    ll left=node*2;
    ll right=left+1;
    ll x=query(left, b, mid, i,j);
    ll y=query(right, mid+1, e, i, j);

  //  cout<<x<<" g "<<y<<endl;
  ll p=x+y;
    return p;
}

int main()
{
   // filein;
    ll t,cas=1;
    scanf("%lld", &t);
    while(t--)
    {
        mem(lazy,0);
        mem(tree,0);
        printf("Case %lld:\n",cas++);
        ll n, q;
        scanf("%lld%lld", &n, &q);
        //init(1,1,n);
        while(q--)
        {
            ll p,x,y;
            scanf("%lld%lld%lld", &p,&x,&y);
            x++;
            y++;
            if(p==1)
            {
                printf("%lld\n",query(1,1,n,x,y));
            }
            else
            {
                ll v;
                scanf("%lld", &v);
                update(1,1,n,x,y,v);
            }

        }


    }
    return 0;
}

