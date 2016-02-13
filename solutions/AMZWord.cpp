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
//#include<unordered_map>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanf("%d",&a) 
#define gc getchar_unlocked
#define MAX 10000000
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
ull  dp[ 50 ][ 3 ];
int main()
{
	int n;
	sf( n );
	dp[ 0 ][ 1 ] = dp[ 0 ][ 0 ] = dp[ 0 ][ 2 ] = 1;
	for ( int i = 1; i < n; ++i )
	{
		dp[ i ][ 0 ] = dp[ i - 1 ][ 1 ] + dp[ i - 1 ][ 0 ];
		dp[ i ][ 1 ] = dp[ i - 1 ][ 0 ] + dp[ i - 1 ][ 1 ] + dp[ i - 1 ][ 2 ];
		dp[ i ][ 2 ] = dp[ i - 1 ][ 1 ] + dp[ i - 1 ][ 2 ];
	}
	printf( "\n%llu" , dp[ n - 1 ][ 0 ] + dp[ n - 1 ][ 1 ] + dp[ n - 1 ][ 2 ] );
	return 0;
}