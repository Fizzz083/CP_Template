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
const int maxn=1000005;

vector<int>v[maxn];
int mark[maxn];
void si()
{

    mark[1]=1;
    for(int i=2; i<maxn; i+=2) mark[i]=2;
    for(int i=3; i*i<maxn; i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i; j<maxn; j+=2*i)
                mark[j]=i;
        }
    }

    //pr.pb(2);
    for(int i=3; i<maxn; i+=2)
    {
        if(!mark[i]) mark[i]=i;
    }

}

int pos[maxn];


int main()
{
    // fast_cin;
//   while(true)

    si();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(pos,-1);
        int n;
        scanf("%d",&n);
        int ara[n+2];
        for(int i=1; i<=n; i++) scanf("%d",&ara[i]);

        vector<int>v[n+2];
        for(int i=1; i<=n; i++)
        {
            while(ara[i]>1)
            {
                int pr=mark[ara[i]];
                v[i].pb(pr);
                ara[i]/=pr;
            }

        }

        for(int i=0; i<v[1].size(); i++)
        {
            pos[v[1][i]]=1;
        }

        int l=1,r=2,ans=-1;

        while(l<=r && r<=n)
        {
            bool f=1;
            for(int i=0; i<v[r].size(); i++)
            {
                if(pos[v[r][i]]==-1 or pos[v[r][i]]==r)
                {
                    pos[v[r][i]]=r;
                }
                else
                {
                    f=0;
                    break;
                }

            }
            if(!f)
            {
                for(int i=0; i<v[l].size(); i++)
                {
                    pos[v[l][i]]=-1;
                }
                l++;
            }
            else
            {
                ans=max(ans,r-l+1);
                r++;
            }
        }
        if(ans==1)ans=-1;


        printf("%d\n",ans);

    }

    return 0;
}
