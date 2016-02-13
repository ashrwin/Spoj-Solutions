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
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf scanInt 
#define gc getchar_unlocked
#define MAX 10000000
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
vector< priority_queue<int> > g(105);
bool vis[ 105 ] = { false };
stack<int> ans;
int n , m;
inline void scanInt( int &x )
{
	register int c = gc();
	x = 0;
	for ( ; ( c<48 || c>57 ); c = gc() );
	for ( ; c>47 && c<58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
}
void dfs( int u )
{
	vis[ u ] = true;
	while ( !g[ u ].empty() )
	{
		int v = g[ u ].top();
		g[ u ].pop();
		if ( !vis[ v ] )
			dfs( v );
	}
	ans.push( u );
}


inline void dfs()
{
	for ( int i = n; i > 0; --i )
		if ( !vis[ i ] )
			dfs( i );
}

int main()
{

	scanInt( n ); scanInt( m );
	rep( i , 0 , m )
	{
		int v , u , k;
		scanInt( v ); scanInt( k );
		rep( j , 0 , k )
		{
			scanInt( u );
			g[ u ].push( v );
		}
	}
	dfs();
	while ( !ans.empty() )
	{
		printf( "%d " , ans.top() );
		ans.pop();
	}
	printf( "\n" );
	return 0;
}