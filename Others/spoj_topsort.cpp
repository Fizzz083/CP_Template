#include<bits/stdc++.h>
typedef long long ll;
#define pb           push_back
#define ff           first
#define ss           second
#define gcd(a, b)    __gcd(a, b)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       (v.begin(),v.end())
#define lllim       2147483648
#define Pi           2*acos(0.0)
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define watch(x)   	 cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'

using namespace std;
const ll maxn=200010;

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

vector<int> adj[205];
vector<bool>vis;
bool flag;
int in[205];

int n,cnt;
vector<int> topsort()
{
    //cout<<" gg "<<endl;

//     mem(in, 0);
//
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=0; j<adj[i].size(); j++)
//        {
//            in[adj[i][j]]++;
//        }
//    }
    set<int >q;
    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            q.insert(i);

        }
    }

    cnt=0;

    vector<int >top;

    while(!q.empty())
    {
        int u=*(q.begin());q.erase(q.begin());
        top.pb(u);
       // cout<<u<<" in"<<endl;
      // priority_queue<int>pq;
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(--in[v]==0)
                q.insert(v);
        }
       // priority_queue<int> :: iterator it;
        cnt++;
    }

    return top;

}

int main()
{

    //  fast_cin;
    int t,cas=1, j;
//    cin>>t;
    while(cin>>n)
    {
    for(int i=0; i<204; i++)
        adj[i].clear();

    int w,m;

    w=n;
    int po=1;
    map<string, int> mpp;
    map<int, string> mp;
    while(w--)
    {
        string a;
        cin>>a;
        mp[po]=a;
        mpp[a]=po++;
    }

    w=m;
  //  ans.clear();
    mem(in, 0);
    int cnt=1;
    cin>>w;
    while(w--)
    {
        string a, b;
        cin>>a>>b;
        in[mpp[b]]++;
        adj[mpp[a]].pb(mpp[b]);
    }

    vector<int> ans=topsort();

   // cout<<ans.size()<<" fff "<<endl;

   cout<<"Case #"<<cas++<<": Dilbert should drink beverages in this order:";

        for(int i=0;i<ans.size();i++)
            cout<<" "<<mp[ans[i]];
       cout<<"."<<endl<<endl;


    }

    return 0;

}



