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
long rev( long n )
{
	long rev=0;
	int d;
	while ( n )
	{
		d = n % 10;
		rev = rev * 10 + d;
		n /= 10;
	}
	return rev;
}
int main()
{
	int n;
	long a , b;
	cin >> n;
	rep( i , 0 , n )
	{
		cin >> a >> b;
		cout << "\n" << rev(rev( a ) + rev( b ));
	}
	return 0;
}
