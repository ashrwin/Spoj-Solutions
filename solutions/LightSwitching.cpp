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
#define sf(a) scanf("%d",&a) 
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
		t[ root ].split( t[ lchild ] , t[ rchild ] );
		node l = id , r = id;
		if ( u < mid )
			l = rQ( lchild , tleft , mid );
		if ( v>mid )
			r = rQ( rchild , mid , tright );
		node res;
		res.merge( l , r );
		return res;
	}
	void rU( int root , int tleft , int tright )
	{
		if ( u <= tleft && tright <= v )
			return t[ root ].update();
		int lchild = ( root << 1 ) , rchild = lchild + 1;
		int mid = ( tleft + tright ) >> 1;
		t[ root ].split( t[ lchild ] , t[ rchild ] );
		node l = id , r = id;
		if ( u < mid )
			rU( lchild , tleft , mid );
		if ( v>mid )
			rU( rchild , mid , tright );
		t[ root ].merge( t[ lchild ] , t[ rchild ] );
	}
public:
	SegmentTree( const int k , const node &id )
	{
		this->id = id;
		n = (int)ceil( log2( k ) );
		t = vector<node>( 1 << ( n + 1 ) , node( 0 ) );
		for ( int i = 0; i < k; ++i )
			t[ ( 1 << n ) + i ].off = 1;
		for ( int i = ( 1 << n ) - 1; i; --i )
			t[ i ].merge( t[ ( i << 1 ) ] , t[ ( i << 1 ) + 1 ] );
	}
	node rangeQuery( int u , int v )
	{
		this->u = ( 1 << n ) + u - 1;
		this->v = ( 1 << n ) + v;
		return rQ( 1 , 1 << n , 1 << ( n + 1 ) );
	}
	void rangeUpdate( int u , int v )
	{
		this->u = ( 1 << n ) + u - 1;
		this->v = ( 1 << n ) + v ;
		rU( 1 , 1 << n , 1 << ( n + 1 ) );
	}
};


struct node
{
	int flip;
	int off , on;
	node( int z = 0 )
	{
		flip = on = off = 0;
		off = z;
	}

	void merge( const node &left , const node &right )
	{
		on = left.on + right.on;
		off = left.off + right.off;
		flip = 0;
	}
	void split( node &left , node &right )
	{
		if ( flip )
		{
			left.flip ^= 1;
			right.flip ^= 1;
			swap( left.on , left.off );
			swap( right.on , right.off );
		}
		flip = 0;
	}

	void update()
	{
		flip ^= 1;
		swap( on , off );
	}
};

inline void scanInt( int &x )
{
	register int c = gc();
	x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
}

int main()
{
	int n , m;
	scanInt( n );
	scanInt( m );
	SegmentTree<node> s( n , node() );
	till( m )
	{
		int a , b , c;
		scanInt( a ); scanInt( b ); scanInt( c );
		if ( !a ) s.rangeUpdate( b , c );
		else printf( "\n%d" , s.rangeQuery( b , c ).on );
	}
	return 0;
}