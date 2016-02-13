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

vi ans;
void seive()
{
	bool prime[ MAX ];
	rep( i , 0 , MAX )prime[ i ] = true;
	for ( int i = 2; i < sqrt( MAX ); ++i )
		if ( prime[ i ] )
			for ( int j = i *i; j < MAX; j += i )
				prime[ j ] = false;;
	for ( int i = 2; i < MAX; ++i )
	{
		if ( prime[ i ] ) continue;
		int div = 0;
		for ( int j = 2; j < i ; ++j )
			if (prime[j] && ( i %  j ) == 0 )
				div++;
		if ( div > 2 )
			ans.push_back( i );
	}
}

int main()
{
	seive();
	int t;
	sf( t );
	//sort( all( ans ) );
	till( t )
	{
		int n;
		sf( n );
		printf( "\n%d" , ans[ n - 1 ] );

	}
	return 0;

}