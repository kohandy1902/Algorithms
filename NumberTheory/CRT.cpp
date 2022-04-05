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
const int MAXN = 2020;

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

ll gcdext(ll x, ll y, ll &k, ll &l)
{
    if(y)
    {
        ll tmp = gcdext(y, x % y, l, k);
        l -= x / y * k;
        return tmp;
    }
    k = 1, l = 0;
    return x;
}

ll crt(ll a, ll m, ll b, ll n)
{
    if (n > m) swap(a, b), swap(m, n);
    ll x, y;
    ll g = gcdext(m, n, x, y);
    if(abs(a - b) % g != 0) return -1;
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
}

int main()
{
    return 0;
}