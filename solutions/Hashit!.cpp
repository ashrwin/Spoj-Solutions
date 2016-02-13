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
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanf("%d",&a) 
#define gc getchar
#define MAX 4000
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

string htable[ 101 ];
int size;
inline void create()
{
	rep( i , 0 , 101 ) htable[ i ].clear();
	size = 0;
}
inline int hashf(const string &key )
{
	int ret = 0;
	for ( int i = 0; i < sz(key); ++i )
		ret += key[ i ] * ( i + 1 );
	return ( 19 * ret ) % 101;
}



void add( const string &key )
{
	rep( i , 0 , 101 )if ( htable[ i ] == key )return ;
	int hkey = hashf( key );
	int j = 1;
	int pos = hkey;
	if ( htable[ pos ] == key )return ;
	while ( !htable[ pos ].empty() && j<20)
	{
		if ( htable[ pos ] == key )
			return;
		pos = ( hkey + j*j + 23 * j ) % 101;
		++j;
	}
	if ( htable[ pos ].empty() )
	{
		htable[ pos ] = key;
		++size;
	}
}

inline void del( const string &key )
{
	rep( i , 0 , 101 )
	if ( htable[ i ] == key )
	{
		htable[ i ].clear();
		--size;
	}
}

inline void printOutput()
{
	cout << "\n" << size;
	rep( i , 0 , 101 )
		if ( !htable[ i ].empty() )
			cout << "\n" << i << ":" << htable[ i ];
}
int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		create();
		int n;
		cin >> n;
		till( n )
		{
			string in;
			cin >> in;
			string op , key;
			op = in.substr( 0 , in.find( ':' ) );
			key = in.substr( in.find( ':' ) + 1 , string::npos );
			if ( op == "ADD" )
				add( key );
			else del( key );
			cout << "";
		}
		printOutput();
	}
	return 0;
}