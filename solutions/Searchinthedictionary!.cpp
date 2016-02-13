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
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MAX 1000010
#define pi 3.14159265358979323846264338327950
#define sqr(x) ((x)*(x))
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

struct trie
{
	int pos;
	trie *children[ 26 ];
	trie( int c = -1 )
	{
		this->pos = c;
		rep( i , 0 , 26 )children[ i ] = NULL;
	}
};

class Trie
{
	trie *root;
	int pos;
	string s;
	trie* insert( trie *r , int l )
	{
		if ( r == NULL )
			r = new trie();
		if ( l == sz( s ) )
		{
			r->pos = pos; return r ;
		}
		int x = s[ l ] - 'a';
		r->children[ x ] = insert( r->children[ x ] , l + 1 );
		return r;
	}
	trie *getNode( trie *r , int l )
	{
		if ( r == NULL )return NULL;
		if ( l == sz( s ) )return r;
		return getNode( r->children[ s[ l ] - 'a' ] , l + 1 );
	}

	void dfs( trie *r , vi &v )
	{
		if ( r == NULL )return;
		rep( i , 0 , 26 )
			if ( r->children[ i ] != NULL )
			{
			if ( r->children[ i ]->pos != -1 )
				v.push_back( r->children[ i ]->pos );
			dfs( r->children[ i ] , v );
			}
	}

public:
	Trie()
	{
		root = NULL;
	}
	void put( const string &k , int p )
	{
		s = k;
		pos = p;
		root = insert( root , 0 );
	}
	void prefixes( const string &k , vi &v )
	{
		s = k;
		trie* tr = getNode( root , 0 );
		if ( tr == NULL )return;
		dfs( tr , v );
	}

};

vector<string> ks;
char buff[ 500 ];
int main()
{
	Trie tr;
	int n = SI;
	string s;
	ks = vector<string>( n );
	rep( i , 0 , n ){
		scanf( "%s" , buff );
		ks[ i ] = string( buff );
		tr.put( ks[ i ] , i );
	}
	int k = SI;
	vi v;
	rep( Z , 1 , k + 1 )
	{
		scanf( "%s" , buff );
		s = string( buff );
		v.clear();
		tr.prefixes( s , v );
		printf( "Case #%d:\n" , Z );
		rep( i , 0 , sz( v ) )
			printf( "%s\n" , ks[ v[ i ] ].c_str() );
		if ( !sz( v ) )printf( "No match.\n" );
	}
	return 0;
}