#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
#define mp make_pair
#define pb push_back
#define MAX 35000
using namespace std;
typedef pair<int , int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;
ull dp[ 65 ][ 10 ];

void find( int n )
{
	for ( int i = 0; i < 10; ++i )
		dp[ 1 ][ i ] = 10-i;
	for ( int i = 2; i <= n; ++i )
	{
		dp[ i ][ 9 ] = 1;
		for ( int j = 8; j >= 0; --j )
			dp[ i ][ j ] = dp[ i - 1 ][ j ]+ dp[i][j+1] ;
	}
	
}

int main()
{
	find( 64 );
	ios::sync_with_stdio( false );
	int t,a,b;
	cin >> t;
	while ( t-- )
	{
		cin >> a>>b;
		cout << "\n" << a << " " << dp[ b ][ 0 ];
	}
	
}