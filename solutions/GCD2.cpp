#include <iostream>
#include<string>
using namespace std;

int getNum( string x , int a )
{
	int ret = 0;
	for ( int i = 0; i < x.size(); ++i )
			ret = ( ( ret * 10 ) + ( x[ i ] - '0' ) ) % a;
	return ret;
}

int gcd( int a , int b )
{
	if ( b == 0 )
		return a;
	else
		return gcd( b , a%b );
}

int main()
{
	string bs;
	int a,t;
	cin >> t;
	while ( t-- )
	{
		cin >> a >> bs;
		if(a==0)
		{
		cout<<"\n"<<bs;
		continue;
		}
		int num = getNum( bs , a );
		cout << "\n" << gcd( a , num );
	}
	
}

