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
#define gc getchar
#define pc putchar
#define MAX 1000010
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
inline void printInt( int &a )
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

char maze[ 1010 ][ 1010 ];
int vis[ 1010 ][ 1010 ];
int n , m;
int trap = 0;
int cc = 0;
void dfs( const int &x , const int &y )
{
	if ( x >= 0 && y >= 0 && x < n&&y < m )
	{
		char d = maze[ x ][ y ];
		vis[ x ][ y ] = cc ;
		int i = x , j = y;
		if ( d == 'N' )--i;
		else if ( d == 'E' )++j;
		else if ( d == 'S' )++i;
		else if ( d == 'W' )--j;
		if ( vis[ i ][ j ] == 0 )
			dfs( i , j );
		else if ( x >= 0 && y >= 0 && x < n&&y < m )
			cc = vis[ i ][ j ];
		vis[ x ][ y ] = cc;
	}
}
int main()
{
	n = SI ; m = SI;
	rep( i , 0 , n )rep( j , 0 , m )cin >> maze[ i ][ j ];
	rep( i , 0 , n )rep( j , 0 , m )
		if ( !vis[ i ][ j ] )
		{
		cc = trap + 1;
		dfs( i , j );
		if ( cc > trap )
			trap++;
		}
	printf( "%d\n" , trap );
	return 0;
}