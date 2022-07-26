#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back 
#define allv(V) (V).begin(), (V).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> base;

const int inf = INT_MAX;
const ll infll = LONG_LONG_MAX;
const ll mod = 1000000007LL;
const int MAXN = 1e8;

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

ll n, l[101010], p[101010], s[101010], dp[101010], pos = 1;

struct line
{
    ll a, b;
    line() : a(0), b(infll) {}
    line(ll a, ll b) : a(a), b(b) {}
    ll calc(ll x)
    {
        return a * x + b;
    }
};

struct node
{
    int l, r;
    line v;
}T[2727272];

void upd(int p, int s, int e, line x)
{
    line low = T[p].v;
    line high = x;
    if(low.calc(s) > high.calc(s)) swap(low, high);

    if(low.calc(e) <= high.calc(e))
    {
        T[p].v = low;
        return;
    }
    int mid = s + e >> 1;
    if(low.calc(mid) <= high.calc(mid))
    {
        T[p].v = low;
        if(!T[p].r) T[p].r = ++pos;
        upd(T[p].r, mid + 1, e, high);
    }
    else
    {
        T[p].v = high;
        if(!T[p].l) T[p].l = ++pos;
        upd(T[p].l, s, mid, low);
    }
}

ll query(int p, int s, int e, ll x)
{
    if(!p) return infll;
    ll tmp = T[p].v.calc(x);
    int mid = s + e >> 1;
    if(x <= mid) return min(tmp, query(T[p].l, s, mid, x));
    return min(tmp, query(T[p].r, mid + 1, e, x));
}

int main()
{
    return 0;
}