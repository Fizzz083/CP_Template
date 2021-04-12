#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int f[1000006];

void kmp_process(string pattern)
{
    int m=pattern.size();
    int j=0;
    f[0]=0;
    for(int i=1;i<m;i++)
    {
       // cout<<2<<endl;
        if(pattern[i]==pattern[j])
        {
            f[i]=j+1;
            j++;

        }
        else
        {
            while(j!=0)
            {
               // cout<<2<<endl;
                j=f[j-1];
                if(pattern[i]==pattern[j])
                {
                    f[i]=j+1;
                    j++;
                    break;
                }
            }
        }
    }


}

int kmp(string txt, string pattern)
{
    int n=txt.size();
    int m=pattern.size();

    int j=0;

    for(int i=0;i<n;i++)
    {
        if(txt[i]==pattern[j])
        {
           // h[i]=j+1;
            j++;

        }
        else
        {
            while(j!=0)
            {
                j=f[j-1];
                if(txt[i]==pattern[j])
                {
                   //h[i]=j+1;
                    j++;
                    break;
                }
            }
        }

    }

   /* for(int i=0;i<n;i++)
    {
        cout<<h[i]<<" ";

    } */
   // cout<<endl;

    return j;


}

int main()
{
    int t,p;
    scanf("%d", &t);
    for(p=1;p<=t;p++)
    {
        string s,sr;

       cin>>s;
       // strcpy(s,sr);
       sr=s;
        reverse(sr.begin(),sr.end());
       // cout<<sr<<endl;
        memset(f,0,sizeof(f));
        kmp_process(sr);

        int ans=kmp(s,sr);
       // cout<<ans<<endl;

        printf("Case %d: %d\n",p,2*s.size()-ans);


    }

}
