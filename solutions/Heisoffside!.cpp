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
	int a , d , amin = 900000 , dmin = 900000 , t , c = 900000;
	while ( true )
	{
		cin >> a >> d;
		if ( !a && !d )return 0;
		vector<int> p(a);
		for ( int i = 0; i < a; ++i )
			cin >> p[i];

		vector<int> v(d);
		for ( int i = 0; i < d; ++i )
			cin >> v[i];
		sort(p.begin(),p.end());
		sort( v.begin() , v.end() );
		if ( p[0] < v[1]  )
			cout << "\nY";
		else
			cout << "\nN";
	}
	return 1;
}


