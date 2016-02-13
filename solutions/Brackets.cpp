/**/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;

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
		int lc = 2 * root , rc = lc | 1;
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

	void singleUpdate( node &n )
	{

		n.balanced = false;
		n.open = n.close = 0;
		char x;
		if ( n.first == '(' )
			x = ')';
		else x = '(';
		n.first = n.last = x;
		if ( x == '(' ) n.open = 1;
		else n.close = 1;
	}

	void flip( node& n ){
		n.min *= -1;
		n.sum = n.min;
	}
	void rangeUpdate( int root , int lleaf , int rleaf )
	{
		if ( u <= lleaf && rleaf <= v )
		{
			flip( t[ root ] );
			return ;
		}
		int mid = lleaf + ( rleaf - lleaf ) / 2;
		int lc = 2 * root , rc = lc + 1;
		t[ root ].split( t[ lc ] , t[ rc ] );
		if ( u < mid )
			rangeUpdate( lc , lleaf , mid );
		if ( v>mid )
			rangeUpdate( rc , mid , rleaf );
		t[ root ].merge( t[ lc ] , t[ rc ] );
	}

	
	
	


public:
	void init( const vector<node> & v , node id )
	{
		this->id = id;
		n = int( ceil( log2( (int)v.size() ) ) );
		int l = ( 1 << n ) , r = ( 1 << ( n + 1 ) );
		t = vector<node>( r );
		for ( int i = 0; i < (int)v.size(); ++i )
			t[ l + i ] = v[ i ];
		for ( int i = (int)v.size() + l; i < r; ++i )
			t[ i ] = id;
		for ( int i = l - 1; i; --i )
			t[ i ].merge( t[ i * 2 ] , t[ 2 * i + 1 ] );
	}
	SegmentTree(){}
	void rangeUpdate( int u , int v )
	{

		this->u = ( 1 << n ) + u;
		this->v = ( 1 << n ) + v + 1;
		rangeUpdate( 1 , 1 << n , 1 << ( n + 1 ) );
	}

	node rangeQuery( int u , int v )
	{
		this->u = ( 1 << n ) + u;
		this->v = ( 1 << n ) + v + 1;
		return rangeQuery( 1 , 1 << n , 1 << ( n + 1 ) );

	}
	

};

struct node
{
	int min , sum;
	void merge( node& l , node& r ){
		sum = l.sum + r.sum;
		min = std::min( l.min , l.sum + r.min );
	}

	void split( node& l , node& r )
	{

	}
	node()
	{
		min = sum = 0;
	}


};



int main()
{
	ios::sync_with_stdio( false );
	int n , c;
	for ( int Z = 1; Z <= 10; ++Z )
	{
		cin >> n;
		SegmentTree<node> s;
		vector<node> v( n );
		for ( int i = 0; i < n; ++i )
		{
			char x;
			cin >> x;
			if ( x == '(' )
				v[ i ].min = v[ i ].sum = 1;
			else v[ i ].min = v[ i ].sum = -1;
		}
		s.init( v , node() );
		cin >> c;
		cout << "\nTest "<<Z<<":";
		
		while ( c-- )
		{
			int p;
			cin >> p;
			if ( !p ){
				node t = s.rangeQuery( 0 , n - 1 );
				if ( t.min==0 && t.sum==0 ) cout << "\nYES";
				else cout << "\nNO ";
			}
			else {
				s.rangeUpdate( p - 1 , p - 1 );
			}
		}
	}
	return 0;

}


