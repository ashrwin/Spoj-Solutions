#include <iostream>
using namespace std;
typedef unsigned long long ull;
int lastDigit( int base , ull  exp )
{
	int res = 1;
	while ( exp )
	{
		if ( exp % 2 )
			res = ( res*base ) % 10;
		exp >>= 1;
		base = ( base*base ) % 10;
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	int base;
	ull exp;
	for(int i=0 ; i <n ; i++ ) 
	{	
		cin >> base >> exp;
		cout << "\n" << lastDigit( base , exp );
	}
	return 0;
}


