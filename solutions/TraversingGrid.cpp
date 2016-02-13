#include<iostream>
using namespace std;
typedef unsigned long long int ull;
int main()
{
	ios::sync_with_stdio( false );
	ull t , n , m;
	cin >> t;
	while ( t-- )
	{
		cin >> n >> m;
		if ( m < n )
		{
			if ( m % 2 == 0 ) cout << "\nU";
			else cout << "\nD";
		}
		else if ( n % 2 ) cout << "\nR";
		else cout << "\nL";
	}
	return 0;
}
