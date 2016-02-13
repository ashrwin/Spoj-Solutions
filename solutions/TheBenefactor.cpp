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
inline int scanint()
{
	register int c = gc();
	register int x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	return x;
}
vvii g;
vector<bool> vis;
ii dfs( int u )
{
	vis[ u ] = true;
	ii ret = mp( 0 , u );
	for ( vii::iterator it = g[ u ].begin(); it != g[ u ].end(); ++it )
	{
		int v = it->first , cost = it->second;
		if ( !vis[ v ] )
		{
			ii ad = dfs( v );
			ad.first += cost;
			ret = max( ret ,ad );
		}
	}
	return ret;
}


int main()
{
	int t = SI;
	till( t )
	{
		int n = SI + 1;
		g = vvii( n );
		vis = vector<bool>( n , false );
		rep( i , 0 , n - 2 )
		{
			int u = SI , v = SI , cost = SI;
			g[ u ].push_back( mp( v , cost ) );
			g[ v ].push_back( mp( u , cost ) );
		}
		ii leaf = dfs( 1 );
		rep( i , 0 , n )vis[ i ] = false;
		printf( "%d\n" , dfs( leaf.second ).first );
	}
	return 0;
}