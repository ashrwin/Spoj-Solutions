#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=a ; i < (int)n ; i++)
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
#define sz(v)  int(v.size())
#define sort(v) sort(all(v))

void mul( vector<long> &v , int n )
{
	long long c = 0 , x;
	for ( int i = 0 ; i < sz( v ) ; ++i )
	{
		long &e = v[ i ];
		x = e * n + c;
		e = x % 10;
		c = x / 10;
	}
	while ( c )
	{
		v.push_back( c % 10 );
		c /= 10;
	}
}
void fact( int n )
{
	vector<long> v( 1 , 1 );
	for ( int i = 2; i <= n; ++i )
		mul( v , i );
	cout << "\n";
	for ( int i = sz( v ) - 1 ; i >= 0 ; --i )
		cout << v[ i ];
}
int main()
{
	int n;
	int a ;
	cin >> n;
	rep( i , 0 , n )
	{
		cin >> a ;
		fact( a );
	}

	return 0;
}


