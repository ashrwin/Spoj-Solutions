#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;

string ambi( const vector<int> &v )
{
	for ( int i = 1; i < (int)v.size(); i++ )
		if ( v[ v[ i ] ] != i )
			return "not ambiguous";
	return "ambiguous";
}
int main()
{
	int val , n;
	while ( true )
	{
		cin >> n;
		if ( !n ) return 0;
		vector<int>v( n + 1 );
		for ( int j = 0; j < n; j++ )
		{
			cin >> val;
			v[ j + 1 ] = val;
		}
		cout << "\n" << ambi( v );
	}
	return 0;
}