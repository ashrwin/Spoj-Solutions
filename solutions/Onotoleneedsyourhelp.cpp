#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
typedef unsigned long long ull;
using namespace std;
int main()
{
	int n;
	cin >> n;
	ull x;
	ull ans = 0;
	for ( int i = 0; i < n; ++i )
	{
		scanf("%llu",&x);
		ans = ans^x;
	}
	printf("\n%d" ,ans);
	return 0;
}