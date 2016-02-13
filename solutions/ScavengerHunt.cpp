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
#define gc getchar
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
map<string , string> to , pre;
set<string> s;
int main()
{
	int t = SI , n;
	string a , b;
	int Z = 0;
	till( t )
	{
		++Z;
		n = SI;
		to.clear(); s.clear(); pre.clear();
		int ind = 0;
		--n;
		till( n )
		{
			cin >> a >> b;
			s.insert( a ); s.insert( b );
			to[ a ] = b;
			pre[ b ] = a;
		}
		string start;
		for ( set<string>::iterator it = s.begin(); it != s.end(); ++it )
			if ( pre.find( *it ) == pre.end() )
			{
			start = *it; break;
			}
		printf( "Scenario #%d:\n",Z );
		printf( "%s\n" , start.c_str() );
		while ( 1 )
		{
			string nex = to[ start ];
			if ( nex.empty() )break;
			printf( "%s\n" , nex.c_str() );
			start = nex;
		}
		printf( "\n" );
	}
	return 0;
}