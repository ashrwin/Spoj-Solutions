/**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;

int main()
{
	int t , n;
	scanf( "%d" , &t );
	ll k , min , sum;
	for ( int T = 1; T <= t; ++T )
	{
		scanf( "%d" , &n );
		sum = 0;
		min = 0;
		for ( int i = 0; i < n; ++i )
		{
			scanf( "%lld" , &k );
			sum += k;
			min = std::min( min , sum );
		}
		printf( "Scenario #%d: %lld\n" , T , -1 * min + 1 );
	}
	return 0;
}

