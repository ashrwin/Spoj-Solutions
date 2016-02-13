#include<iostream>
using namespace std;
long long a[ 500005 ];
bool m[ 5000000 ] = { false };
int main()
{
	ios::sync_with_stdio( false );
	a[ 0 ] = 0;
	for ( int i = 1; i < 500001; ++i )
	{
		a[ i ] = a[ i - 1 ] - i;
		if ( a[ i ] <= 0 ||  m[ a[ i ] ] )
			a[ i ] += 2 * i;
		m[a[ i ]]=true;
	}
	int n;
	while ( true )
	{
		cin >> n;
		if ( n == -1 ) return 0;
		cout << "\n" << a[ n ];
	}
	return 1;
}