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
#include<fstream>
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
#define pc putchar
#define MAX (1<<30)
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
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
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	return x;
}
inline void printInt( int a )
{
	char s[ 11 ];
	int t = -1;
	do{
		s[ ++t ] = a % 10 + '0';
		a /= 10;
	} while ( a > 0 );
	while ( t >= 0 )pc( s[ t-- ] );
	pc( '\n' );
}
int into[ 1101 ] = { 0 } , out[ 1101 ] = { 0 };
int main()
{
	int Z = 0;
	while ( 1 )
	{
		++Z;
		int n = SI;
		if ( !n )return 0;
		int initial = 0;
		rep( i , 0 , n )rep( j , 0 , n )into[ i ] = out[ i ] = 0;
		rep( i , 0 , n )rep( j , 0 , n )
		{
			int k = SI;
			if ( 1 )
			{
				initial += k;
				into[ j ] += k;
				out[ i ] += k;
			}
		}
		int ret = 0;
		rep( i , 0 , n )
		{
			into[ i ] = into[ i ] - out[ i ] ;
			if ( into[ i ] > 0 )
				ret += into[ i ];
		}
		printf( "%d. %d %d\n" , Z , initial , ret );
	}
	return 0;
}
