#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
typedef unsigned long long ull;

int main()
{
	ull n,t;
	int p;
	cin >> t;
	for ( ull i = 0; i < t; ++i )
	{
		cin >> n>>p;
		( p == 0 ) ? cout<<"Airborne wins." : cout<<"Pagfloyd wins.";
		cout << endl;
	}
	return 0;
}
