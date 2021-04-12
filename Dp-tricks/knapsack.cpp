#include<bits/stdc++.h>
#define ll long long int
#define filein freopen("in.txt","r",stdin)

using namespace std;

ll dp[100][1005];
ll a[100];
ll cc[100];



ll n,k;
const ll mod=100000007;

ll fn(ll i, ll s)
{
    ll ans=0;

    if(i>=n)
    {
        if(s==k) return 1;
        else return 0;

    }
    if(s>k) return 0;

    if(dp[i][s]!=-1)
        return dp[i][s];

    for(int j=0;j<=cc[i] && (j*a[i]+s)<=k;j++)
    {
        ans+=(fn(i+1,s+j*a[i]));
        ans=ans%mod;
    }

    return dp[i][s]=ans%mod;

}
int main()
{
  // filein;
    int t;
    scanf("%d", &t);
    for(int c=1; c<=t; c++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%lld%lld", &n,&k);
        for(ll i=0; i<n; i++)
             scanf("%lld", &a[i]);
        for(ll i=0; i<n; i++)
             scanf("%lld", &cc[i]);

       ll ans=fn(0,0);

        printf("Case %d: %lld\n", c, ans);



    }

}
