#include<cstdio>
#include<algorithm>
using namespace std;
int n,tree[404040],s=1,k,val;
int f(int x,int y)
{
	x+=s-1;y+=s-1;
	int ans=0;
	while(x<=y)
	{
		if(x%2==1) ans=max(ans,tree[x++]);
		if(y%2==0) ans=max(ans,tree[y--]);
		if(x>y) break;
		x/=2;y/=2;
	}
	return ans;
}
int main()
{
	scanf("%d %d",&n,&k);
	while(s<n) s*=2;
	for(int i=s;i<s+n;i++)
	{
		scanf("%d",&tree[i]);
	}
	for(int i=s-1;i>0;i--)
	{
		tree[i]=max(tree[i*2],tree[i*2+1]);
	}
	int l=k+1,r=n;
	val=tree[k+s-1];
	while(l<=r)
	{
		if(l>=r) 
		{
			printf("%d",l);
			return 0;
		} 
		int mid=(l+r)/2;
		if(f(l,mid)>=val)
		{
			r=mid;
			continue;
		}
		else
		{
			l=mid+1;
			continue;
		}
	}
}