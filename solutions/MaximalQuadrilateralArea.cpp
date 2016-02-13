#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	double a , b , c , d;
	cin >> t;
	for ( int i = 0; i < t; ++i )
	{
		cin >> a >> b >> c >> d;
		double s = ( a*1.0 + b + c + d ) / 2.0;
		double area = sqrt( (s-a)*(s-b)*(s-c)*(s-d) );
		
		printf("%lf\n",area);
	}
	

	return 0;
}
