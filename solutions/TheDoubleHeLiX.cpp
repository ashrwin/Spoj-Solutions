#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int helix( const vector<int> &x , const vector<int> &y , const vector<int> &ip )
{
	int n = ip.size();
	vector<int> sa( n + 1,0 ) , sb( n + 1,0 );
	for ( int i = 0 , j = 0; i < x.size(); ++i )
	{	
		sa[ j ] += x[ i ];
		if (  j<ip.size() && ip[ j ] == x[ i ] )
		{
			j++;

		}
	}
	for ( int i = 0 , j = 0; i < y.size(); ++i )
	{
		sb[ j ] += y[ i ];
		if ( j< ip.size() && ip[ j ] == y[ i ] )
			j++;
	}
	int ret = 0;
	for ( int i = 0; i < sa.size(); ++i )
	{
		ret += max( sa[ i ] , sb[ i ] );
	}

	return ret;
}

int main()
{
	vector<int> a , b;
	int na , nb;
	while ( true )
	{
		vector<int> ip;
		set<int> s;
		cin >> na;
		if ( !na ) return 0;
		a = vector<int>( na );
		for ( int i = 0; i < na; ++i )
		{
			cin >> a[ i ];
			s.insert( a[ i ] );
		}
		cin >> nb;
		b = vector<int>( nb );
		for ( int i = 0; i < nb; ++i )
		{
			cin >> b[ i ];
			if ( s.find( b[ i ] ) != s.end() )
				ip.push_back( b[ i ] );
		}
		cout << "\n" << helix( a , b , ip );
	}
}