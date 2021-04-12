#include<bits/stdc++.h>
using namespace std;
int mark[805];
int p=0,pp[805];
vector<int>v,v1;


void sieve()
{
    int n=801;
    mark[1]=1;

    for(int i=2;i<=n;i+=2)
    {
        mark[i]=1;
    }
    mark[2]=0;
    v.push_back(2);

    for(int i=3;i<=n;i+=2)
    {
        if(mark[i]!=1) { v.push_back(i);}
        if(i<sqrt(n+1)){
        for(int j=i*i;j<=n;j+=(2*i))
        mark[j]=1;
        }

    }

}

int ch(int b)
{
    int i;
    if(mark[b]==0) return b;
    int p=1;

    for(i=0;i<v.size() && v[i]<=b/2+1 ;i++)
    {
        if(b%v[i]==0)
        {
            p=v[i];
        }
    }
    return p;
}

int zero(int n,int r)
{
    int c=r,cnt=0;
    while(true)
    {
        if(n/r==0) break;
        cnt+=(n/r);
        r*=r;

    }
    return cnt;


}


int main()


{
    sieve();
    while(true)
    {
        int b,n,r,t;
        cin>>b>>n;
        r=ch(b);
        cout<<r<<endl;
        t=zero(n,r);
        cout<<t<<endl;
    }


    return 0;
}
