#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef unsigned long long ull;

int cards( double n )
{
	double x = 0.0,i;
	for ( i = 2; x < n; i++ )
	{
		x = x + ( 1.0 / i );
	}
	return (int)i-2;
}

int main()
{
	double n;
	while ( true )
	{
		cin >> n;
		if ( n == 0.00 )
			return 0;
		cout << "\n" << cards( n ) << " card(s)";
	}
	return 1;
}