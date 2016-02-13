/**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<math.h>
#include<stdlib.h>
using namespace std;



int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	int n , k , p , f;
	while ( t-- )
	{
		cin >> n >> k >> p >> f;
		cout << "\n" << n + k*( f - n ) / ( k - 1 );
	}
	return 0;
}

