#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

typedef pair<int,int> pii;

struct qu{int l,r,idx;}query[101010];

int n,m,si;
int cnt[1010101],d[101010],tmp,ans[101010];

bool cmp(qu k, qu l)
{
	if(k.l/si==l.l/si) return k.r<l.r;
	return k.l/si<l.l/si;
}

void add(int x)
{
	cnt[d[x]]++;
	if(cnt[d[x]]==1) tmp++;
}

void sub(int x)
{
	if(cnt[d[x]]) cnt[d[x]]--;
	if(cnt[d[x]]==0) tmp--;
}

void pro(qu x, qu y)
{
	for(int i=y.l;i<x.l;i++) add(i); 
	for(int i=x.r+1;i<=y.r;i++) add(i); 
	for(int i=y.r+1;i<=x.r;i++) sub(i); 
	for(int i=x.l;i<y.l;i++) sub(i); 
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}

	si=sqrt(n);

	scanf("%d",&m);

	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&query[i].l,&query[i].r);
		query[i].idx=i;
	}

	sort(query+1,query+m+1,cmp);

	query[0].r=0; query[0].l=1;

	for(int i=1;i<=m;i++)
	{
		pro(query[i-1],query[i]);
		ans[query[i].idx]=tmp;
	}

	for(int i=1;i<=m;i++)
	{
		printf("%d\n",ans[i]);
	}
}

