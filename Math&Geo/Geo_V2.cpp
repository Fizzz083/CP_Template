
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * ((b) / gcd(a, b)))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define lllim 2147483648
#define Pi acos(-1.0)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mem(a, b) memset(a, b, sizeof(a))
#define fill_(a, b) fill(a, a + n, b);
#define MOD 1000000007
#define fast_cin                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define filein freopen("input.txt", "r", stdin)
//#define D(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define case        \
    int t, cas = 1; \
    cin >> t;       \
    while (t--)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, n, a) for (int i = n; i >= a; i--)
#define sim template <class T

/*------------------------------Graph Moves----------------------------*/
//const int fx[] = {+1, -1, +0, +0};
//const int fy[] = {+0, +0, +1, -1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

inline ll _gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (!b)
        return a;
    return _gcd(b, a % b);
}
inline ll _pow(ll a, ll y)
{
    ll z = 1;
    rep(i, 1, y) { z *= a; }
    return z;
}
inline ll _lcm(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    return (a / _gcd(a, b)) * b;
}
inline ll bigmod(ll n, ll m, ll mod)
{
    ll ret = 1, a = n % mod;
    while (m)
    {
        if (m & 1)
            ret = (ret * a) % mod;
        m >>= 1;
        a = (a * a) % mod;
    }
    ret %= mod;
    return ret;
}
sim > void ckmin(T &a, const T &b) { a = b < a ? b : a; }
sim > void ckmax(T &a, const T &b) { a = b > a ? b : a; }

///.............................input.................................///
sim > void readvec(std::vector<T> &v, const int n)
{
    rep(i, 0, n)
    {
        T p;
        std::cin >> p;
        v.pb(p);
    }
}
///...........................input end...............................///

using namespace std;
using namespace __gnu_pbds;

#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << ",\n"[++it == istream_iterator<string>()];
    err(it, args...);
}

const int maxn = 1000001;

const double pi = acos(-1.0);
const double eps = 1e-9;

double ang;

typedef double T;
struct pt
{
    T x, y;
    pt() {}
    pt(T _x, T _y) : x(_x), y(_y) {}
    pt operator+(const pt &p) const
    {
        return pt(x + p.x, y + p.y);
    }
    pt operator-(const pt &p) const
    {
        return pt(x - p.x, y - p.y);
    }
    pt operator*(const T &d) const
    {
        return pt(x * d, y * d);
    }
    pt operator/(const T &d) const
    {
        return pt(x / d, y / d);
    }
    bool operator==(const pt &p) const
    {
        return (x == p.x and y == p.y);
    }
    bool operator!=(const pt &p) const
    {
        return !(x == p.x and y == p.y);
    }
    bool operator<(const pt &p) const
    {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }
};

T sq(pt p)
{
    return p.x * p.x + p.y * p.y;
}

double abs(pt p)
{
    return sqrt(sq(p));
}

pt translate(pt v, pt p)
{
    return p + v;
}

pt scale(pt c, double factor, pt p)
{
    return c + (p - c) * factor;
}

pt rot(pt p, double a)
{
    return pt(p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a));
}

pt perp(pt p)
{
    return pt(-p.y, p.x);
}

T dot(pt v, pt w)
{
    return v.x * w.x + v.y * w.y;
}

bool isPerp(pt v, pt w)
{
    return dot(v, w) == 0;
}

double smallAngle(pt v, pt w)
{
    double cosTheta = dot(v, w) / abs(v) / abs(w);
    if (cosTheta < -1)
        cosTheta = -1;
    if (cosTheta > 1)
        cosTheta = 1;
    return acos(cosTheta);
}

T cross(pt v, pt w)
{
    return v.x * w.y - v.y * w.x;
}

T orient(pt a, pt b, pt c)
{
    return cross(b - a, c - a);
}

bool inAngle(pt a, pt b, pt c, pt x)
{
    assert(orient(a, b, c) != 0);
    if (orient(a, b, c) < 0)
        swap(b, c);
    return orient(a, b, x) >= 0 and orient(a, c, x) <= 0;
}

//Line
struct line
{
    pt v;
    T c;
    line() {}
    //From points P and Q
    line(pt p, pt q)
    {
        v = (q - p);
        c = cross(v, p);
    }
    //From equation ax + by = c
    line(T a, T b, T c)
    {
        v = pt(b, -a);
        c = c;
    }
    //From direction vector v and offset c
    line(pt v, T c)
    {
        v = v;
        c = c;
    }

    //These work with T = int / double
    T side(pt p);
    double dist(pt p);
    double sqDist(pt p);
    line perpThrough(pt p);
    bool cmpProj(pt p, pt q);
    line translate(pt t);

    //These require T = double
    line shiftLeft(double dist);
    pt proj(pt p);
    pt refl(pt p);
};

T line ::side(pt p)
{
    return cross(v, p) - c;
}

double line ::dist(pt p)
{
    return abs(side(p)) / abs(v);
}

double line ::sqDist(pt p)
{
    return side(p) * side(p) / (double)sq(v);
}

line line ::perpThrough(pt p)
{
    return line(p, p + perp(v));
}

bool line ::cmpProj(pt p, pt q)
{
    return dot(v, p) < dot(v, q);
}

line line ::translate(pt t)
{
    return line(v, c + cross(v, t));
}

line line ::shiftLeft(double dist)
{
    return line(v, c + dist * abs(v));
}

bool areParallel(line l1, line l2)
{
    return (l1.v.x * l2.v.y == l1.v.y * l2.v.x);
}

bool areSame(line l1, line l2)
{
    return areParallel(l1, l2) and (l1.v.x * l2.c == l2.v.x * l1.c) and (l1.v.y * l2.c == l2.v.y * l1.c);
}

bool inter(line l1, line l2, pt &out)
{
    T d = cross(l1.v, l2.v);
    if (d == 0)
        return false;
    out = (l2.v * l1.c - l1.v * l2.c) / d;
    return true;
}

pt line ::proj(pt p)
{
    return p - perp(v) * side(p) / sq(v);
}

pt line ::refl(pt p)
{
    return p - perp(v) * 2 * side(p) / sq(v);
}

line intBisector(line l1, line l2, bool interior)
{
    assert(cross(l1.v, l2.v) != 0);
    double sign = interior ? 1 : -1;
    return line(l2.v / abs(l2.v) + l1.v * sign / abs(l1.v),
                l2.c / abs(l2.v) + l1.c * sign / abs(l1.v));
}

//Segment
bool inDisk(pt a, pt b, pt p)
{
    return dot(a - p, b - p) <= 0;
}

bool onSegment(pt a, pt b, pt p)
{
    return orient(a, b, p) == 0 and inDisk(a, b, p);
}

bool properInter(pt a, pt b, pt c, pt d, pt &i)
{
    double oa = orient(c, d, a),
           ob = orient(c, d, b),
           oc = orient(a, b, c),
           od = orient(a, b, d);

    //Proper intersection exists iff opposite signs
    if (oa * ob < 0 and oc * od < 0)
    {
        i = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

bool inters(pt a, pt b, pt c, pt d)
{
    pt out;
    if (properInter(a, b, c, d, out))
        return true;
    if (onSegment(c, d, a))
        return true;
    if (onSegment(c, d, b))
        return true;
    if (onSegment(a, b, c))
        return true;
    if (onSegment(a, b, d))
        return true;
    return false;
}

double segPoint(pt a, pt b, pt p)
{
    if (a != b)
    {
        line l(a, b);
        if (l.cmpProj(a, p) and l.cmpProj(p, b))
            return l.dist(p);
    }
    return min(abs(p - a), abs(p - b));
}

double segSeg(pt a, pt b, pt c, pt d)
{
    pt dummy;
    if (properInter(a, b, c, d, dummy))
        return 0;
    return min(min(min(segPoint(a, b, c), segPoint(a, b, d)), segPoint(c, d, a)), segPoint(c, d, b));
}

//int latticePoints (pt a, pt b){
//    //requires int representation
//    return __gcd (abs (a.x - b.x), abs (a.y - b.y)) + 1;
//}

bool isConvex(vector<pt> &p)
{
    bool hasPos = false, hasNeg = false;
    for (int i = 0, n = p.size(); i < n; i++)
    {
        int o = orient(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (o > 0)
            hasPos = true;
        if (o < 0)
            hasNeg = true;
    }
    return !(hasPos and hasNeg);
}

double areaTriangle(pt a, pt b, pt c)
{
    return abs(cross(b - a, c - a)) / 2.0;
}

double areaPolygon(const vector<pt> &p)
{
    double area = 0.0;
    for (int i = 0, n = p.size(); i < n; i++)
    {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return fabs(area) / 2.0;
}

ll is_point_in_convex(vector<pt>& p, pt &x)  // O(log n)
{
    ll n = p.size();
    if (n < 3)
        return 1;
    ll a =orient(p[0], p[1], x), b = orient(p[0], p[n - 1], x);
    if (a < 0 || b > 0)
        return 1;
    ll l = 1, r = n - 1;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (orient(p[0], p[mid], x) >= 0)
            l = mid;
        else
            r = mid;
    }
    ll k = orient(p[l], p[r], x);
    if (k <= 0)
        return -k;
    if (l == 1 && a == 0)
        return 0;
    if (r == n - 1 && b == 0)
        return 0;
    return -1;
}

bool pointInPolygon(const vector<pt> &p, pt q) //rezaul vai's
{
    bool c = false;
    for (int i = 0, n = p.size(); i < n; i++)
    {
        int j = (i + 1) % p.size();
        if ((p[i].y <= q.y and q.y < p[j].y or p[j].y <= q.y and q.y < p[i].y) and
            q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}

pt centroidPolygon(const vector<pt> &p)
{
    pt c(0, 0);
    double scale = 6.0 * areaPolygon(p);
    //    if (scale < eps) return c;
    for (int i = 0, n = p.size(); i < n; i++)
    {
        int j = (i + 1) % n;
        c = c + (p[i] + p[j]) * cross(p[i], p[j]);
    }
    return c / scale;
}

//Circle
pt circumCenter(pt a, pt b, pt c)
{
    b = b - a;
    c = c - a;
    assert(cross(b, c) != 0);
    return a + perp(b * sq(c) - c * sq(b)) / cross(b, c) / 2;
}

bool circle2PtsRad(pt p1, pt p2, double r, pt &c)
{
    double d2 = sq(p1 - p2);
    double det = r * r / d2 - 0.25;
    if (det < 0.0)
        return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

int circleLine(pt c, double r, line l, pair<pt, pt> &out)
{
    double h2 = r * r - l.sqDist(c);
    if (h2 < 0)
        return 0; // the line doesn't touch the circle;
    pt p = l.proj(c);
    pt h = l.v * sqrt(h2) / abs(l.v);
    out = make_pair(p - h, p + h);
    return 1 + (h2 > 0);
}

int circleCircle(pt c1, double r1, pt c2, double r2, pair<pt, pt> &out)
{
    pt d = c2 - c1;
    double d2 = sq(d);
    if (d2 == 0)
    { //concentric circles
        assert(r1 != r2);
        return 0;
    }
    double pd = (d2 + r1 * r1 - r2 * r2) / 2;
    double h2 = r1 * r1 - pd * pd / d2; // h ^ 2
    if (h2 < 0)
        return 0;
    pt p = c1 + d * pd / d2, h = perp(d) * sqrt(h2 / d2);
    out = make_pair(p - h, p + h);
    return 1 + h2 > 0;
}

int tangents(pt c1, double r1, pt c2, double r2, bool inner, vector<pair<pt, pt>> &out)
{
    if (inner)
        r2 = -r2;
    pt d = c2 - c1;
    double dr = r1 - r2, d2 = sq(d), h2 = d2 - dr * dr;
    if (d2 == 0 or h2 < 0)
    {
        assert(h2 != 0);
        return 0;
    }
    for (int sign : {-1, 1})
    {
        pt v = pt(d * dr + perp(d) * sqrt(h2) * sign) / d2;
        out.push_back(make_pair(c1 + v * r1, c2 + v * r2));
    }
    return 1 + (h2 > 0);
}

//Convex Hull - Monotone Chain
int sz; //returned polygon's size;
pt H[100000 + 5];
vector<pt> monotoneChain(vector<pt> &v) /// from you_know_who
{
    if(v.size()==1)
		return v;

	sort(v.begin(), v.end());
	vector<pt> up(2*v.size()+2), down(2*v.size()+2);
    int szup=0, szdw=0;

	for(int i=0;i<v.size();i++)
	{
        // cout<<"p: ("<<v[i].x<<" "<<v[i].y<<" )"<<endl;
        while(szup>1 && orient(up[szup-2], up[szup-1], v[i])>=0)
            szup--;
        while(szdw>1 && orient(down[szdw-2], down[szdw-1], v[i])<=0)
            szdw--;
        up[szup++]=v[i];
        down[szdw++]=v[i];
	}

    if(szdw>1)
        szdw--;

    reverse(up.begin(), up.begin()+szup);
	for(int i=0;i<szup-1;i++)
		down[szdw++]= up[i];
    
    
    if(szdw==2 && down[0].x==down[1].x && down[0].y==down[1].y)
    {
        szdw--;
    }
    sz = szdw;
    
	return down;
}

pt toPoint(pt p1, pt p2)
{
    return pt(p2.x-p1.x,p2.y - p1.y);
}

double angle(pt a, pt o, pt b)
{
    //double result = atan2(P3.y - P1.y, P3.x - P1.x) - atan2(P2.y - P1.y, P2.x - P1.x);

    double result;

    pt oa = toPoint(o, a);
    pt ob = toPoint(o, b);

    if(sq(oa)==0 || sq(ob)==0){
        return 0.0;
    }

    result = acos(dot(oa, ob)/sqrt(sq(oa)*sq(ob)));
    result*=180.0;
    result/=Pi;
    return result;
}



void solve()
{   
    int n;
    cin>>n;
    vector<pt>a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i].x<<" ff "<<a[i].y<<endl;;
    // }
    int m;

    reverse(all(a));
    cin>>m;
    
    bool f=1;
    for(int i=0;i<m;i++)
    {
        pt t;
        cin>>t.x>>t.y;
       // cout<<t.x<<" "<<t.y<<endl;

        if(is_point_in_convex(a, t)>=0){
            f=0;
        }
    }
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


}

int main()
{
    fast_cin;

   // case
    {
        // if(n==0) break;
     //    cout<<"Case "<<cas++<<": ";
        solve();
    }

    return 0;
}
