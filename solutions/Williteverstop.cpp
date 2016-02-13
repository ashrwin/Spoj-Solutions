#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<functional>
#include<set>
typedef unsigned long long ull;
using namespace std;

set<ull> s;
int main()
{
	ull n;
	cin >> n;
	if ( n <= 2 )
	{
		cout << "\nTAK"; return 0;
	}
	while ( n > 1 )
	{
		if ( n % 2 == 0 )
			n /= 2;
		else n = 3 * n + 3;
		
		if ( ( n &( n - 1 ) ) == 0 )
		{
			cout << "\nTAK"; break;
		}
		if ( s.find( n ) != s.end() )
		{
			cout << "\nNIE"; break;
		}
		s.insert( n );
	}
	return 0;
}