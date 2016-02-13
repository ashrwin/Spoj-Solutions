#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main()
{
	ios::sync_with_stdio( false );
	int ret = 0 , rem = 100 , t;
	for ( int i = 0; i < 10; ++i )
	{
		cin >> t;
		if ( rem>0 && (abs(100-( ret + t)) ) <= rem )
		{
			ret += t;
			rem -= t;
		}
		else break;
	}
	cout << "\n"<< ret;
	return 0;
}