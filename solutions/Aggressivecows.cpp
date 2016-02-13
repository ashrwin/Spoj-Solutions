#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
typedef long long ll;


bool pred( ll x ,vector<ll> v ,ll c)
{
	ll cows = 1 , pos = v[ 0 ];
	for ( ll i = 1; i<v.size() ; i++ )
	{
		if ( v[ i ] - pos >=x )
		{
			pos = v[ i ];
			cows++;
			if ( cows == c )
				return true;
		}
	}
	return false;
}


ll bintest( ll c , vector<ll> &v )
{
	sort( v.begin() , v.end() );
	ll lo = 0 , hi = v[ v.size() - 1 ];
	while (  lo<hi )
	{
		ll x = ( lo + hi ) / 2;
		if ( pred( x , v , c ) )
			lo = x+1;
		else hi = x ;
	}
	return lo - 1;

}


int main()
{
	ll t , n , c;
	cin >> t;
	for ( int i = 0; i < t; ++i )
	{
		cin >> n >> c;
		vector<ll> v( n );
		for ( ll j = 0; j < n; ++j )
			 cin >> v[ j ];
		cout<<"\n"<<bintest( c ,  v );
	}
	

	return 0;
}
