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
#include<cstdio>
#include<cstring>
#include <ctime>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar
#define pc putchar
#define MAX 1000010
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef pair<double , double> dd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vvi adj;
vector<bool> vis;
void dfs( int u )
{
	vis[ u ] = true;
	for ( int i = 0; i < sz( adj[ u ] ); ++i )
		if ( !vis[ adj[ u ][ i ] ] )
			dfs( adj[ u ][ i ] );
}
int main()
{
	int z;
	scanf( "%d" , &z );
	till( z )
	{
		int v , e;
		scanf( "%d" , &v ); scanf( "%d" , &e );
		adj = vvi( v );
		vis = vector<bool>( v , false );
		rep( i , 0 , e )
		{
			int a , b;
			scanf( "%d" , &a ); scanf( "%d" , &b );
			adj[ a ].push_back( b ); adj[ b ].push_back( a );
		}
		int ans = 0;
		rep( i , 0 , v )
			if ( !vis[ i ] )
				dfs( i ) , ++ans;
		printf( "%d\n" , ans );
	}

	return 0;
}