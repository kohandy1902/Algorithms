#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define allv(V) (V).begin(),(V).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> base;

const int inf=10101010;
const ll infll=LONG_LONG_MAX;
const ll mod=1000000007LL;

int gcd(int x,int y){return y?gcd(y,x%y):x;}

void fft(vector<base> &vx, bool inv)
{
	ll n = vx.size();
	ll j = 0;
	vector<base> roots(n / 2);
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
	double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
	for(ll i = 0; i < n / 2; i++) roots[i] = base(cos(ang * i), sin(ang * i));

	for(ll i = 2; i <= n; i <<= 1)
	{
		ll st = n / i;
		for(ll j = 0; j < n; j += i)
		{
			for(ll k = 0; k < i / 2; k++)
			{
				base x = vx[j + k];
				base y = vx[j + k + i / 2] * roots[st * k];
				vx[j + k] = x + y;
				vx[j + k + i / 2] = x - y;
			}
		}
	}
	if(inv) for(ll i = 0; i < n; i++) vx[i] /= n;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w)
{
	vector<base> fv(v.begin(), v.end());
	vector<base> fw(w.begin(), w.end());
	ll n = 2;
	while(n < v.size() + w.size()) n <<= 1;
	fv.resize(n); fw.resize(n);
	fft(fv, 0); fft(fw, 0);
	for(ll i = 0; i < n; i++) fv[i] *= fw[i];
	fft(fv, 1);
	vector<ll> ret(n);
	for(ll i = 0; i < n; i++) ret[i] = (ll)round(fv[i].real());
	return ret;
}

int main()
{
	return 0;
}