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

ll sumofdigit(ll n)
{
    if(n<10)
    {
        return (n*(n+1)/2);
    }

    ll d=log10(n);

    ll *a=new ll[d+1];

    a[0]=0;
    a[1]=45;

    for(ll i=2;i<=d;i++)
    {
        a[i]=a[i-1]*10+45*(ceil(powl(10,i-1)));
    }

    ll p=ceil(powl(10,d));

    ll msd=n/p;

    return msd*a[d]+(msd*(msd-1)/2)*p+msd*(1+n%p)+sumofdigit(n%p);
}


int main()
{
    fast_cin;
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;

        ll ans1=(sumofdigit(n-1))/10;
        ll ans2=(sumofdigit(m))/10;

        ll ans=ans2-ans1;

        cout<<ans<<endl;
    }

    return 0;
}

