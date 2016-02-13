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
typedef long long ll;

ll res( ll a , string op , ll b )
{
	if ( op == "+" )
		return a + b;
	if ( op == "-" )
		return a - b;
	if ( op == "*" )
		return a*b;
	if ( op == "/" )
		return a / b;
	return 0;
}

ll calc(  )
{
	string t,op;
	ll a,b,ret = 0;
	cin >> a >> op >> b;
	ret = res(a,op,b);
	cin >> op;
	while (  op != "=" )
	{
		cin >> b;
		ret = res( ret , op , b );
		cin >> op;
	}
	return ret;
}


int main()
{
	
	int t,n;
	cin >> t;
	for ( int i = 0; i < t;++i )
		cout << "\n" << calc() << endl;
	return 0;
}
