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

const int inf = INT_MAX;
const ll infll = LONG_LONG_MAX;
const ll mod1 = 998244353LL;
const ll mod2 = 2281701377LL;
const int MAXN = 1010;

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

ll powll(ll x, ll y, ll m)
{
	if(y == 0) return 1;
	ll tmp = powll(x, y / 2, m);
	if(y % 2) return tmp * tmp % m * x % m;
	return tmp * tmp % m;
}

void fft(vector<ll> &vx, bool inv, ll m)
{
	ll n = vx.size();
	ll j = 0;
	vector<ll> roots(n / 2);
	for(ll i = 1; i < n; i++)
	{
		ll tmp = n >> 1;
		while(j >= tmp)
		{
			j -= tmp;
			tmp >>= 1;
		}
		j += tmp;
		if(i < j) swap(vx[i], vx[j]);
	}

	ll ang = powll(3, (m - 1) / n, m);
	if(inv) ang = powll(ang, m - 2, m);
	for(ll i = 0; i < n / 2; i++) roots[i] = (i ? roots[i - 1] * ang % m : 1);

	for(ll i = 2; i <= n; i <<= 1)
	{
		ll st = n / i;
		for(ll j = 0; j < n; j += i)
		{
			for(ll k = 0; k < i / 2; k++)
			{
				ll x = vx[j + k];
				ll y = vx[j + k + i / 2] * roots[st * k] % m;
				vx[j + k] = (x + y) % m;
				vx[j + k + i / 2] = (x - y + m) % m;
			}
		}
	}
	ll invn = powll(n, m - 2, m);
	if(inv) for(ll i = 0; i < n; i++) vx[i] = (vx[i] * invn) % m;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w, ll m)
{
	vector<ll> fv(v.begin(), v.end());
	vector<ll> fw(w.begin(), w.end());
	ll n = 2;
	while(n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0, m); fft(fw, 0, m);
	for(ll i = 0; i < n; i++) fv[i] = (fv[i] * fw[i]) % m;
	fft(fv, 1, m);
	return fv;
}

int main()
{
	return 0;
}