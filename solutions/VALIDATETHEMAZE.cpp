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

char maze[ 25 ][ 25 ];
int n , m;
bool vis[ 25 ][ 25 ];
const int dx[] = { -1 , 0 , 1 , 0 } , dy[] = { 0 , 1 , 0 , -1 };
void dfs( int r , int c )
{
	vis[ r ][ c ] = true;
	rep( i , 0 , 4 )
	{
		int R = r + dy[ i ] , C = c + dx[ i ];
		if ( R < 0 || C < 0 || R >= n || C >= m || vis[ R ][ C ] || maze[ R ][ C ] == '#' )
			continue;
		dfs( R , C );
	}
}

int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		vii ep;
		memset( vis , 0 , sizeof vis );
		cin >> n >> m;
		rep( i , 0 , n )rep( j , 0 , m )
		{
			cin >> maze[ i ][ j ];
			if ( ( i == 0 || j == 0 || i == n - 1 || j == m - 1 ) && maze[ i ][ j ] == '.' )
				ep.push_back( mp( i , j ) );
		}

		if ( sz( ep ) != 2  )
			cout << "invalid";
		else
		{
			dfs( ep[ 0 ].first , ep[ 0 ].second );
			if ( vis[ ep[ 1 ].first ][ ep[ 1 ].second ] )
				cout << "valid";
			else cout << "invalid";
		}
		cout << "\n";
	}
	return 0;
}
