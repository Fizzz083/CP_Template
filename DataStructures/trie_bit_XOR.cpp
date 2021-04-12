#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
#define M 200015


struct prefix
{
    bool endmark;
    ll cnt_trees;
    prefix *next[2];

    prefix()
    {
        cnt_trees=0;
        endmark=false;

        for(ll i=0; i<2; i++)
        {
            next[i]=NULL;

        }
    }
}*root;

int idx(char c)
{

    if(c=='A')
        return 0;
    else if(c=='C')
        return 1;
    else if(c=='G')
        return 2;
    else
        return 3;

}


void insert_into_trie(ll num)
{
    prefix *current=root;

    for(ll i=32; i>=0; i--)
    {
        ll num2=num;
        bool bit =(num2>>i)&1;

        if(current->next[bit]==NULL)
            current->next[bit]=new prefix;

        current=current->next[bit];
    }
}

ll search_into_trie(ll pos, prefix *current)
{
    if(pos<0)
        return 0;

    if(current->next[1]!=NULL && current->next[0]!=NULL)
    {
        //cout<<pos<<endl;
        return (powl(2,pos) + min(search_into_trie(pos-1,current->next[1]),search_into_trie(pos-1,current->next[0]) ));
    }


    if(current->next[0]!=NULL)
        return search_into_trie(pos-1,current->next[0]);
    if(current->next[1]!=NULL)
        return search_into_trie(pos-1,current->next[1]);
}


void del(prefix* cur)
{

    for(ll i=0; i<4; i++)
    {
        if(cur->next[i])
            del(cur->next[i]);

    }

    delete(cur);
}



int main()
{

   // freopen("input.txt", "r", stdin);

   ll n;
   cin>>n;

   root = new prefix;

   for(ll i=0;i<n;i++)
   {
        ll num;
        cin>>num;

        insert_into_trie(num);
    }

    ll ans=search_into_trie(32,root);

    cout<<ans<<endl;


    return 0;
}
