#include<bits/stdc++.h>
typedef long long ll;
#define pb           push_back
#define ff           first
#define ss           second
#define gcd(a, b)    __gcd(a, b)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       (v.begin(),v.end())
#define intlim       2147483648
#define Pi           2*acos(0.0)
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define watch(x)   	 cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'

using namespace std;
const int maxn=100005;

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/
ll ara[34];
ll k, n;
ll dp[34][2][2][35];
ll func(ll idx, ll issmall, ll prv, ll tot)
{
    if(dp[idx][issmall][prv][tot]!=-1)
        return dp[idx][issmall][prv][tot];

    // cout<<idx<<" "<<issmall<<" "<<ara[idx]<<" "<<mod<<" "<<sum<<endl;

    if(idx == 0)
    {
        return tot;
    }
    ll ret = 0;
    if(issmall == 0)
    {
            for(ll i = 0; i < ara[idx]; i++)
            {
                    ret += (func(idx - 1, 1, i,tot+min(prv,i)));
            }

            ret +=(func(idx - 1, 0, ara[idx],tot+min(prv,ara[idx])));

    }
    else
    {

             for(ll i = 0; i <= 1; i++)
            {

                    ret +=(func(idx - 1, 1, i,tot+min(prv,i)));
            }

    }
    return dp[idx][issmall][prv][tot]=ret;

}

ll solve(ll m)
{
    mem(dp, -1);
    ll l=0;
    ll r=0;
    // cout<<" cassss"<<endl;
    while(m)
    {
        ara[++l]=m%2;
        m/=2;

       // cout<<ara[l]<<" "<<endl;

    }
 //   cout<<l<<endl;
    return func(l,0,0,0);
}

int main()
{
    fast_cin;
    ll t, cas=1;
    cin>>t;
    while(t--)
    {

        ll a, b, ans;
        cin>>a;
        ans=solve(a);

        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }

}
