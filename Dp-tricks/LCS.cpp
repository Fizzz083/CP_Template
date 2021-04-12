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

string s,t;
ll ls,lt;

ll dp[150][150];

ll lcs(ll i, ll j)
{
    if(i==ls || j==lt)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll ret=0;
    if(s[i]==t[j])
        ret=1+lcs(i+1,j+1);
    else
    {

            ret=max(lcs(i+1,j),lcs(i,j+1));
    }

    return dp[i][j]=ret;

}
ll dp1[105][105][105];
ll edit_dist(string s1, string s2, ll m, ll n, ll way)
{
    if(n==0 or m==0)
        return way==0;
    if(dp1[m][n][way]!=-1)
        return dp1[m][n][way];
    if(s1[m-1]==s2[n-1])
        return dp1[m][n][way]=edit_dist(s1,s2,m-1,n-1,way-1);
    else
        return dp1[m][n][way]=edit_dist(s1,s2,m,n-1,way)+edit_dist(s1,s2,m-1,n,way);

   // int s=edit_dist(s1,s2,m-1,n-1);

}

int main()
{
    fast_cin;

    ll tt,cas=1;
    cin>>tt;
    while(tt--)
    {


    mem(dp,-1);
    mem(dp1,-1);

    cin>>s>>t;

    ls=s.size();
    lt=t.size();
    ll ans1=lcs(0,0);
   ll ans2=edit_dist(s,t,ls,lt,ans1);

   ans1=ls+lt-ans1;

    cout<<"Case "<<cas++<<": "<<ans1<<" "<<ans2<<endl;;

    }
    return 0;
}

