#include <iostream>
#include<numeric>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

string dota( const vector<int> &v , int m , int d )
{
	int ret = 0;
	int k = 0;
	for ( int i = 0; i < v.size(); ++i )
	{
		k = ( v[ i ] / d );
		if ( k*d == v[ i ] ) --k;
		ret += k;
		if ( ret >= m )
			return "YES";
	}
	return "NO";
}

int main()
{
	int t , n , m , d;
	cin >> t;
	while ( t-- )
	{
		cin >> n >> m >> d;
		vector<int> v( n );
		for ( int i = 0; i < n; ++i )
			cin >> v[ i ];
		cout << "\n" << dota( v , m , d );

	}
	return 0;
}
