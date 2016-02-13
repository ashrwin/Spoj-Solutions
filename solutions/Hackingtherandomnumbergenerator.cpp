/**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;


int pairs( vector<int> &v ,const int &k)
{
	int n = v.size();
	int ret = 0;
	sort( v.begin() , v.end() );
	for ( int i = 0; i < v.size(); ++i )
	{
		int tofind = v[ i ] + k;
		if ( binary_search( v.begin() , v.end() , tofind ) )
			ret++;
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio( false );
	int n,k;
	cin >> n >> k;
	vector<int> v( n );
	for ( int i = 0; i < n; ++i )
			cin >> v[ i ];
	cout << "\n" << pairs( v,k );
	return 0;
}

