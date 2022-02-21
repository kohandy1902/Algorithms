#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
#define pop pop_back
using namespace std;
typedef long long ll;
struct vec
{
	ll x,y;
	ll mag(){return x*x+y*y;}
	vec operator -(vec v){return (vec){x-v.x,y-v.y};}
	ll operator *(vec v){return x*v.y-y*v.x;}
	bool operator <(vec v)
	{
		if(y==v.y) return x<v.x;
		return y<v.y;
	}
}d[101010];
ll n,a,b,mi;
vector<vec> v;
bool cmp(vec k,vec l)
{
	vec tmp=d[0];
	if((k-tmp)*(l-tmp)==0) return k.mag()<l.mag();
	return (k-tmp)*(l-tmp)>0;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=0;i<n;i++)
	{
		scanf("%lld %lld",&d[i].x,&d[i].y);
		if(d[i]<d[mi]) mi=i;
	}
	swap(d[mi],d[0]);
	sort(d+1,d+n,cmp);
	v.pb(d[0]);
	v.pb(d[1]);
	for(ll i=2;i<n;i++)
	{
		while(v.size()>1)
		{
			if((d[i]-v[v.size()-1])*(v[v.size()-1]-v[v.size()-2])>=0) v.pop();
			else break;
		}
		v.pb(d[i]);
	}
	printf("%lld",(ll)v.size());
}