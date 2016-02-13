#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
typedef unsigned long long int ll;

class Matrix
{
	ll a[ 2 ][ 2 ];
	public:
	ll getN()
	{
		return a[ 0 ][ 1 ]%1000000007;
	}
	Matrix( ll p = 1 , ll q = 1 , ll r = 1 , ll s = 0 )
	{
		a[ 0 ][ 0 ] = p;
		a[ 0 ][ 1 ] = q;
		a[ 1 ][ 0 ] = r;
		a[ 1 ][ 1 ] = s;
	}

	Matrix operator *( const Matrix &b )
	{
		ll p = ( a[ 0 ][ 0 ] * b.a[ 0 ][ 0 ] ) + ( a[ 0 ][ 1 ] * b.a[ 1 ][ 0 ] ) ;
		ll q = ( a[ 0 ][ 0 ] * b.a[ 0 ][ 1 ] ) + ( a[ 0 ][ 1 ] * b.a[ 1 ][ 1 ] ) ;
		ll r = ( a[ 1 ][ 0 ] * b.a[ 0 ][ 0 ] ) + ( a[ 1 ][ 1 ] * b.a[ 1 ][ 0 ] ) ;
		ll s = ( a[ 1 ][ 0 ] * b.a[ 0 ][ 1 ] ) + ( a[ 1 ][ 1 ] * b.a[ 1 ][ 1 ] ) ;
		return Matrix( p , q , r , s );
	}
	Matrix operator %( const ll &n )
	{
		ll p = a[0][0] % 1000000007;
		ll q = a[0][1] % 1000000007;
		ll r = a[1][0] % 1000000007;
		ll s = a[1][1] % 1000000007;
		return Matrix( p , q , r , s );
	}

};

Matrix modPower( Matrix base , ll exp )
{
	Matrix ret( 1 , 0 , 0 , 1 );
	while ( exp > 0 )
	{
		if ( exp % 2 )
			ret = ( ret* base ) % 1000000007;
		exp >>= 1;
		base = ( base*base ) % 1000000007;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio( false );
	ll t , n , m;
	cin >> t;
	while ( t-- )
	{
		Matrix a,b ;
		cin >> n >> m;
		a = modPower( a , n+1 );
		b= modPower( b , m + 2 );
		cout << "\n" << ( b.getN() - a.getN()+1000000007 ) % 1000000007;
	}
	return 0;
}
