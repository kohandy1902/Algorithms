#include<cstdio>
#include<vector>
using namespace std;
int n,m,a,b,sp[101010][25],par[101010],d[101010];
vector<int> v[101010];
void dfs(int x,int y)
{
	d[x]=y;
	for(auto i : v[x])
	{
		if(!d[i])
		{
			par[i]=x;
			dfs(i,y+1);
		}
	}
}
void sparse()
{
	for(int j=0;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(j==0) sp[i][j]=par[i];
			else sp[i][j]=sp[sp[i][j-1]][j-1];
		}
	}
}
int lca(int x,int y)
{
	if(d[x]>d[y]) swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(d[y]-d[x]>=(1<<i)) y=sp[y][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--)
	{
		if(sp[x][i]!=sp[y][i])
		{
			x=sp[x][i];
			y=sp[y][i];
		}
	}
	return sp[x][0];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	par[1]=1;
	dfs(1,1);
	sparse();
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}

