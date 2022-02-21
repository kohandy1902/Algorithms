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
const ll mod = 1000000007LL;
const int MAXN = 1010;

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

string s;

int z[101010];

void Z()
{
	int l = 0, r = 0;
	for(int i = 1; i < s.size(); i++)
	{
		if(r < i)
		{
			for(int j = i; j < s.size(); j++)
			{
				if(s[j - i] == s[j])
				{
					z[i] = j - i + 1;
					l = i;
					r = j;
				}
				else break;
			}
		}
		else if(z[i - l] <= r - i) z[i] = z[i - l];
		else
		{
			z[i] = r - i + 1;
			l = i;
			for(int j = r + 1; j < s.size(); j++)
			{
				if(s[j - l] == s[j])
				{
					z[i] = j - i + 1;
					r = j;
				}
				else break;
			}
		}
	}

	z[0] = s.size();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    getline(cin, s);
	return 0;
}