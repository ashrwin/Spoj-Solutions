#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define mp make_pair
using namespace std;
typedef unsigned long long ull;
typedef pair<int , int> ii;

inline ull gcd( ull a , ull b )
{
	if ( !b )return a;
	return gcd( b , a%b );
}

int main()
{
	
	int t;
	cin >> t;
	while ( t-- )
	{
		int a,b;
		cin >> a >> b;
		ull g = gcd( a , b );
		cout << "\n" << b / g << " " << a / g;
	}
	return 0;
}