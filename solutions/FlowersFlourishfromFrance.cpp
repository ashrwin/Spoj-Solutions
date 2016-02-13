#include<iostream>
#include<string>
#include<sstream>
using namespace std;

char taut( const string &s )
{
	stringstream ss( s );
	string x;
	ss >> x;
	char f = toupper( x[ 0 ]);
	while ( ss >> x )
		if ( toupper(x[ 0 ]) != f )
			return 'N';
	return 'Y';
}

int main()
{
	ios::sync_with_stdio( false );
	string s;
	while ( true )
	{
		getline( cin , s );
		if ( s == "*" ) return 0;
		if ( s.empty() ) continue;
		cout << "\n" << taut( s );
	}
	return 1;
}

