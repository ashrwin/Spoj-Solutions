#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
int main()
{
	ull t , n , sum = 0,val;
	cin >> t;
	for ( ull i = 0; i < t; ++i )
	{
		cin >> n;
		sum = 0;
		for ( ull j = 0; j < n; j++ )
		{
			cin >> val;
			sum = (sum+val)%n;
		}
		if ( !sum )
			cout << "\nYES";
		else cout << "\nNO";
	}
	return 0;
}

