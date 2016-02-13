#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
typedef unsigned long long ull;

int main()
{
	int t;
	long long r;
	cin >> t;
	for ( int i = 1; i <= t; ++i )
	{
		cin >> r;
		cout<<"Case "<<i<<": "<<4*r*r<<".25"<<endl;
	}
	return 0;
}

