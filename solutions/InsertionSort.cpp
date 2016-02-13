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
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vi aux( 100101 ,0);
int merge(vi &v,int lo,int mid,int hi)
{
	int ret = 0;
	rep( i , lo , hi + 1 ) aux[ i ] = v[ i ];
	for ( int i = lo ,k=lo, j = mid + 1; i <= mid || j <= hi ; )
		if ( i > mid ) v[ k++ ] = aux[ j++ ];
		else if ( j > hi ) v[ k++ ] = aux[ i++ ];
		else if ( aux[ i ] <= aux[ j ] ) v[ k++ ] = aux[ i++ ];
		else{
			v[ k++ ] = aux[ j++ ];
			ret += mid - i + 1;
		}
	return ret;
}

int mergesort( vi &v , int l , int r )
{
	int ret = 0;
	if ( l < r )
	{
		int mid = ( l + r ) / 2;
		ret+=mergesort( v , l , mid );
		ret+=mergesort( v , mid + 1 , r );
		ret+= merge( v , l , mid , r );
	}
	return ret;
}


int main()
{
	int t;
	sf( t );
	till( t )
	{
		int n;
		sf( n );
		vi v( n );
		rep( i , 0 , n ) sf( v[ i ] );
		printf( "\n%d" , mergesort( v , 0 , n - 1 ) );
	}
	return 0;

}