#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct co{int e,v;}tmp;
vector<co> v[202020];
queue<int> q;
int n,a,b,c,d[202020];
co bfs(int x)
{
	int ans=x;
	d[x]=1;
	q.push(x);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		if(d[ans]<d[t]) ans=t;
		for(auto i : v[t])
		{
			if(!d[i.e])
			{
				d[i.e]=d[t]+i.v;
				q.push(i.e);
			}
		}
	}
	return {ans,d[ans]-1};
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	tmp=bfs(1);
	for(int i=1;i<=n;i++) d[i]=0;
	tmp=bfs(tmp.e);
	printf("%d",tmp.v);
}

