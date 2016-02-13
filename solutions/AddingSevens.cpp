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
#include<tr1/unordered_map>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf scanInt 
#define gc getchar
#define MAX 10000000
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int a[ 7 ];
int converter()
{
	int ret = 0 , mul = 1;
	for ( int i = 0; i <= 6; ++i )
	{
		ret += ( a[ i ] * mul );
		mul *= 2;
	}
	return ret;
}
map<string , int> m1;
map<int , string> m2;
ll reverse( const ll &sum )
{
	ll n = sum;
	ll rev = 0;
	while ( n )
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev;
}

string dec( const string &s )
{
	string hm( 3 , '0' );
	int x = 0;
	ll num[ 2 ] = { 0 };
	int npos = 0;
	for ( int i = 0; i < sz( s ) - 1; ++i )
	{
		if ( s[ i ] == '+' )
		{
			x = 0;
			npos = 1;
			continue;
		}
		hm[ ( x++ ) ] = s[ i ];
		if ( x == 3 )
		{
			num[ npos ] = num[ npos ] * 10 + m1[ hm ];
			x = 0;
		}
	}
	
	ll sum = num[ 0 ] + num[ 1 ];
	ll rsum = reverse( sum );
	stringstream ret;
	while ( rsum )
	{
		ret << m2[ rsum % 10 ];
		rsum /= 10;
	}
	while ( ( sum % 10 ) == 0 )
	{
		ret << m2[ 0 ];
		sum /= 10;
	}
	return ret.str();
}
int main()
{
	m1[ "063" ] = 0;
	m1[ "010" ] = 1;
	m1[ "093" ] = 2;
	m1[ "079" ] = 3;
	m1[ "106" ] = 4;
	m1[ "103" ] = 5;
	m1[ "119" ] = 6;
	m1[ "011" ] = 7;
	m1[ "127" ] = 8;
	m1[ "107" ] = 9;
	m2[ 0 ] = "063";
	m2[ 1 ] = "010";
	m2[ 2 ] = "093";
	m2[ 3 ] = "079";
	m2[ 4 ] = "106";
	m2[ 5 ] = "103";
	m2[ 6 ] = "119";
	m2[ 7 ] = "011";
	m2[ 8 ] = "127";
	m2[ 9 ] = "107";
	string x;

	while ( true )
	{
		char temp[ 300 ];
		stringstream ret;
		scanf( "%s" , temp );
		x = temp;
		if ( x == "BYE" )return 0;
		ret << x;
		ret << dec( x );
		printf( "\n%s" , ret.str().c_str() );
	}
	return 0;
}