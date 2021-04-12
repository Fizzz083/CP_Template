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
using namespace __gnu_pbds;
const int maxn=200005;

bool mark[maxn];

void si()
{
    mark[1]=1;
    for(ll i=4; i<maxn; i+=2) mark[i]=1;
    for(ll i=3; i*i<maxn; i+=2)
        if(!mark[i])
            for(ll j=i*i; j<maxn; j+=i)
                mark[j]=1;
}

ll mod=998244353 ;
ll fib[maxn];
ll finv[maxn];
ll inv[maxn];

void calc()
{
    inv[1] = 1;
    for (int i = 2; i <maxn; ++i)
        inv[i] = (mod - ((mod/i)*inv[mod%i])%mod)%mod;

    fib[0]=1;
    finv[0]=1;
    for(ll i=1; i<maxn; i++)
    {
        fib[i]=(fib[i-1]*i)%mod;
        finv[i]=(finv[i-1]*inv[i])%mod;
    }
}

ll com(ll n,ll r)
{
    // cout<<n<<" "<<r<<endl;
    if(n<0LL || r<0LL || r>n) return 0LL;
    return (fib[n]*finv[r]%mod*finv[n-r]%mod)%mod;
}

ll bigmod(ll a, ll b, ll m)
{
    if(b==0ll) return 1ll;
    if(b==1ll) return a;

    if(b%2)
    {
        ll res=bigmod(a,b/2,m)%m;
        return ((((res%m)*(res%m))%m)*(a))%m;
    }
    else
    {
        ll res=bigmod(a,b/2,m)%m;
        return (((res%m)*(res%m))%m);
    }
}


int main()
{
    // fast_cinn;'

    /// solved from the eqn of stirling number 2nd kind...
    /// where s(n,k) is the number of ways to partition a set of
    /// n objects into k nonempty subsets.

    /// https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind

    //si();
    calc();
    //int n;
    ll n, k,r;
    cin>>n>>k;
    r=n-k;

    if(r<=0) cout<<0<<endl;
    else
    {
        ll ans=0ll;

        for(ll i=0ll;i<=r;i++)
        {
            ll num=(com(r,i)%mod * (bigmod(r-i,n,mod)%mod)%mod);
         //   cout<<com(r,i)<< " "<<bigmod(r-i,n,mod)<<endl;

          //  cout<<num<<endl;
            if(i%2)
                ans+=(mod-num);
            else ans+=num;

            ans%=mod;
        }

        ans*=com(n,r);
        ans%=mod;

        if(k>0)
        ans*=2;
        ans%=mod;

        cout<<ans<<endl;

    }


    return 0;
}
