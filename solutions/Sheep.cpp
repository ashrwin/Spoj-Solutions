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

char maze[ 300 ][ 300 ];
bool vis[ 320 ][ 320 ] = { 0 };
int n , m;

const int dx[] = { -1 , 0 , 1 , 0 } , dy[] = { 0 , 1 , 0 , -1 };

bool out = false;
int w , s;
void dfs( int r , int c )
{
	vis[ r ][ c ] = true;
	if ( maze[ r ][ c ] == 'v' )w++;
	if ( maze[ r ][ c ] == 'k' )++s;
	rep( i , 0 , 4 )
	{
		int R = r + dy[ i ] , C = c + dx[ i ];
		if ( R < 0 || C < 0 || R >= n || C >= m )
		{
			out = true;
			continue;
		}
		if ( maze[ R ][ C ] == '#' || vis[ R ][ C ] )continue;
		dfs( R , C );
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep( i , 0 , n )rep( j , 0 , m )cin >> maze[ i ][ j ];
	int retw = 0 , rets = 0;
	rep( i , 0 , n )rep( j , 0 , m )
	{
		out = false;
		if ( maze[ i ][ j ] != '#' && !vis[ i ][ j ] )
		{
			s = 0; w = 0;
			dfs( i , j );
			if ( !out )
				if ( s > w )rets += s;
				else retw += w;
		}
	}
	cout << rets << " " << retw << "\n";
	return 0;
}



