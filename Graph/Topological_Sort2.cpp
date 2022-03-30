#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,m,a,b,in[101010];
vector<int> v[101010],ans;
queue<int> q;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		in[b]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	while(!q.empty())
	{
		int tmp=q.front();
		printf("%d ",tmp);
		q.pop();
		for(auto i : v[tmp])
		{
			in[i]--;
			if(!in[i]) q.push(i);
		}
	}
}
