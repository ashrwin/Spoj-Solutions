#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

string tribal( const vector<int> &v )
{
	stringstream ret( "NO" );
	vector<int> hash( 2001 ,0);
	const int n = v.size();
	for ( int i = 0; i < n ; ++i )
	{
		if ( n>1 && ++hash[ v[i] + 1000 ] > n/2 )
		{
			ret.clear();
			ret << "YES " << v[i]; break;
		}
	}
	return ret.str();
}

int main()
{
	int t,n;
	vector<int> v;
	cin >> t;
	while ( t-- )
	{
		scanf( "%d" , &n );
		v = vector<int>( n );
		for ( int i = 0; i < n; ++i )
			scanf( "%d" , &v[ i ] );
		printf("\n%s",tribal( v ).c_str());
		
	}

}