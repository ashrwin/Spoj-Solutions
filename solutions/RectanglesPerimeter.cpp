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
vii rect;
int n;
const int SIZE = 1100;
int memo[ SIZE ][ SIZE ];
int func( int i , int p )
{
	if ( i >= n )
		return 0;
	int &ret = memo[ i ][ p ];
	if ( ret != -1 )
		return ret;
	//1st config
	if ( i == 0 )
		p = rect[ i ].first;
	int f = ( abs( p - rect[ i ].first ) + rect[ i ].second + func( i + 1 , rect[ i ].first ) );
	if ( i == 0 )
		p = rect[ i ].second;
	//2nd config
	int s = ( abs( p - rect[ i ].second ) + rect[ i ].first + func( i + 1 , rect[ i ].second ) );
	ret = max( f , s );
	return ret;
}
int main()
{

	sf( n );
	rect = vii( n );
	rep( i , 0 , n )
	{
		sf(rect[ i ].first);
		sf( rect[ i ].second);
	}
	rep( i , 0 , SIZE )rep( j , 0 , SIZE )memo[ i ][ j ] = -1;
	printf( "\n%d" , func( 0 , 0 ) );
	return 0;
}