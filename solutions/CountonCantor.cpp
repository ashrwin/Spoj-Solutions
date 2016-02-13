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
#define SL scanlong() 
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

inline ll scanlong()
{
	register int c = gc();
	register ll x = 0;
	int neg = 0;
	for ( ; ( ( c < 48 || c>57 ) && c != '-' ); c = gc() );
	if ( c == '-' ) { neg = 1; c = gc(); }
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	if ( neg ) x = -x;
	return x;
}

int next_string() {
	char c;
	int x = 0;
	while ( 1 ) {
		c = gc();
		if ( c == ' ' || c == '\n' )break;
		//	buff[ x++ ] = c;
	}
	//buff[ x ] = '\0';
	return x;
}

int cantorn[ 10000016 ] , cantord[ 10000016 ];
void init()
{
	int d = 1 , diag = 1;
	int i = 1;
	int SIZE = 10000003;
	while ( true )
	{
		d = diag;
		if ( d % 2 )
		{
			int a = d , b = 1;
			while ( d )
			{
				cantorn[ i ] = a-- ;
				cantord[ i++ ] = b++;
				--d;
				if ( i > SIZE )return;
			}
		}
		else
		{
			int a = 1 , b = d;
			while ( d )
			{
				cantorn[ i ] = a++ ;
				cantord[ i++ ] = b--;
				--d;
				if ( i > SIZE )return;
			}
		}
		diag++;
	}

}
int main()
{
	init();
	int t = SI , n;
	while ( t-- )
	{
		n = SI;
		printf( "TERM %d IS %d/%d\n" , n , cantorn[ n ] , cantord[ n ] );
	}
	return 0;
}