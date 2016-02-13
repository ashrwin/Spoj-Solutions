#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef unsigned long long ull;


int main()
{
	ull t,n;
	cin >> t;
	for ( int i = 0; i < t; i++ )
	{
		cin >> n;
		cout << "\n" << (n-1)*250+192 ;
	}
	return 0;
}
