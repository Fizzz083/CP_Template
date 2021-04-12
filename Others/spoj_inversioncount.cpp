#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);

        ll ara[n+5];

        for(ll i=0;i<n;i++)
        {
            ll p;
            scanf("%lld", &p);
            ara[i]=p;
        }

        ll ans=0;

        for(ll i=0;i<n-1;i++)
        {
            for(ll j=i+1;j<n;j++)
            {
                if(ara[j]<ara[i])
                    ans++;
            }

        }
        printf("%lld\n", ans);


    }

}
