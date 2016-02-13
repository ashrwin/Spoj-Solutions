#include<iostream>
#include<string>
using namespace std;

void patCount( const string &t , const string &p )
{
	int ret = 0,pos=-1,flag=0;
	while ( ( pos = t.find( p , pos + 1 ) ) != string::npos )
	{
		cout << "\n" << pos;
		flag = 1;
	}
	if ( !flag ) cout << "\n\n";
}

int main()
{
	ios::sync_with_stdio( false );
	int n;
	string text , pat;
	while ( cin >> n )
	{
		cin >> pat;
		cin >> text;
		patCount( text , pat );
	}
	return 0;
}
