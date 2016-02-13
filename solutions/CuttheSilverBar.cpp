#include<iostream>
#include<math.h>
using namespace std;

inline int minCut( int n )
{
	return log( n ) / log( 2 );
}

int main()
{
	ios::sync_with_stdio( false );
	int n;
	while ( true )
	{
		cin >> n;
		if ( !n ) return 0;
		cout << "\n"<< minCut( n );
	}
	
	return 1;
}
