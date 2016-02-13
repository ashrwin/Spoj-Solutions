#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
typedef unsigned long long ull;

int main()
{
	ull n;
	cin >> n;
	if ( n % 10 )
		cout << "\n1\n" << n % 10;
	else cout << "\n2";
	return 0;
}
