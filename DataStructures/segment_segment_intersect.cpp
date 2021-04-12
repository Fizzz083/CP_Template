///...UVa 11343....
///................

///*****************************************************///
///*...................................................*///
///*.............MD MUSTAFIZUR RAHMAN ARMAN............*///
///*.........................KUET......................*///
///*...................................................*///
///*****************************************************///

#include<bits/stdc++.h>
typedef long long ll;
#define pb           push_back
#define ff           first
#define ss           second
#define gcd(a, b)    __gcd(a, b)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define D(x)   	     cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define all(v)       (v.begin(),v.end())
#define intlim       2147483648
#define Pi           2*acos(0.0)
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

struct point
{
    double x,y;
};

///q lies on pr segment
bool on_segment(point p, point q, point r)
{
    if((q.x<=max(p.x, r.x) && q.x>=min(p.x,r.x)) && (q.y<=max(p.y,r.y) && q.y>=min(p.y, r.y)))
        return true;
    return false;
}

///pq segment, r point..
int orientation(point p, point q, point r)
{
    double ori=(q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);

    if(ori==0.0)
        return 0;

    return (ori>0.0)? 1: 2;

    /// 0 colinear
    /// 1 for clocwise
    /// 2 for counterclockwise
}

//void intersect_point(point A, point B, point C, point D)
//{
//    /// Line AB represented as a1x + b1y = c1
//    int a1 = A.y - B.y;
//    int b1 = B.x - A.x;
//
//    int c1 = a1*(A.x)+b1*A.y;
//
//    /// Line CD represented as a2x + b2y = c2
//    //cout<<" A : "<<A.x<<" "<<A.y<<"\nB : "<<B.x<<" "<<B.y<<"\nC : "<<C.x<<" "<<C.y<<"\nD : "<<D.x<<" "<<D.y<<endl;
//
//   int a2 = C.y - D.y;
//    int b2 = C.x - D.x;
//
//
//    int c2 = a2*(C.x)+b2*C.y;
//
//    int det = a1*b2-a2*b1;
//    int Dx = c1*b2 - c2*b1;
//    int Dy = a1*c2 - a2*c1;
//
//    //cout<<det<<endl;
//
//
//    double x = double(Dx)/det;
//    double y = double(Dy)/det;
//    cout<<setprecision(2)<<fixed<<x<<" "<<y<<endl;
//    /// return make_pair(x, y);
//
//}

bool intersect(point p1, point q1, point p2, point q2)
{
    int o1=orientation(p1,q1,p2); ///p1q1 segment, p2 point
    int o2=orientation(p1,q1,q2);
    int o3=orientation(p2,q2,p1);
    int o4=orientation(p2,q2,q1);

    if(o1!=o2 && o3!=o4)
    {
        ///segment two, intersect in a point

        return 1;

    }
    else if((o1==0 && on_segment(p1,p2,q1)) ||
            (o2==0 && on_segment(p1,q2,q1)) ||
            (o3==0 && on_segment(p2,p1,q2)) ||
            (o4==0 && on_segment(p2,q1,q2)))
    {
        return 1;
    }

    else
        return 0;

}

///



int main()
{
    freopen("input.txt", "r", stdin);
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d" , &n);
        pair<point,point> a[n+4];
        for(int i=0;i<n;i++)
        {
            point p,q;
            scanf("%lf%lf%lf%lf", &p.x, &p.y, &q.x, &q.y);
            a[i]={p,q};
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            bool flag=0;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                flag=intersect(a[i].ff,a[i].ss, a[j].ff, a[j].ss);

                if(flag==1)
                    break;
            }
            if(flag==0)
                ans++;


        }
        printf("%d\n", ans);
    }

    return 0;
}

