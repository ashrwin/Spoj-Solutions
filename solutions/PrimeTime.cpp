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
#define gc getchar_unlocked
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
const int size = 11010;
bool p[ size ] = { false };
vi primes;
inline void seive()
{
	for ( int i = 2; i < size; ++i )
		if ( !p[ i ] )
		{
		primes.push_back( i );
		for ( int j = i*i; j < size; j += i )
			p[ j ] = true;
		}
}

int main()
{
	seive();
	int n = SI;
	stringstream ret;
	for ( int i = 0; i < sz( primes ) && primes[ i ] <= n ; ++i )
	{
		ret << primes[ i ] << "^";
		int k = 0;
		int z = primes[ i ] , multi = z;
		while ( n / z > 0 )
		{
			k += n / z;
			z *= multi;
		}
		ret << k;
		if ( i + 1 < sz( primes ) && primes[ i + 1 ] <= n )
			ret << " * ";
	}
	printf( "%s\n" , ret.str().c_str() );
	return 0;
}