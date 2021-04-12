#include<bits/stdc++.h>
typedef long long ll;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define watch(x)   	 cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'

//bool check(int n, int pos) return (bool)(n&(1<<pos));
#define Set(n,pos) n|=(1<<pos)

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
const int maxn=50001;

ll ara[maxn];

struct nodeo
{
    ll left,right,maxx,sum;
} tree[maxn*3];

void init(ll node, ll b, ll e)
{
    if(b>e) return;
    if(b==e)
    {
        tree[node].sum=ara[b];
        tree[node].left=ara[b];
        tree[node].right=ara[b];
        tree[node].maxx=ara[b];
        return;
    }
    ll left=2*node;
    ll right=left+1;

    ll mid=(b+e)/2;

    init(left,b,mid);

    init(right,mid+1,e);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].left=max(tree[left].left,tree[left].sum+tree[right].left);
    tree[node].right=max(tree[right].right,tree[right].sum+tree[left].right);
    tree[node].maxx=max(max(tree[left].maxx,tree[right].maxx),tree[left].right+tree[right].left);
}

nodeo query(ll node, ll b,ll e, ll l, ll r)
{
    if(l<=b && r>=e)
        return tree[node];

    ll left=2*node;
    ll right=left+1;

    ll mid=(b+e)/2;

    if(r<=mid) return query(left,b,mid,l,r);
    if(l>mid) return query(right,mid+1,e,l,r);

    nodeo ll=query(left,b,mid,l,r);
    nodeo rr=query(right,mid+1,e,l,r);

    nodeo ans;
    ans.sum=ll.sum+rr.sum;
    ans.left=max(ll.left,ll.sum+rr.left);
    ans.right=max(rr.right,rr.sum+ll.right);
    ans.maxx=max(max(ll.maxx,rr.maxx),ll.right+rr.left);

    return ans;

}



int main()
{
    // fast_cin;
    ll n;
    scl(n);
    for(ll i=1;i<=n;i++) scl(ara[i]);
    init(1,1,n);
    ll q;
    scl(q);
    while(q--)
    {
        ll l, r;
        scll(l,r);

        nodeo ans=query(1,1,n,l,r);

        printf("%lld\n",ans.maxx);
    }


    return 0;
}
