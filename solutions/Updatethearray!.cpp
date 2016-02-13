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
#include<map>
#include<set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanf("%d",&a) 
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int , int> ii;
typedef vector<ii> vii;
vector<ll> bit;
int n;

void update( int x , int val )
{
	for ( int i = x; i < n; i += ( i & -i ) )
		bit[ i ] += val;
}

ll read( int x )
{
	ll ret = 0;
	for ( int i = x; i ; i -= ( i & -i ) )
		ret += bit[ i ];
	return ret;
}

void update( int s , int e , int v )
{
	update( s , v );
	update( e + 1 , -v );
}

int main()
{
	int t , s , e , val , u;
	sf( t );
	rep( Z , 0 , t )
	{
		sf( n ); sf( u );
		n++;
		bit = vector < ll>( n , 0 );
		till( u )
		{
			sf( s ); sf( e ); sf( val );
			update( s + 1 , e + 1 , val );
		}
		int q;
		sf( q );
		till( q )
		{
			int z;
			sf( z );
			printf( "\n%lld" , read( z + 1 ) );
		}
	}
	return 0;
}