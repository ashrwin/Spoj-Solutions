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
#define sf scanInt 
#define gc getchar_unlocked
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

struct order
{
	int s , e , val;
	bool operator<( const order &b ) const
	{
		return ( s == b.s ) ? e < b.e : s < b.s;
	}
};
order o[ 10002 ];
int n;
int dp[ 10002 ];
int binSearch( int lo , int hi , int val )
{
	int ret = -1;
	while ( lo <= hi )
	{
		int mid = ( lo + hi ) / 2;
		if ( o[ mid ].s >= val )
		{
			ret = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	return ret;
}
int func()
{
	dp[ n - 1 ] = o[ n - 1 ].val;
	for ( int i = n - 2; i >= 0; --i )
	{
		int next = binSearch( i+1 , n-1 , o[ i ].e );
		if ( next != -1 )
			dp[ i ] = max( dp[ i + 1 ] , dp[ next ] + o[ i ].val );
		else dp[ i ] = max( dp[ i + 1 ] , o[ i ].val );
	}
	return dp[ 0 ];
}

void scanInt( int &x )
{
	register int c = gc();
	x = 0;
	for ( ; ( c<48 || c>57 ); c = gc() );
	for ( ; c>47 && c<58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
}

int main()
{
	int t;
	scanInt( t );
	till( t )
	{
		scanInt( n );
		rep( i , 0 , n )
		{
			scanInt( o[i].s ); scanInt( o[i].e ); scanInt( o[i].val );
			o[ i ].e += o[ i ].s;
		}
		sort( o , o + n );
		//rep( i , 0 , 10001 )dp[ i ] = -1;
		printf( "\n%d" , func() );
	}
	return 0;
}
