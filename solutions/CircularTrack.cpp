/**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<math.h>
#include<stdlib.h>
using namespace std;

int gcd(int a,int b)
{
	if ( !b ) return a;
	return gcd( b , a%b );
}



int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	int a , b;
	while ( t-- )
	{
		cin >> a >> b;
		cout << "\n" << abs( a - b ) / gcd( abs(a) , abs(b) );
	}
	return 0;
}

