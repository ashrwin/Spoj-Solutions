#include<iostream>
using namespace std;
int main()
{
	int n;
	while (true )
	{
		cin >> n;
		if ( !n )	break;
		cout<<"\n"<<(n*(n+1)*(2*n+1))/6;
	}
	return 0;
}
