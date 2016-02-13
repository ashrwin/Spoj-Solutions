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
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
int h , w;
const int dy[ 8 ] = { 1 , 0 , -1 , 0 , -1 , 1 , 1 , -1 };
const int dx[ 8 ] = { 0 , 1 , 0 , -1 , -1 , -1 , 1 , 1 };
bool vis[ 51 ][ 51 ];
char maze[ 52 ][ 52 ];

int dfs( ii s )
{
	vis[ s.first ][ s.second ] = true;
	int ret = 1;
	rep( i , 0 , 8 )
	{
		int p = s.first + dy[ i ];
		int q = s.second + dx[ i ];
		if ( p < 0 || q < 0 || p >= h || q >= w || vis[ p ][ q ] || ( maze[ p ][ q ] != maze[ s.first ][ s.second ] + 1 ) )
			continue;
		ret = max( ret , dfs( mp( p , q ) ) + 1 );
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio( false );
	int Z = 0;
	while ( true )
	{
		Z++;
		cin >> h >> w;
		if ( !h && !w )
			return 0;
		rep( i , 0 , h )rep( j , 0 , w )cin >> maze[ i ][ j ];
		int ret = 0;
		rep( i , 0 , h )rep( j , 0 , w )
			if ( maze[ i ][ j ] == 'A' )
			{
			rep( p , 0 , 51 )rep( q , 0 , 51 )vis[ p ][ q ] = false;
			ret = max( ret , dfs( mp( i , j ) ) ) ;
			}
		cout << "\nCase "<<Z<<": "<<ret;
	}
	return 0;
}