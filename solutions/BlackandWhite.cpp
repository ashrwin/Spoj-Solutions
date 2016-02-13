#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
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
#include<string.h>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<assert.h>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanf("%d",&a) 
#define gc getchar
#define MAX 10000000
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
string s , t;

int dp( int i )
{
	if ( i >= sz( s ) )
		return 0;
	int ret = 0;
	for ( ; i < sz( s ) && s[ i ] == t[ i ]; ++i );
	for ( ; i < sz( s ) && s[ i ] != t[ i ]; ++i )
		ret = 1;
	return dp( i ) + ret;
}

int main()
{
	ios::sync_with_stdio( false );
	while ( true )
	{
		cin >> s >> t;
		if ( s == "*" && t == "*" )
			return 0;
		cout << "\n" << dp( 0 );
	}
	return 1;
}