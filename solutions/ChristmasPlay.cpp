#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

ll party( const vector<ll> &v , ll k )
{
	ll ret = v[k-1]-v[0];
	for ( int i = 1; i+k-1 < v.size(); ++i )
	{
		ret = min( ret , v[ i + k - 1 ] - v[ i ] );
	}
	return ret;
}

int main()
{
	int t;
	ll n , k;
	cin >> t;
	while (t-- )
	{
		cin >> n >> k;
		vector<ll> v( n );
		for ( int i = 0; i < n; ++i )
			cin >> v[ i ];
		sort( v.begin() , v.end() );
		cout << "\n" << (ll)party( v , k );
	}
	

	return 0;
}
