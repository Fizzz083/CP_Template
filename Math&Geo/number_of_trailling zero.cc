#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll mark[100000007];
ll p=0,pp[100000];
vector<ll>v;


void sieve(ll n)
{
    mark[1]=1;

    for(ll i=2; i<=n; i+=2)
    {
        mark[i]=1;
    }
    mark[2]=0;
    v.push_back(2);

    for(ll i=3; i<=n; i+=2)
    {
        if(mark[i]!=1)
        {
            //mark[i]=1;
            v.push_back(i);
        }
        if(i<sqrt(n+1))
        {
            for(ll j=i*i; j<=n; j+=(2*i))
                mark[j]=1;
        }

    }

}

int main()
{
    sieve(100000);
    ll n, m;
    while(true)
    {
        cin>>m>>n;
        ll l=m,k,j=0,zero=0,n1=n;
        for(ll i=2; i<=m; i++)
        {
            j=0;
            while(true)
            {
                if(n%v[i]!=0)
                    break;
                n/=v[i];
                j++;
            }
            ll c=0,j

            if(n==1)
            {
                k=v[i];
                j=j;
                break;
            }
            k=min()
        }
        //cout<<k<<" "<<j<<endl;
        while(true)
        {
            zero+=l/k;
            l/=k;
            if(l<=1)
                break;
        }
        double dig=0;
        // cout<<zero/j<<endl;
        for(ll i=1; i<=m; i++)
        {
            dig+=log(i);
        }
        dig/=log(n1);



        cout<<zero/j<<" "<<floor(dig+1.0)<<endl;
    }

    return 0;
}
