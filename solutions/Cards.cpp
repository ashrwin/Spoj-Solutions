#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
typedef unsigned long long ull; 
int main()
{
	int t;
	ull n ;
	cin >> t;
	for ( int i = 0; i < t; ++i )
	{
		cin >> n;
		cout << "\n" << ( n*( 3 * n + 1 ) / 2 ) % 1000007;
	}
	return 0;
}