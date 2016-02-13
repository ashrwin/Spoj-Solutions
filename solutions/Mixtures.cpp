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
#include<unordered_map>
#include<unordered_set>
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

int n;
int v[ 121 ];

inline int col( int i , int j )
{
	int ret = 0;
	for ( ; i <= j; ++i )
		ret = ( ret + v[ i ] ) % 100;
	return ret;
}
int memo[ 105 ][ 105 ];

int smoke( int i , int j )
{
	if ( i == j )return 0;
	int &ret = memo[ i ][ j ];
	if ( ret != -1 )
		return ret;
	ret = ( 1 << 30 );
	for ( int k = i; k < j; ++k )
		ret = min( ret , smoke( i , k ) + smoke( k + 1 , j ) + col( i , k )*col( k + 1 , j ) );
	return ret;
}


int main()
{
	while ( cin >> n )
	{
		rep( i , 0 , n )	cin >> v[ i ];
		memset( memo , -1 , sizeof memo );
		cout << smoke( 0 , n - 1 ) << "\n";
	}
	return 0;
}