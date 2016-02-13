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

int cells[ 101 ][ 101 ];
int n;
int floyd( int tim , int exit )
{
	rep( k , 1 , n ) rep( i , 1 , n ) rep( j , 1 , n )
		cells[ i ][ j ] = min( cells[ i ][ j ] , cells[ i ][ k ] + cells[ k ][ j ] );
	int ret = 0;
	rep( i , 1 , n ) if ( cells[ i ][ exit ] <= tim ) ret++;
	return ret;
}

int main()
{
	ios::sync_with_stdio( false );
	cin >> n;
	++n;
	int e;
	cin >> e;
	int time;
	cin >> time;
	int m;
	cin >> m;
	rep( i , 0 , 101 ) rep( j , 0 , 101 )
	{
		cells[ i ][ j ] = 100000;
		cells[ i ][ i ] = 0;
	}
	till( m )
	{
		int u , v , c;
		cin >> u >> v >> c;
		cells[ u ][ v ] = c;
	}
	cout << "\n" << floyd( time , e );

	return 0;

}