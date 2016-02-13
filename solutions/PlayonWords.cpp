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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include<cstdio>
#include<cstring>
#include <ctime>
#include<unordered_set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar//_unlocked
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
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int scanint()
{
	register int c = gc();
	register int x = 0;
	int neg = 0;
	for ( ; ( ( c < 48 || c>57 ) && c != '-' ); c = gc() );
	if ( c == '-' ) { neg = 1; c = gc(); }
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	if ( neg ) x = -x;
	return x;
}

int indeg[ 26 ] , outdeg[ 26 ];
char word[ 5000 ];
bool g[ 26 ][ 26 ];
bool vis[ 26 ];

void dfs( int u )
{
	vis[ u ] = true;
	rep( i , 0 , 26 )
	{
		if ( g[ u ][ i ] )
			if ( !vis[ i ] )
				dfs( i );
	}
}

int main()
{
	int t = SI;
	int n;
	till( t )
	{
		fill( indeg , indeg + 26 , 0 );
		fill( outdeg , outdeg + 26 , 0 );
		fill( vis , vis + 26 , false );
		memset( g , 0 , sizeof( g ) );
		n = SI;
		string s;
		rep( i , 0 , n )
		{
			scanf( "%s" , word );
			outdeg[ word[ 0 ] - 'a' ]++;
			indeg[ word[ strlen( word ) - 1 ] - 'a' ]++;
			g[ word[ 0 ] - 'a' ][ word[ strlen( word ) - 1 ] - 'a' ] = true;
		}
		int ret = 0;
		int inset = -1 , oset = -1;
		bool flag = true;
		rep( i , 0 , 26 )
		{
			if ( indeg[ i ] != outdeg[ i ] )
			{
				if ( indeg[ i ] == outdeg[ i ] + 1 )
					oset = i , ++ret;
				else if ( indeg[ i ] + 1 == outdeg[ i ] )
						inset = i , ++ret;
				
				else flag = false;
			}
			if ( !flag )break;
		}

		if ( flag && ( ret <= 2 ) )
		{
			if ( inset == -1 )
				rep( i , 0 , 26 )
				if ( outdeg[ i ] ){ inset = i; break; }
			dfs( inset );
			rep( i , 0 , 26 )
				if ( ( indeg[ i ] || outdeg[ i ] ) && !vis[ i ] )
					flag = 0;
			if ( flag )
				printf( "Ordering is possible." );
			else printf( "The door cannot be opened." );
		}
		else printf( "The door cannot be opened." );
		printf( "\n" );
	}

	return 0;
}