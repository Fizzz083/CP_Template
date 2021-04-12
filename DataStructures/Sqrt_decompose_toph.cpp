
/// 07.05.2020   ::  01:26:00  GMT+06

//#pragma GCC optimize("03,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
//using namespace __gnu_pbds;
const int maxn=100001;

ll ara[maxn];
int n,len;
pair<int,int> seg[318];

ll tree[maxn];


void update(int l, int r, int st)
{
    //cout<<l<<" "<<r<<" "<<len<<endl;
    for(int i=l; i<=r;)
    {
        // cout<<i<<" "<<" "<<st<<endl;

        if(i%len==0 && i+len-1<=r)
        {
            seg[i/len].ff++;
            seg[i/len].ss+=st;
            ll f=(ll)(st-1);
            st+=len;
            ll s=(ll)(st-1);

            tree[i/len]+=(s*(s+1))/2 - (f*(f+1))/2;
            i+=len;
        }
        else
        {
            /*
                        if(seg[i/len].ff!=0)
                        {
                            ll prv=0;
                            ll nn=seg[i/len].ss;
                            ll cnt=seg[i/len].ff;
                            for(int k=i; k<=i+len-1; k++)
                            {
                                ara[k]+=nn;
                                nn+=cnt;
                                //prv++;
                            }
                            seg[i/len].ff=0;
                            seg[i/len].ss=0;
                        }
                        */
            tree[i/len]+=st;
            ara[i]+=st;
            i++;
            st++;
        }
    }


}


ll query(int l, int r)
{
    ll ans=0ll;

    //cout<<l<<" "<<r<<endl;
    for(int i=l; i<=r;)
    {
        //cout<<i<<" dd "<<endl;



        if(i%len==0 && i+len-1<=r)
        {
            ans+=(tree[i/len]);
            i+=len;
        }
        else
        {
            if(seg[i/len].ff!=0)
            {

                ll nn=(ll)seg[i/len].ss;
                ll cnt=(ll)seg[i/len].ff;
                int ne=(i/len)*len;
                for(int k=ne; k<=ne+len-1; k++)
                {
                    ara[k]+=nn;
                    nn+=cnt;
                    //cout<<ara[k]<<" "<<" "<<i/len<<"   a:  ";
                    //prv++;
                }
                //cout<<endl;
                seg[i/len].ff=0;
                seg[i/len].ss=0;
            }
            ans+=ara[i];
            i++;
        }
    }

    //cout<<ans<<endl;

    return ans;


}




void solve()
{


    int q;
    scanf("%d%d", &n, &q);
    len=sqrt(n+0.1)+1;
    for(int i=0; i<=len; i++)
        seg[i].ff=0;

    //  cout<<"len "<<len<<endl;

    //for(int i=1;i<maxn;i++) sum[i]=(i+sum[i-1]);

    while(q--)
    {
        int t, l,r;
        scanf("%d%d%d",&t,&l,&r);

        if(t==1)
        {
            update(l,r,1);

            //cout<<" qqq  "<<n<<"  ";
            //for(int i=1;i<=n;i++) cout<<query(i,i)<<' ';
            //cout<<endl;
        }
        else
        {
            //cout<<" xca"<<endl;
            ll ans=query(l,r);


            printf("%lld\n",ans);
        }
    }


}


int main()
{
    // fast_cin;
    int t,cas=1;
    // cin>>t;
    //while(t--)
    //{
    //cout<<""<<cas++<<""<<endl;
    solve();
    //}

    return 0;
}

