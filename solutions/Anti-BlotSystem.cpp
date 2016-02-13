#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

string antiBlot( string &a , string &b , string &c )
{
	stringstream s;
	if ( a.find( "m" ) != string::npos )
		a.clear();
	if ( b.find( "m" ) != string::npos )
		b.clear();
	if ( c.find( "m" ) != string::npos )
		c.clear();
	if ( a.empty() )
		s << atoi( c.c_str() ) - atoi( b.c_str() ) << " + " << b << " = " << c;
	else if ( b.empty() )
		s << a << " + " << atoi( c.c_str() ) - atoi( a.c_str() ) << " = " << c;
	else s << a << " + " << b << " = " << atoi( a.c_str() ) + atoi( b.c_str() ) ;
	return s.str();
}

int main()
{
	int t;
	string a , b , c;
	char op;
	cin >> t;
	for ( int i = 0; i < t; i++ )
	{
		cin >> a >> op >> b >> op >> c;
		cout << "\n" << antiBlot( a , b , c );
	}
	return 0;
}