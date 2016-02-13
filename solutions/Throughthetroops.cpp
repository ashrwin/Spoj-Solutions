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
#define MAX 1000010
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
int dp[ 30 ][ 3 ];
int main()
{
	int t = SI;
	till( t )
	{
		int n = SI;
		rep( i , 0 , n ) rep( j , 0 , 3 )dp[ i ][ j ] = SI;
		rep( i , 1 , n )
		{
			dp[ i ][ 0 ] += min( dp[ i - 1 ][ 1 ] , dp[ i - 1 ][ 2 ] );
			dp[ i ][ 1 ] += min( dp[ i - 1 ][ 0 ] , dp[ i - 1 ][ 2 ] );
			dp[ i ][ 2 ] += min( dp[ i - 1 ][ 0 ] , dp[ i - 1 ][ 1 ] );
		}
		int ret = min( dp[ n - 1 ][ 0 ] , min( dp[ n - 1 ][ 1 ] , dp[ n - 1 ][ 2 ] ) );
		printf( "%d\n" , ret );
	}
	return 0;
}