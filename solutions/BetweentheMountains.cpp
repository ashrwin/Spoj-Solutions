#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
#include<stdlib.h>
#include<limits>
using namespace std;
typedef long long ull;

ull alt( const vector<ull> & x , const vector<ull> & y )
{
	ull ret =100000000;
	for ( int i = 0; i < x.size(); ++i )
		for ( int j = 0; j < y.size(); j++ )
			ret = min( ret , abs( x[ i ] - y[ j ] ) );
	return ret;
}


int main()
{
	int t,a,b;
	cin >> t;
	while ( t-- )
	{
		cin >> a;
		vector<ull> m1( a );
		for ( int i = 0 ; i < a; ++i )
			cin >> m1[ i ];

		cin >> b;
		vector<ull> m2( b);
		for ( int i = 0 ; i < b; ++i )
			cin >> m2[ i ];

		cout << "\n" << alt( m1 , m2 );

	}
	return 0;
}

