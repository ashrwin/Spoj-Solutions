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
#define sf(a) scanint(a) 
#define gc getchar_unlocked
#define MAX 10000000
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

void scanint( int &x )
{
	register int c = gc();
	x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
}

struct node
{
	int rem;
	char c;
	node *parent;
	node( char x = '!' )
	{
		c = x; rem = 0;
	}
};
//node parent[ 40000000 ];
node track[ 4000000 ];
string path( node *p )
{
	//cout << "\n PP " << p;

	stringstream ret;
	for ( node *i = p; i != NULL ; i = i->parent )
		ret << i->c;
	string s = ret.str();
	reverse( s.begin() , s.end() );
	return s;
}

node bfs( int x )
{
	node s;
	s.rem = 1;
	s.c = '1';
	queue<node> q;
	s.parent = NULL;
	q.push( s );
	int p = 1;

	int t = 0;
	while ( !q.empty() )
	{
		node cur = q.front();
		track[ t++ ] = cur;

		q.pop();
		node v1 , v2;
		v1.rem = ( ( cur.rem * 10 ) % x ) % x;
		v1.c = '0';
		v2.rem = ( v1.rem + 1 ) % x ;
		v2.c = '1';
		v1.parent = &( track[ t - 1 ] );
		v2.parent = &( track[ t - 1 ] );
		if ( v1.rem == 0 )return v1;
		if ( v2.rem == 0 ) return v2;
		q.push( v1 );
		q.push( v2 );

	}
}

int main()
{
	int t;
	sf( t );
	till( t )
	{
		int m;
		sf( m );
		if ( m == 1 )printf( "\n1" );
		else printf( "\n%s" , path( &bfs( m ) ).c_str());
		
	}
	return 0;
}


