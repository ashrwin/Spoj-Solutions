#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<functional>
#include<queue>
using namespace std;

int getInput( int n )
{
	int m = -100 , c;
	for ( int i = 0; i < n; i++ )
	{
		cin >> c;
		m = max( m , c );
	}
	return m;
}

int main()
{
	int t , ng , nm , ngmax , nmmax;
	cin >> t;
	for ( int i = 0; i < t; ++i )
	{
		cin >> ng >> nm;
		ngmax = getInput( ng );
		nmmax = getInput( nm );
		if ( ngmax >= nmmax )
			cout << "\nGodzilla";
		else cout << "\nMechaGodzilla";
	}
	return 0;
}