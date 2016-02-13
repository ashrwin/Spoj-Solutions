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

	void singleUpdate( node &x , int nval )
	{
		x.ladd += nval;
		x.sum += nval*x.nl;
	}

	void rangeUpdate( int root , int lleaf , int rleaf,int nval )
	{
		if ( u <= lleaf && rleaf <= v )
			return singleUpdate(t[ root ],nval);
		int mid = lleaf + ( rleaf - lleaf ) / 2;
		int lc = 2 * root , rc = lc + 1;
		t[ root ].split( t[ lc ] , t[ rc ] );
		if ( u < mid )
			rangeUpdate( lc , lleaf , mid,nval );
		if ( v>mid )
			rangeUpdate( rc , mid , rleaf,nval );
		t[ root ].merge( t[ lc ] , t[ rc ] );
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
	void rangeUpdate( int u , int v , int xx )
	{
		this->u = ( 1 << n ) + u;
		this->v = ( 1 << n ) + v + 1;
		rangeUpdate( 1 , 1 << n , 1 << ( n + 1 ) ,xx);
	}
	
	node rangeQuery( int u , int v )
	{
		this->u = (1<<n)+u;
		this->v = (1<<n)+v + 1;
		return rangeQuery( 1 , 1<<n ,  1<<(n+1) );
		
	}
	
	
};

struct node
{
	ll sum;
	ll ladd , nl;
	node(int k=0)
	{
		nl =k; ladd = sum = 0;
	}
	void merge( const node &a , const node &b )
	{
		sum = a.sum + b.sum;
		nl = a.nl + b.nl;
	}
	void split( node &a , node &b )
	{
		a.sum += ladd*a.nl;
		b.sum += ladd*b.nl;
		a.ladd += ladd;
		b.ladd += ladd;
		ladd = 0;
	
	}
};



int main()
{
	ios::sync_with_stdio( false );
	int n , t , c;
	cin >> t;
	while ( t-- )
	{
		cin >> n >> c;
		SegmentTree<node> s;
		vector<node> v( n , node( 1 ) );
		s.init( v , node() );
		for ( int i = 0; i < c; ++i )
		{
			int p , q , r ,z;
			cin >> p >> q >> r;
			if ( !p )
			{
				cin >> z;
				s.rangeUpdate(q-1,r-1,z);
			}
			else cout << "\n" << s.rangeQuery( q - 1 , r - 1 ).sum;
		}

	}
	return 0;

}


