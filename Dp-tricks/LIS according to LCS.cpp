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
const int maxn=100005;


int b[maxn],N;
int lis[maxn];

vector<int>List;

void calculate_LIS(){
    List.clear();
    for(int i = 0;i<N;i++){
        vector<int>::iterator low = lower_bound(List.begin(),List.end(),b[i]);
        lis[i] = (low - List.begin());
        if(low == List.end()) List.pb(b[i]);
        else *low = b[i];
    }
}



int main()
{
  // fast_cin;
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
            //int n;
            scanf("%d",&N);
            string a="";
           // int ara[n+2];

            map<int,int> mpp;
            for(int i=0;i<N;i++)
            {
                int c;
                scanf("%d",&c);
                mpp[c]=i;
            }

            for(int i=0;i<N;i++)
            {
                int c;
                scanf("%d",&c);
                b[i]=mpp[c];
            }


            calculate_LIS();

            int res=0;

            for(int i=0;i<N;i++)
            {
              //  cout<<lis[i]<<" ";
                res=max(res,lis[i]);
            }
            //cout<<endl;

            printf("%d\n",res+1);



    }

}
