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
typedef unsigned long long ull;



int nodivisors( int n )
{
	int div = 0;
	for ( int i = 1; i <= floor( sqrt( n ) ); ++i )
		if ( n%i == 0 )
			div++;
	return div;
}




int main()
{
	int n;
	cin >> n;
	ull ret = 0;
	for ( int i = 1; i <= n; ++i )
		ret += nodivisors( i );
	cout << "\n" << ret;
}

