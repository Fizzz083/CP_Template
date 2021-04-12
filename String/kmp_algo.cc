#include<bits/stdc++.h>
using namespace std;
int main()
{

    char t[1000],p[1000];
    gets(t);
    gets(p);
    int i , j;
    for(i=0;i<strlen(t);i++)\
    {
        bool found=true;
        for(j=0;j<strlen(p) && found;j++)
        {
            if(i+j>=strlen(t) || p[j]!=t[i+j])
                found=false;
        }
        if(found)
        {
            cout<<"found at "<<i+1<<"th position"<<endl;
        }
    }
    return 0;
}
