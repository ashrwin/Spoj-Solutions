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
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
int memo[ 1010 ][ 1010 ];
int dp( vi &v , int s , int e  )
{
	if ( s > e ) return 0;
	if ( s == e )
		return v[ s ];
	int &ret = memo[ s ][ e ];
	if ( ret != -1 )
		return ret;
	int left = v[s];
	if ( v[ s + 1 ] >= v[ e ] )
		left += dp( v , s + 2 , e );
	else if ( v[ e ] > v[ s + 1 ] )
		left += dp( v , s + 1 , e-1  );
	
	int right = v[e];
	if ( v[ s ] >= v[ e - 1 ] )
		right += dp( v , s + 1 , e - 1  );
	else
		right += dp( v , s , e - 2  );
	ret= max( left , right );
	return ret;
}


int main()
{
	int n;
	int Z = 0;
	while ( true )
	{
		sf( n );
		if ( !n )break;
		++Z;
		vi v( n );
		int sum = 0;
		rep( i , 0 , n )
		{
			sf( v[ i ] );
			sum += v[ i ];
		}
		rep( i , 0 , 1010 ) rep( j , 0 , 1010 ) memo[ i ][ j ] = -1;
		int ret = dp( v , 0 , n - 1 );
		printf( "\nIn game %d, the greedy strategy might lose by as many as %d points.",Z,ret-(sum-ret) );
	}

	return 0;
}