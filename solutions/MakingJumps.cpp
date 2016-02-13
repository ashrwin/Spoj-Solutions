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
#include<unordered_set>
#include<unordered_map>
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

char board[ 12 ][ 12 ];
int n;
const int dx[] = { -2 , -2 , -1 , -1 , 1 , 1 , 2 , 2 };
const int dy[] = { -1 , 1 , -2 , 2 , -2 , 2 , -1 , 1 };
bool vis[ 12 ][ 12 ];
int dfs( int r , int c )
{
	int ret = 1;
	vis[ r ][ c ] = true;
	rep( i , 0 , 8 )
	{
		int R = r + dy[ i ] , C = c + dx[ i ];
		if ( R < 0 || C < 0 || R >= n || C >= 10 || board[ R ][ C ] == 'x' || vis[ R ][ C ] )
			continue;
		ret = max( ret , dfs( R , C )+1 );
	}
	vis[ r ][ c ] = false;
	return ret;
}

int main()
{
	int Z = 0;
ios::sync_with_stdio( false );
	while ( cin >> n&&n )
	{
		++Z;
		int tot = 0;
		rep( i , 0 , 12 )rep( j , 0 , 12 )board[ i ][ j ] = 'x';
		rep( i , 0 , n )
		{
			int x , y;
			cin >> x >> y;
			tot += y;
			rep( k , 0 , y )
				board[ i ][ x + k ] = '.';
		}
		memset( vis , 0 , sizeof vis );
		int ans = tot - dfs( 0 , 0 );
		if (ans!=1 )
			cout << "Case " << Z << ", " << ans << " squares can not be reached.";
		else cout << "Case " << Z << ", " << ans << " square can not be reached.";
		cout << "\n";
	}

}


