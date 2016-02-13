#include <iostream>
#include <cstdio>
using namespace std;
unsigned int a[300009];
int main()
{
	unsigned int p,q,i,j,n,m,b,c,d;
	unsigned int ans,s;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	p=1;
	q=1;
	s=a[1];
	ans=0;
	while(q<=n)
	{
		if(s<=m)
		{
			ans=max(ans,s);
			q++;
			s=s+a[q];
		}
		else
		{
			p++;
			s=s-a[p-1];
		}
	}
	printf("%d",ans);
	return 0;
	}