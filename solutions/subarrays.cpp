/**/#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long int ll;

template <typename node>
class SegmentTree
{
	vector<node> t;
	node id;
	int n;
	int u , v;
	node rangeQuery( int root , int lleaf , int rleaf )
	{
		if ( u <= lleaf && rleaf <= v )
			return t[ root ];
		int mid = lleaf + ( rleaf - lleaf ) / 2;
		int lc = 2 * root,rc=lc|1;
		t[ root ].split( t[ lc ] , t[ rc ] );
		node a = id , b = a;
		if ( u < mid )
			a = rangeQuery( lc , lleaf , mid );
		if ( v>mid )
			b = rangeQuery( rc , mid , rleaf );
		node k;
		k.merge( a , b );
		return k;
	}
public:
	void init( const vector<node> & v , node id )
	{
		this->id = id;
		n = int( ceil( log2( (int)v.size() ) ) );
		int l = ( 1 << n ) , r = ( 1 << ( n + 1 ) );
		t = vector<node>( r );
		for ( int i = 0; i <(int) v.size(); ++i )
			t[ l+i ] = v[ i ];
		for ( int i = (int)v.size() + l; i < r; ++i )
			t[ i ] = id;
		for ( int i = l - 1; i; --i )
			t[ i ].merge( t[ i *2 ] , t[ 2*i + 1 ]);
	}
	SegmentTree(){}
	node rangeQuery( int u , int v )
	{
		this->u = (1<<n)+u;
		this->v = (1<<n)+v + 1;
		return rangeQuery( 1 , 1<<n ,  1<<(n+1) );
		
	}
	
};

struct node
{
	int val;
	void merge( const node &a , const node &b )
	{
		val = max( a.val , b.val );
	}
	void split( node &a , node &b ){}
};



int main()
{
	node identity;
	identity.val = -1;
	SegmentTree<node> s;
	int n , k;
	scanf( "%d" , &n );
	vector<node> v( n );
	for ( int i = 0; i < n; ++i )
	{
		int x;
		scanf( "%d" , &x );
		v[ i ].val = x;
	}
	scanf( "%d" , &k );
	s.init( v , identity );
	for ( int i = 0; i <= n - k; ++i )
		printf( "%d " , s.rangeQuery( i , i + k-1 ).val );
	return 0;
}


