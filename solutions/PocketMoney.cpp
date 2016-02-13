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
//#include<unordered_map>
//#include<tr1/unordered_set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar
#define MAX 10000
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

inline int scanint()
{
	register int c = gc();
	register int x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	return x;
}
string s;
vector<ull> v;
vector<char> op;
inline void preProcess()
{
	v.clear(); op.clear();
	rep( i , 0 , sz( s ) )
	{
		if ( isdigit( s[ i ] ) )
			v.push_back( s[ i ] - '0' );
		else op.push_back( s[ i ] );
	}
}
ull m1[ 100 ][ 100 ] , m2[ 100 ][ 100 ];
ull dpmax( int i , int j )
{
	if ( i == j ) return v[ i ];
	ull &ret = m1[ i ][ j ];
	if ( ret != 0 )
		return ret;
	ret = 0;
	for ( int k = i ; k < j; ++k )
	{
		ull a = dpmax( i , k ) , b = dpmax( k + 1 , j );
		if ( op[ k ] == '+' )
			a += b;
		else a *= b;
		ret = max( ret , a );
	}
	return ret;
}

ull dpmin( int i , int j )
{
	if ( i == j ) return v[ i ];
	ull &ret = m2[ i ][ j ];
	if ( ret != (ull)-1 )
		return ret;
	ret = (ull)-1;
	for ( int k = i ; k < j; ++k )
	{
		ull a = dpmin( i , k ) , b = dpmin( k + 1 , j );
		if ( op[ k ] == '+' )
			a += b;
		else a *= b;
		ret = min( ret , a );
	}
	return ret;
}



int main()
{
	int t;
	t = SI;
	till( t )
	{
		cin >> s;
		preProcess();
		rep( i , 0 , 100 )rep( j , 0 , 100 )
		{
			m1[ i ][ j ] = 0;
			m2[ i ][ j ] = (ull)-1;
		}
		printf( "\n%llu %llu" , dpmax( 0 , sz( v ) - 1 ) , dpmin( 0 , sz( v ) - 1 ) );
	}

	return 0;
}