#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
set<int> friends;
set<int> ret;
vector< vector<int> > fl;
int main()
{
	int n,a;
	cin >> n;
	fl = vector< vector<int> >( n );
	for ( int i = 0; i < n; ++i )
	{
		cin >> a;
		friends.insert( a );
		int k;
		cin >> k;
		fl[ i ] = vector<int>( k );
		for ( int j = 0; j < k; ++j )
			cin >> fl[ i ][ j ];
	}
	for ( int i = 0; i < fl.size(); ++i )
		for ( vector<int>::const_iterator it = fl[ i ].begin() ; it != fl[ i ].end() ; ++it )
			if ( friends.find( *it ) == friends.end() )
				ret.insert( *it );
	cout << "\n" << ret.size();
	return 0;
}