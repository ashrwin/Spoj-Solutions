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
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

template<class node>
class SegmentTree
{
	vector<node> t;
	node id;
	int n;
	int u , v;
	node rQ( int root , int tleft , int tright )
	{
		if ( u <= tleft && tright <= v )
			return t[ root ];
		int lchild = ( root << 1 ) , rchild = lchild + 1;
		int mid = ( tleft + tright ) >> 1;
		node l = id , r = id;
		if ( u < mid )
			l = rQ( lchild , tleft , mid );
		if ( v>mid )
			r = rQ( rchild , mid , tright );
		node res;
		res.merge( l , r );
		return res;
	}
public:
	SegmentTree( const vi &v , const node &id )
	{
		const int k = sz( v );
		this->id = id;
		n = (int)ceil( log2( k ) );
		t = vector<node>( 1 << ( n + 1 ),node() );
		for ( int i = 0; i < k; ++i )
		{
			t[ ( 1 << n ) + i ].lv = t[ ( 1 << n ) + i ].rv = v[ i ];
			t[ ( 1 << n ) + i ].lfc = t[ ( 1 << n ) + i ].rfc = t[ ( 1 << n ) + i ].mf = 1;

		}
		for ( int i = ( 1 << n ) - 1; i; --i )
			t[ i ].merge( t[ ( i << 1 ) ] , t[ ( i << 1 ) + 1 ] );
	}
	node rangeQuery( int u , int v )
	{
		this->u = ( 1 << n ) + u - 1;
		this->v = ( 1 << n ) + v;
		return rQ( 1 , 1 << n , 1 << ( n + 1 ) );
	}

};


struct node
{
	int rv , lv , rfc , lfc , mf;
	node()
	{
		rv = lv = rfc = lfc = mf = 0;
	}

	void merge( const node &left , const node &right )
	{
		int t = 0;
		if ( left.rv == right.lv )
			t = left.rfc + right.lfc;
		lfc = max( left.lfc , ( ( right.lv == left.lv ) ? ( right.lfc + left.lfc ) : 0 ) );
		rfc = max( right.rfc , ( ( right.rv == left.rv ) ? ( right.rfc + left.rfc ) : 0 ) );
		lv = left.lv;
		rv = right.rv;
		mf = max( left.mf , max( right.mf , t ) );
	}
};

inline void scanInt( int &x )
{
	register int c = gc();
	x = 0;
	int neg = 0;
	for ( ; ( ( c<48 || c>57 ) && c != '-' ); c = gc() );
	if ( c == '-' ) { neg = 1; c = gc(); }
	for ( ; c>47 && c<58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	if ( neg ) x = -x;
}
int main()
{
	int n , q;
	while ( true )
	{
		sf( n );
		if ( !n ) return 0;
		sf( q );
		vi v( n );
		rep( i , 0 , n )sf( v[ i ] );
		SegmentTree<node> s( v , node() );
		till( q )
		{
			int a , b;
			sf( a ); sf( b );
		printf( "\n%d" , s.rangeQuery( a , b ).mf );
		}
	}
	return 0;
}