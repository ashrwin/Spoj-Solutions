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
//#include<unordered_set>
//#include<unordered_map>
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
typedef vector<ll> vl;

vvi g;
bool vis[ 1000000 ];
int val = 0;
int dfs( int u )
{
	vis[ u ] = true;
	int len = 1;
	rep( j , 0 , sz( g[ u ] ) )
		if ( !vis[ g[ u ][ j ] ] )
			len += dfs( g[ u ][ j ] ) + 1;
	val += len;
	return len;
}

int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		memset( vis , 0 , sizeof vis );
		int n;
		cin >> n;
		g = vvi( n );
		rep( i , 0 , n - 1 )
		{
			int u , v;
			cin >> u >> v;
			g[ u ].push_back( v );
			g[ v ].push_back( u );
		}
		val = 0;
		dfs( 0 );
		cout << val << "\n";
	}
	return 0;
}
