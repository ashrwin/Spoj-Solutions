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
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanf("%d",&a) 
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

int an[ 100 ];
char bn[ 100 ];
inline ll convert10( string s , int base )
{
	ll ret = 0;
	int mp = 1;
	for ( int i = sz( s ) - 1; i >= 0; --i )
	{
		ret += ( mp* an[ s[ i ] ] );
		mp *= base;
	}
	return ret;
}

string convertb( ll x , int base )
{
	string ret;
	int size = 0;
	while ( x )
	{
		ret.push_back( bn[ x%base ] );
		x /= base;
		if ( ++size > 7 )
			return "ERROR";
	}
	reverse( ret.begin() , ret.end() );
	return ret;
}

int main()
{
	rep( i , '0' , '9' + 1 )  an[ i ] = ( i - '0' );
	rep( i , 'A' , 'G' )	an[ i ] = ( i - 'A' ) + 10;
	rep( i , 0 , 10 )	bn[ i ] = ( i + '0' );
	rep( i , 10 , 16 )	bn[ i ] = ( i - 10 + 'A' );
	string s;
	int cbase , tbase;
	while ( cin >> s )
	{
		cin >> cbase >> tbase;
		ll num = convert10( s , cbase );
		string ans = convertb( num , tbase );
		printf( "%7s\n" , ans.c_str() );		
	}
	return 0;
}