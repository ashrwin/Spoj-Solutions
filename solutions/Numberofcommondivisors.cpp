/**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

inline int gcd( int a , int b )
{
	if ( !b )
		return a;
	return gcd( b , a%b );
}

inline int cmd( int a )
{
	int ret = 0;
	for ( int i = 1; i * i <= a; ++i )
	{
		if ( !( a%i ) )
			ret += 2;
		if ( i*i == a )
			ret--;
	}
	return ret;
}


int main()
{

	int t ,a,b  ;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf( "%d%d" , &a,&b );
		printf("\n%d", cmd( gcd( a , b ) ));
	}
	return 0;
}




