#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int V,E,a,b,vi[10101],cnt;
vector<int> v[10101],rv[10101],scc[10101],ans;
void dfs(int x)
{
	vi[x]=1;
	for(auto i : v[x])
	{
		if(!vi[i]) dfs(i);
	}
	ans.push_back(x);
}
void f(int x,int si)
{
	vi[x]=1;	
	scc[si].push_back(x);
	for(auto i : rv[x])
	{
		if(!vi[i]) f(i,si);
	}
}
bool cmp(vector<int> k, vector<int> l)
{
	return k[0]<l[0];
}
int main()
{
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++)
	{
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		rv[b].push_back(a);
	}
	for(int i=1;i<=V;i++)
	{
		if(!vi[i]) dfs(i);
	}
	for(int i=1;i<=V;i++) vi[i]=0;
	while(!ans.empty())
	{
		int tmp=ans.back();
//		printf("%d\n",tmp);
		ans.pop_back();
		if(!vi[tmp]) f(tmp,cnt++);
	}
	printf("%d\n",cnt);
	sort(scc,scc+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		sort(scc[i].begin(),scc[i].end());
		scc[i].push_back(-1);
	}
	sort(scc,scc+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		for(auto j : scc[i]) printf("%d ",j);
		puts("");
	}
}
