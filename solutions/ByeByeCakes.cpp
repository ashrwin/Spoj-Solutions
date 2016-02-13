#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int a[ 5 ] , b[ 5 ];
int main()
{
	ios::sync_with_stdio( false );
	while ( true )
	{
		for ( int i = 0; i < 4; ++i )
			cin >> a[ i ];
		if ( a[ 0 ] == -1 ) return 0;
		for ( int i = 0; i < 4; ++i )
			cin >> b[ i ];
		int r = 0;
		for ( int i = 0; i < 4; ++i )
			r = max( r*1.0 , ceil(a[ i ]*1.0 / b[ i ]) );
		for ( int i = 0; i < 4; ++i )
			cout << max(( r*b[ i ] ) - a[ i ],0)<<" ";
		cout << "\n";
	}
	return 0;
}
