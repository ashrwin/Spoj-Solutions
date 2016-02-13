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
long zF( long n )
{
	int z = 0;
	for ( int i = 5; n / i >= 1; i *= 5 )
		z += n / i;
	return z;
}
int main()
{
	int n;
	long a ;
	cin >> n;
	rep( i , 0 , n )
	{
		cin >> a ;
		cout << "\n" << zF(a);
	}
	
	return 0;
}
