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

const int inf = 1 << 29;
const ll infll = LONG_LONG_MAX;
const ll mod = 1000000007LL;
const int MAXN = 5050;

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

ll n, q, col[505050], par[505050], sz[505050], pos, num[505050], nxt[505050];

vector<ll> v[505050];

// if parent is in edge vector, then add logic that exclude parent

void gsz(int x)
{
    sz[x] = 1;
    for(auto &i : v[x])
    {
        gsz(i, x);
        sz[x] += sz[i];
        if(sz[i] > sz[v[x][0]]) swap(i, v[x][0]);
    }
}

void hld(int x)
{
    num[x] = ++pos;
    for(auto &i : v[x])
    {
        nxt[i] = (i == v[x][0] ? nxt[x] : i);
        hld(i);
    }
}

int main()
{
    return 0;
}