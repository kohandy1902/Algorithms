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

const int inf=INT_MAX;
const ll infll=LONG_LONG_MAX;
const ll mod=1000000007LL;

int gcd(int x,int y){return y?gcd(y,x%y):x;}

struct node
{
	pii p;
	int ax, sx, ex, sy, ey;
}T[2020202];

int sq(int x){return x*x;}
bool cmp(pii k, pii l){return mp(k.se,k.fi)<mp(l.se,l.fi);}
int dist(pii k, pii l){return sq(k.fi-l.fi)+sq(k.se-l.se);}

int n,m,q;
pii d[1010101];
int vi[2020202];
int ans;

void make_tree(int p, int s, int e)
{
	//printf("%d %d %d\n",p,s,e);
	int minx=0,maxx=n,miny=0,maxy=m;
	int mid=s+e>>1;
	for(int i=s;i<=e;i++)
	{
		minx=min(minx,d[i].fi);
		maxx=max(maxx,d[i].fi);
		miny=min(miny,d[i].se);
		maxy=max(maxy,d[i].se);
	}
	T[p].ax=(maxx-minx>maxy-miny);
	if(T[p].ax) sort(d+s,d+e+1);
	else sort(d+s,d+e+1,cmp);
	T[p]={d[mid],T[p].ax,minx,maxx,miny,maxy};
	vi[p]=1;
	if(s<=mid-1) make_tree(p<<1,s,mid-1);
	if(mid+1<=e) make_tree(p<<1|1,mid+1,e);
}

void mindist(int p, pii k)
{
	ans=min(ans,dist(T[p].p,k));
	if(T[p].ax)
	{
		if(T[p].p>=k)
		{
			if(vi[p<<1]) mindist(p<<1,k);
			if(vi[p<<1|1] && sq(T[p<<1|1].sx-k.fi)<ans) mindist(p<<1|1,k);
		}
		else
		{
			if(vi[p<<1|1]) mindist(p<<1|1,k);
			if(vi[p<<1] && sq(T[p<<1].ex-k.fi)<ans) mindist(p<<1,k);
		}
	}
	else
	{
		if(cmp(k,T[p].p))
		{
			if(vi[p<<1]) mindist(p<<1,k);
			if(vi[p<<1|1] && sq(T[p<<1|1].sy-k.se)<ans) mindist(p<<1|1,k);
		}
		else
		{
			if(vi[p<<1|1]) mindist(p<<1|1,k);
			if(vi[p<<1] && sq(T[p<<1].ey-k.se)<ans) mindist(p<<1,k);
		}
	}
}


int main()
{
	scanf("%d",&q);
	for(int i=0;i<q;i++) scanf("%d %d",&d[i].fi,&d[i].se);
	make_tree(1,0,q-1);

}