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

ll ex32(ll x, ll y, ll m)
{
    if(y == 0) return 1;
    ll tmp = ex32(x, y / 2, m);
    if(y & 1) return tmp * tmp % m * x % m;
    return tmp * tmp % m;
}

bool millerRabin32(ll n, ll a)
{
    ll d = n - 1;
    while(d % 2 == 0)
    {
        if(ex32(a, d, n) == n - 1) return true;
        d /= 2;
    }
    ll tmp = ex32(a, d, n);
    return tmp == n - 1 || tmp == 1;
}

bool isPrime32(ll n)
{
    if(n <= 1) return false;
    if(n <= 10000) 
    {
        for(ll i = 2; i * i <= n; i++) if(n % i == 0) return false;
        return true;
    }
    for (ll a : {2, 7, 61}) if(!millerRabin32(n, a)) return false;
    return true;
}

ll ex64(ll x, ll y, ll m)
{
    if(y == 0) return 1;
    ll tmp = ex64(x, y / 2, m);
    if(y & 1) return (__int128) tmp * tmp % m * x % m;
    return (__int128) tmp * tmp % m;
}

bool millerRabin64(ll n, ll a)
{
    ll d = n - 1;
    while(d % 2 == 0)
    {
        if(ex64(a, d, n) == n - 1) return true;
        d /= 2;
    }
    ll tmp = ex64(a, d, n);
    return tmp == n - 1 || tmp == 1;
}

bool isPrime64(ll n)
{
    if(n <= 1) return false;
    if(n <= 100000000) 
    {
        for(ll i = 2; i * i <= n; i++) if(n % i == 0) return false;
        return true;
    }
    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) if(a < n && !millerRabin64(n, a)) return false;
    return true;
}

int main()
{
    return 0;   
}