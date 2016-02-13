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
#define MAX 10000
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int scanint()
{
	register int c = gc();
	register int x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	return x;
}
int g[ 250 ][ 250 ];
int source , sink;
int parent[ 250 ];
bool visited[ 250 ];
bool bfs()
{
	rep( i , 0 , 250 )visited[ i ] = false;
	queue<int> q;
	q.push( source );
	parent[ source ] = -1;
	while ( !q.empty() )
	{
		int u = q.front();
		q.pop();
		visited[ u ] = true;
		for ( int v = 1; v <= sink; v++ )
			if ( !visited[ v ] && g[ u ][ v ] > 0 )
			{
			parent[ v ] = u;
			q.push( v );
			}
	}
	return visited[ sink ];
}
int fordFulkerson()
{
	int mflow = 0;
	while ( bfs() )
	{
		int pf = MAX;
		for ( int v = sink; v != source; v = parent[ v ] )
		{
			int u = parent[ v ];
			pf = min( pf , g[ u ][ v ] );
		}
		for ( int v = sink; v != source; v = parent[ v ] )
		{
			int u = parent[ v ];
			g[ u ][ v ] -= pf;
			g[ v ][ u ] += pf;
		}
		mflow += pf;
	}
	return mflow;
}

int main()
{

	int t , n;
	t = SI;
	till( t )
	{
		n = SI;
		memset( g , 0 , sizeof( g ) );
		rep( i , 1 , ( n ) )
		{
			int k = SI;
			till( k )
			{
				int z;
				z = SI;
				if ( i == 1 || z == n )g[ i ][ z ] = 1;
				else g[ i ][ z ] = MAX;
				g[ z ][ i ] = 0;
			}
		}
		source = 1; sink = n;
		printf( "%d\n" , fordFulkerson() );
	}
	return 0;
}