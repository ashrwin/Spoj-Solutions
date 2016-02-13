#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;


int main()
{
	int t;
	cin >> t;
	while ( t-- )
	{
		ll n , m;
		cin >> n >> m;
		cout << "\n" << !( ( n - m )&( ( m - 1 ) / 2 ) );
	}
}