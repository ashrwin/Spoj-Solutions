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

int dp[ 10002 ][ 2 ];

void init()
{
	dp[ 1 ][ 1 ] = 1;
	dp[ 2 ][ 0 ] = 2;
	dp[ 2 ][ 1 ] = 4;
	rep( i , 3 , 10002 )
		if ( i & 1 )
			dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + 1 , dp[ i ][ 1 ] = dp[ i - 1 ][ 1 ] + 1;
		else dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + 3 , dp[ i ][ 1 ] = dp[ i - 1 ][ 1 ] + 3;
}
int main()
{
	ios::sync_with_stdio( false );
	init();
	int n;
	cin >> n;
	till( n )
	{
		int x , y;
		cin >> x >> y;
		if ( y != x - 2 && y != x )
			cout << "No Number";
		else if ( y == x - 2 )
			cout << dp[ x ][ 0 ];
		else cout << dp[ x ][ 1 ];
		cout << "\n";
	}
	return 0;
}