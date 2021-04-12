#include<bits/stdc++.h>
typedef long long ll;
///#include <ext/pb_ds/assoc_container.hpp>
///#include <ext/pb_ds/tree_policy.hpp>
///#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define seg_tree     int left=node*2,right=node*2+1,mid=(b+e)/2;
/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;
///using namespace __gnu_pbds;
const int maxn=100005;


vector<int>tree[3*maxn];
vector<pair<int,int> > ara;
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].pb(ara[b].ss);
        return;
    }

    seg_tree;

    init(left,b,mid);
    init(right,mid+1,e);

    merge(all(tree[left]),all(tree[right]),back_inserter(tree[node]));
}

int query(int node, int b, int e, int l, int r, int k)
{
    if(b==e)
    {
        return tree[node][0];
    }

    seg_tree;

    int p=lower_bound(all(tree[left]),r+1)-upper_bound(all(tree[left]),l-1);

    if(p>=k)
        return query(left,b,mid,l,r,k);
    else
        return query(right,mid+1,e,l,r,k-p);
}

int main()
{
    int t,cas=1;
    //scanf("%d",&t);
    // while(t--)
    // {
    int n,q;
    scanf("%d%d",&n,&q);
    int b[n+3];ara.clear();
    ara.pb({-(1e9+2),0});
    for(int i=1; i<=n; i++)
    {
        int a;
        scanf("%d",&a);
        b[i]=a;
        ara.pb({a,i});
    }

    for(int i=0; i<maxn; i++) tree[i].clear();
   //

    sort(all(ara));


    init(1,1,n);

    for(int i=0; i<q; i++)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        int ans=query(1,1,n,l,r,k);
        //cout<<ans<<endl;

        printf("%d\n",b[ans]);

    }

    // }

    return 0;
}
