#include<cstdio>
#include<vector>
using namespace std;
int n,m,vi[101010],fi[101010],cycle;
vector<int> v[101010],ans;
void dfs(int x)
{
	vi[x]=1;
	for(auto i : v[x])
	{
		if(!vi[i])
		{
			vi[i]=1;
			dfs(i);
		}
		else if(!fi[i]) cycle=1;
	}
	fi[x]=1;
	ans.push_back(x);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vi[i]) dfs(i);
		if(cycle) 
		{
			puts("CYCLE!");
			return 0;
		}
	}
	while(!ans.empty())
	{
		printf("%d ",ans.back());
		ans.pop_back();
	}
}
