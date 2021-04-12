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
#define rall(v)      v.rbegin(),v.rend()
#define lllim        2147483648
#define Pi           2*acos(0.0)
#define pii          pair<int,int>
#define pll 	     pair<ll,ll>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define D(x)         cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define case		 int t,cas=1;cin>>t;while(t--)
#define rep(i,a,n)   for(int i=a;i<n;i++)
#define rev(i,n,a)   for(int i=n;i>=a;i--)
#define sim 		 template<class T

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/



sim > void ckmin(T& a, const T& b) {
    a= b < a? b:a;
}
sim > void ckmax(T& a, const T& b) {
    a= b > a? b:a;
}

///.............................input.................................///
sim > void read(T& a) {
    std::cin>>a;
}
sim > void read(T& a, T& b) {
    std::cin>>a>>b;
}
sim > void read(T& a,T& b, T& c) {
    std::cin>>a>>b>>c;
}
sim > void readara(T& ara,const int sidx, const int eidx) {
    for(int i=sidx; i<eidx; i++) std::cin>>ara[i];
}
sim > void readvec( std::vector<T>& v, const int n) {
    rep(i,0,n) {
        T p;
        std::cin>>p;
        v.pb(p);
    }
}
///...........................input end...............................///


using namespace std;
using namespace __gnu_pbds;

const int maxn=1 << 16;
const int maxl= 16;


int n, step, mv, suffix[maxn],tmp[maxn];
int sum[maxn],cnt[maxn];
int Rank[maxl][maxn];
string str;

inline bool equal(const int &u, const int &v)
{
	if(!step) return str[u]==str[v];
	if(Rank[step-1][u] != Rank[step-1][v]) return false;
	int a = u+mv<n? Rank[step-1][u+mv]:-1;
	int b = v+mv<n? Rank[step-1][v+mv]:-1;
	
	return a==b;
}

void update()
{
	int i, rnk;
	for(i=0;i<n;i++)
	{
		sum[i]=0;
	}
	for(i=rnk=0;i<n;i++)
	{
		suffix[i]=tmp[i];
		if(i && !equal(suffix[i], suffix[i-1]))
		{
			Rank[step][suffix[i]]=++rnk;
			sum[rnk+1]=sum[rnk];
		}
		else
		{
			Rank[step][suffix[i]]=rnk;
		}
		sum[rnk+1]++;
	}
	
}

void Sort()
{
	int i;
	for(i=0;i<n;i++) cnt[i]=0;
	
	mem(tmp,-1);
	
	for(i=0;i<mv;i++)
	{
		int idx=Rank[step-1][n-i-1];
		int x= sum[idx];
		tmp[x+cnt[idx]]=n-i-1;
		cnt[idx]++;
	}
	
	for(i=0;i<n;i++)
	{
		int idx=suffix[i]-mv;
		if(idx<0) continue;
		
		idx = Rank[step-1][idx];
		int x= sum[idx];
		tmp[x+cnt[idx]]=suffix[i]-mv;
		cnt[idx]++;
	}
	update();
	return;
}


inline bool cmp(const int &a, const int &b)
{
	if(str[a]!=str[b]) return str[a]<str[b];
	return false;
}

void SortSuffix()
{
	int i;
	for(i=0;i<n;i++)
	{
		tmp[i]=i;
	}
	sort(tmp,tmp+n,cmp);
	step=0;
	update();
	step++;
	for(mv=1;mv<n;mv<<=1)
	{
		Sort();
		step++;
	}
	step--;
	
	for(i=0;i<=step;i++) Rank[i][n]=-1;
	
}

inline int lcp(int u, int v)
{
	if(u==v) return n-u;
	int ret, i;
	for(ret=0,i=step;i>=0;i--)
	{
		if(Rank[i][u]==Rank[i][v])
		{
			ret+=1<<i;
			u+=1<<i;
			v+=1<<i;
		}
	}
	
	return ret;
}

void solve()
{
	
	read(str);
	n=str.size();
	
	SortSuffix();
	
	for(int i=0;i<n;i++)
	{
		cout<<suffix[i]<<' ';
	}
	

}


int main()
{
    fast_cin;
 
    {
		  solve();
    }

    return 0;
}


