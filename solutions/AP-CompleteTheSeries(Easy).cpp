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
	ull x , y , z,t,a,n,d;
	cin >> t;
	for ( int i = 0; i < t;++i )
	{
		cin >> x >> y >> z;
		n = 2 * z / ( x + y );
		d = ( y - x ) / ( n - 5 );
		a = x - 2 * d;
		cout << "\n"<<n<<endl;
		for ( ull k = 1; k <=n; k++ , a += d )
			cout << a << " ";
	}
	return 0;
}
