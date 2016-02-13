#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<functional>
using namespace std;

string friends( int stamps , vector<int> &v )
{
	stringstream ret;
	sort( v.begin() , v.end() , greater<int>() );
	int i;
	for ( i = 0; i < v.size() && stamps>0 ; ++i )
		stamps -= v[ i ];
	if ( stamps <= 0 )
		ret << i;
	else ret << "impossible";
	return ret.str();
}

int main()
{
	int t , n , stamps;
	cin >> t;
	for ( int i = 0; i < t; ++i )
	{
		cin >> stamps >> n;
		vector<int> v( n );
		for ( int j = 0; j < n; j++ )
			cin >> v[ j ];
		cout << "\nScenario #" << i + 1 << ":\n" << friends( stamps , v ) << endl ;
	}
	return 0;
}