#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef unsigned long long ull;
map<ull , ull> m;
map<ull , ull>::iterator it;
ull dp( ull n )
{
	if ( (it=m.find( n )) != m.end() )
		return it->second;
	ull sol = max( n , dp( n / 2 ) + dp( n / 3 ) + dp( n / 4 ) );
	m[ n ] = sol;
	return sol;
}

int main()
{
	
	int n;
	for ( int i = 0; i < 12; i++ )
		m[ i ] = i;
	while ( cin >> n )
		cout << "\n" << dp( n );
	return 0;
}