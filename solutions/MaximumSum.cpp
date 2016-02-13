#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef long long ll;

template <class node>
class SegmentTree
{
	int n;
	int u , v;
	node id;
	vector<node> t;

	node rmq( int pos , int ll , int rl )
	{
		if ( u <= ll && rl <= v )
			return t[ pos ];
		node l = id , r = l;
		int lc = 2 * pos , rc = lc + 1;
		int mid = ll + ( rl - ll ) / 2;
		if ( u < mid )	l = rmq( lc , ll , mid );
		if ( v > mid )r = rmq( rc , mid , rl );
		node k = id;
		k.merge( l , r );
		return k;
	}

public:
	void init(vector<node> &v , node &id)
	{
		this->id = id;
		int k = v.size();
		n = int(ceil(log2( k )));
		int lc = 1 << n;
		int rc = lc << 1;
		t = vector<node>( rc ,id);
		for ( int i = 0; i <(int) v.size(); ++i )
			t[ lc+i ] = v[ i ];
		for ( int i = lc - 1; i; --i )
			t[ i ].merge( t[ 2 * i ] , t[ 2 * i + 1 ] );
	}

	node rmq( int u , int v )
	{
		this->u = ( 1 << n )+u;
		this->v = ( 1 << n ) + v + 1;
		return rmq( 1 , 1 << n , 1 << ( n + 1 ) );
	}

	void update( int pos ,ll val)
	{
		int tpos = ( 1 << n ) + pos;
		t[ tpos ].m1 = val;
		int p = tpos >> 1;
		while ( p )
		{
			t[ p ].merge( t[ p * 2 ] , t[ p * 2 + 1 ] );
			p >>= 1;
		}
	}
};

struct node
{
	ll m1,m2;
	node()
	{
		m1=m2 = 0;
	}
	void merge( const node &a , const node &b )
	{
		if ( a.m1 < b.m2 )
		{
			m1 = max( b.m1 , b.m2 );
			m2 = min( b.m1 , b.m2 );
		}
		else if ( a.m2 > b.m1 )
		{
			m1 = max( a.m1 , a.m2 );
			m2 = min( a.m1 , a.m2 );
		}
		else
		{
			ll x = max( a.m2 , b.m1 );
			ll y = max( b.m2 , a.m1 );
			m1 = max( x , y );
			m2 = min( x , y );
		}
	}

};









int main()
{
	ios::sync_with_stdio( false );
	int  n;
	cin >> n;
	vector<node> v( n );
	for ( int i = 0; i < n; ++i )
	{
		int x;
		cin >> x;
		v[ i ].m1 = x;
	}
	SegmentTree<node> s;
	node t;
	t.m1 = t.m2 = 0;
	s.init( v , t );
	int m , b; 
	ll c;
	char a;
	cin >> m;
	while ( m-- )
	{
		cin >>a>> b >> c;
		if ( a == 'Q' )
		{
			node t = s.rmq( b - 1 ,(int) c - 1 );
			cout << "\n" << t.m1 + t.m2;
		}
		else if(a=='U') s.update( b - 1 , c );
	}
}
