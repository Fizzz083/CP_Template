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

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;
const int maxn=1010;

int fin_seg[2*maxn][2*maxn];

int sizee;
//
//void segment(int low, int high, int pos, int strip)
//{
//    if(high==low)
//    {
//        ini_seg[strip][pos]=rect[strip][low];
//    }
//    else
//    {
//        int mid=(low+high)/2;
//        int left=2*pos;
//        int right=left+1;
//        segment(low, mid, left, strip);
//        segment(mid+1, high, right, strip);
//        ini_seg[strip][pos]=ini_seg[strip][left]+ini_seg[strip][right];
//    }
//}
//
//void finalSegment(int low, int high, int pos)
//{
//    if(high==low)
//    {
//        for(int i=1;i<2*sizee;i++)
//        {
//            fin_seg[pos][i]=ini_seg[low][i];
//        }
//    }
//    else
//    {
//        int mid=(low+high)/2;
//        int left=2*pos;
//        int right=left+1;
//
//        finalSegment(low, mid, left);
//        finalSegment(mid+1, right, high);
//
//        for(int i=1;i<2*sizee;i++)
//        {
//            fin_seg[pos][i]=fin_seg[left][i]+fin_seg[right][i];
//        }
//    }
//}

int finalQuery(int pos, int start, int endd, int x1, int x2, int node)
{
    if(x2<start || endd<x1)
        return 0;
    if(x1<=start && endd<=x2)
        return fin_seg[node][pos];
    int mid=(start+endd)/2;
    int left=pos*2;
    int right=left+1;

    int p1=finalQuery(left,start,mid,x1,x2,node);
    int p2=finalQuery(right,mid+1,endd,x1,x2,node);

    return p1+p2;
}

int query(int pos, int start, int endd, int y1,int y2, int x1, int x2)
{
    if(y2<start || y1>endd)
        return 0;
    if(y1<=start && endd<=y2)
        return (finalQuery(1,0,sizee,x1,x2,pos));
    int mid=(start+endd)/2;
    int left=pos*2;
    int right=left+1;

    int p1=query(left,start,mid,y1,y2,x1,x2);
    int p2=query(right,mid+1,endd,y1,y2,x1,x2);

    return p1+p2;
}

void finalUpdate(int pos, int low, int high,int x, int val, int node)
{
    if(low==high)
    {
        fin_seg[node][pos]=val;
    }
    else
    {
        int mid=(low+high)/2;
        int left=pos*2;
        int right=left+1;

        if(low<=x && x<=mid)
        {
            finalUpdate(left,low,mid,x,val,node);
        }
        else
        {
            finalUpdate(right,mid+1,high,x,val,node);
        }

        fin_seg[node][pos]=fin_seg[node][left]+fin_seg[node][right];
    }
}

void update(int pos, int low, int high, int x, int y, int val)
{
    if(low==high)
    {
        finalUpdate(1,0,sizee,x,val,pos);
    }
    else
    {
        int mid=(low+high)/2;
        int left=pos*2;
        int right=left+1;

        if(low<=y && y<=mid)
        {
            update(left,low,mid,x,y,val);
        }
        else
        {
            update(right,mid+1,high,x,y,val);
        }

        for(int i=0;i<2*maxn;i++)
        {
            fin_seg[pos][i]=fin_seg[left][i]+fin_seg[right][i];
        }
    }
}



int main()
{
   // fast_cin;
    int t,cas=1;
   // cin>>t;
   scanf("%d", &t);
    sizee=1002;
    while(t--)
    {
        printf("Case %d:\n",cas++);
        int q;
        scanf("%d", &q);
        mem(fin_seg,0);
      //  mem(ini_seg,0);
        while(q--)
        {
            int m,x,y;
            scanf("%d%d%d", &m,&x,&y);

            if(m==0)
            {
               // sizee++;
                update(1,0,sizee,x,y,1);
            }
            else
            {
                int x2,y2;
                scanf("%d%d", &x2,&y2);

                int ans=query(1,0,sizee,y,y2,x,x2);
                printf("%d\n", ans);
            }

        }
    }

    return 0;
}
