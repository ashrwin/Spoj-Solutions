#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include<fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<assert.h>
//#include<unordered_map>
//#include<tr1/unordered_set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar_unlocked
#define pc putchar
#define MAX 10000
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
inline int scanint()
{
	register int c = gc();
	register int x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	return x;
}
inline void printInt( int a )
{
	char s[ 11 ];
	int t = -1;
	do{
		s[ ++t ] = a % 10 + '0';
		a /= 10;
	} while ( a > 0 );
	while ( t >= 0 )pc( s[ t-- ] );
	pc( '\n' );
}
int dp[ 50 ][ 50 ];

void func( int n , int m , int x , int y )
{
	int ret = dp[ x ][ y ];
	dp[ x ][ y ] = 0;
	for ( int j = y + 1; j <= m; ++j )
		dp[ x ][ j ] = dp[ x ][ j - 1 ] + dp[ x ][ j ];
	for ( int i = x + 1 ; i <= n; ++i )
		for ( int j = y; j <= m; ++j )
		{
		int f = dp[ i - 1 ][ j ] + dp[ i ][ j ];
		int s = ( 1 << 30 );
		if ( j > y )s = dp[ i ][ j - 1 ] + dp[ i ][ j ];
		dp[ i ][ j ] = min( f , s );
		}
	dp[ n ][ n ] = ret - ( dp[ n ][ m ] );
	( dp[ n ][ m ] >= 0 ) ? printf( "Y %d\n" , dp[ n ][ m ] ) : printf( "N\n" );
}


int main()
{
	int n = SI , m = SI , x = SI , y = SI;
	rep( i , 1 , n + 1 )rep( j , 1 , m + 1 )dp[ i ][ j ] = SI;
	func( n , m , x , y ) ;
	return 0;
}