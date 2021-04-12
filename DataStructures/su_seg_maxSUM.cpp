

//#pragma GCC optimize("03,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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
const int maxn=100005;


int res(vector<int>a, int n, int m)
{

    int ans = a[0], ans_l = 0, ans_r = 0;
    int sum = 0, min_sum = 0, min_pos = -1;
    
    //cout<<"arra  :";
    int cum[n+2];
    cum[0]=0;
  
    for (int r = 0; r < n; ++r) {
		if(r==0) cum[r+1]=a[r];
		else cum[r+1]=a[r]+cum[r];
		
		//cout<<a[r]<<' ';
        sum += a[r];
        int cur = sum - min_sum;
        if (cur > ans) {
            ans = cur;
            ans_l = min_pos + 1;
            ans_r = r;
        }
        if (sum <= min_sum) {
            min_sum = sum;
            min_pos = r;
        }
    }

    
    int p1=(cum[ans_r+1] - cum[ans_l]);
    int p2=0;
    if(p1<=0)
    p1=0;
    
    int another_ans=m-p1;
    
    //cout<<"     "<<ans_l<<" "<<ans_r<<" "<<another_ans<<" "<<p1<<" "<<p2<<endl;
    

    return another_ans;
}


void solve()
{
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;

    

    int cnt_1=0;
    string v[k+2];


    for(int i=0; i<n; i++)
    {
        int idx=i%k;
        v[idx]+=s[i];
        cnt_1+=(s[i]=='1');
    }

    int ans=1e9;

    for(int i=0; i<k; i++)
    {
		int m=count(all(v[i]),'1');
        int rem=(cnt_1-m);

        int cnt=1;
        vector<int>vc;
        

        for(int j=1; j<v[i].size(); j++)
        {
            if(v[i][j]==v[i][j-1])
            {
                cnt++;
            }
            else
            {
                if(v[i][j]=='1')
                    vc.pb(-cnt);
                else vc.pb(cnt);
                cnt=1;
            }
        }
        if(v[i][v[i].size()-1]=='1')
            vc.pb(cnt);
        else vc.pb(-cnt);

        int result=res(vc,(int)vc.size(), m);

        ans=min(ans, result+rem);
    }

    cout<<ans<<endl;


}


int main()
{
    // fast_cin;
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        //cout<<""<<cas++<<""<<endl;
        solve();
    }

    return 0;
}

