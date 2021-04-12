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
#define watch(x)   	 cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;
using namespace __gnu_pbds;
const int maxn=100010;

int ara[maxn];
int cnt[maxn], n;
int ans;

void add(int i)
{
    if(ara[i]<=n)
    {
        int x=ara[i];
        cnt[x]++;
        if(cnt[x]==x) ans++;
        else if(cnt[x]==x+1) ans--;
    }
}

void remove_(int i)
{
    if(ara[i]<=n)
    {
        int x=ara[i];
        cnt[x]--;
        if(cnt[x]==x-1) ans--;
        else if(cnt[x]==x) ans++;
    }
}


int block_size;

struct query
{
    int l,r,idx;
bool operator<(query other) const
    {
        return make_pair(l/block_size,r)<make_pair(other.l/block_size,other.r);
    }
};



vector<int> mo(vector<query>vq)
{
    // cout<<'ww'<<endl;
    vector<int>answer((int)vq.size());
    sort(all(vq));

    int cur_l=0;
    int cur_r=-1;
    ans=0;

    for(query q:vq)
    {
        // cout<<q.l<<" "<<q.r<<" "<<q.idx<<endl;
        while(cur_l>q.l)
        {
            cur_l--;
            add(cur_l);
        }
        while(cur_r<q.r)
        {
            cur_r++;
            add(cur_r);
        }
        while(cur_l<q.l)
        {
            remove_(cur_l);
            cur_l++;
        }
        while(cur_r>q.r)
        {
            remove_(cur_r);
            cur_r--;
        }
        answer[q.idx]=ans;
        // cout<<ans<<' '<<q.idx<<endl<<endl;
    }

    return answer;

}

int main()
{
    // fast_cin;
    int t,cas=1;

    scanf("%d%d",&n,&t);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }


/*

1 1
1000000000
1 1

*/
    vector<query>v;
    for(int tt=0; tt<t; tt++)
    {
        int x, y;
        scanf("%d%d",&x, &y);
        x--;
        y--;

        query cq;
        cq.l=x;
        cq.r=y;
        cq.idx=tt;
        v.pb(cq);
    }
    block_size=320;

    vector<int>anss=mo(v);

    for(int i=0; i<(int)anss.size(); i++)
    {
        printf("%d\n",anss[i]);
    }

    return 0;
}
