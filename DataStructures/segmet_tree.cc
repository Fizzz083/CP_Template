#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back()
#define mp make_pair
#define pii pair<int,int>
const int INF=1e9;
const int maxn=1000006;

int ara[maxn];
int tree[maxn*3];

void init(int node , int b, int e)
{
    if(b==e)
    {
        tree[node]=ara[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
    return;
}

int query(int node, int b, int e, int i , int j)
{
    if(i>e || j<b)
    {
        return INF;
    }
    else if(b>=i && e<=j)
    {
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    //cout<<p1<<" "<<p2<<"   i  "<<i<<"   j  "<<j<<"   b  "<<b<<"  e  "<<e<<endl;


    return min(p1,p2);
}
/*
void updated(int node, int b, int e, int i, int newvalue)
{
    if(i>e || i<b)
    {
        return ;
    }
    if(b>=i && e<=i)
    {
        tree[node]=newvalue;
        return ;
    }
    int left=node*2;
    int right=node*2+1;
    updated(left,b,mid,i,newvalue);
    updated(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
    return;
}

*/



int main()
{
    int n,m,t=1;
    scanf("%d", &n);
    while(n--)
    {
        memset(ara,INF,sizeof(ara));
        memset(tree,INF,sizeof(tree));
        int p,i,j,k;
        scanf("%d%d", &m,&p);
        for(i=1;i<=m;i++)
        {
            scanf("%d", &ara[i]);
        }
        init(1,1,m);
        printf("Case %d:\n",t++);
        for(i=0;i<p;i++)
        {
            int x,y;
            scanf("%d%d", &x,&y);
            int ans=query(1,1,m,x,y);
            printf("%d\n", ans);
        }
        //printf("\n");

    }

}

