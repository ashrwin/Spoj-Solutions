#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
typedef long long int ll;

string base( ll n )
{
	if ( !n ) return "0";
	string ret;
	int b = -2,rem;
	while ( n )
	{
		rem = n%b;
		n = n / b;
		if ( rem < 0 )
		{
			rem += 2;
			n++;
		}
		ret.insert( ret.begin() , rem+'0' );
	}
	return ret;
	
}

int main()
{
	ios::sync_with_stdio( false );
	ll n;
	cin >> n;
	cout << "\n" << base( n );
	return 0;
}