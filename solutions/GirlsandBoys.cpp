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

int main()
{
	int bt , gt , x , y;
	while ( 1 )
	{
		cin >> bt >> gt;
		if ( bt == -1 && gt == -1 ) return 0;
		x = max( bt , gt );
		y = min( bt , gt );
		cout << "\n" << ceil( (double)x / ( y + 1 ) );
	}
	return 1;
}
