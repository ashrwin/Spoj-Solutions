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
#include<cstdio>
#include<cstring>
#include <ctime>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar
#define pc putchar
#define MAX 1000010
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int main()
{
	ios::sync_with_stdio( false );
	string s;
	while ( cin >> s && s != "0" )
	{
		ll dp[ 6001 ];
		fill( dp , dp + 6000 , 0 );
		dp[ 0 ] = dp[ 1 ] = 1;
		int n = ( s[ 0 ] - '0' ) * 10 + s[ 1 ] - '0';
		if ( n <= 26 && s[ 1 ] != '0' )
			dp[ 1 ] = dp[ 0 ] + 1;
		rep( i , 2 , sz( s ) )
		{
			int n = ( s[ i - 1 ] - '0' ) * 10 + s[ i ] - '0';
			if ( s[ i ] - '0' )dp[ i ] = dp[ i - 1 ];
			if ( n > 9 && n <= 26 )
				dp[ i ] += dp[ i - 2 ];
		}
		cout << dp[ sz( s ) - 1 ] << "\n";
	}
	return 0;
}