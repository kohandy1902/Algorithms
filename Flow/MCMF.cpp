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
const int MAXN = 1010;

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

struct EDGE
{
	int v, c, d, r;
	EDGE(int v, int c, int d, int r) : v(v), c(c), d(d), r(r) {}
};

vector<EDGE> ed[MAXN];
int S, E;
int dis[MAXN], pe[MAXN];
bool inq[MAXN];

void addedge(int a, int b, int c, int d)
{
	ed[a].eb(b, c, d, ed[b].size());
	ed[b].eb(a, 0, -d, ed[a].size() - 1);
}

pii MCMF()
{
	int cost = 0, flow = 0;
	while(1)
	{
		queue<int> q;
		for(int i = 1; i <= E; i++) 
		{
			dis[i] = inf;
			inq[i] = false;
		}
		dis[S] = 0;
		q.push(S);
		inq[S] = true;
		while(!q.empty())
		{
			int t = q.front();
			q.pop();
			inq[t] = false;
			for(auto e : ed[t])
			{
				if(e.c && dis[t] + e.d < dis[e.v]) 
				{
					dis[e.v] = dis[t] + e.d;
					pe[e.v] = e.r;
					if(!inq[e.v])
					{
						q.push(e.v);
						inq[e.v] = true;
					}
				}
			}
		}
		if(dis[E] == inf) break;
		int f = inf;
		for(int x = E; x != S; x = ed[x][pe[x]].v)
		{
			EDGE &e = ed[x][pe[x]];
			f = min(f, ed[e.v][e.r].c);
		}
		flow += f;
		cost += dis[E] * f;
		for(int x = E; x != S; x = ed[x][pe[x]].v)
		{
			EDGE &e = ed[x][pe[x]];
			e.c += f;
			ed[e.v][e.r].c -= f;
		}
	}
	return mp(flow, cost);
}

int main()
{
	return 0;
}