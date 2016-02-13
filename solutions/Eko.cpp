#include <vector>
#include <map>
#include <set>
#include <queue>
#include<memory.h>
#include<string.h>
#include <stack>
#include <algorithm>
#include <functional>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<assert.h>
#include<unordered_map>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define SU scanulong() 
#define gc getchar_unlocked
#define pc putchar
#define MAX 1000010
#define pi 3.14159265358979323846264338327950
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

inline int scanint()
{
	register int c = gc();
	register int x = 0;
	int neg = 0;
	for ( ; ( ( c < 48 || c>57 ) && c != '-' ); c = gc() );
	if ( c == '-' ) { neg = 1; c = gc(); }
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	if ( neg ) x = -x;
	return x;
}

inline ull scanulong()
{
	register int c = gc();
	register ull x = 0;
	int neg = 0;
	for ( ; ( ( c < 48 || c>57 ) && c != '-' ); c = gc() );
	if ( c == '-' ) { neg = 1; c = gc(); }
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	return x;
}

vi v;
int m;
int n;
bool pred( int x )
{
	int cut = 0;
	for ( int i = n - 1; i >= 0; --i )
	{
		if ( v[ i ] <= x )break;
		cut += v[ i ] - x;
		if ( cut >= m )break;
	}
	return cut >= m;
}

int binarySearch( int hi )
{
	int lo = 1 , mid;
	int sol;
	while ( lo <= hi )
	{
		mid = lo + ( hi - lo ) / 2;
		if ( pred( mid ) )
		{
			sol = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	return sol;
}



int main()
{
	n = SI;
	m = SI;
	v = vi( n );
	rep( i , 0 , n )v[ i ] = SI;
	sort( all( v ) );
	printf( "%d\n" , binarySearch( v[ n - 1 ] + 1 ) );
	return 0;
}