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

char maze[ 275 ][ 275 ];
int n , m;
bool vis[ 275 ][ 275 ];
const int dx[] = { -1 , 0 , 1 , 0 } , dy[] = { 0 , 1 , 0 , -1 };
int dfs( int r , int c )
{
	int ret = 1;
	vis[ r ][ c ] = true;
	rep( i , 0 , 4 )
	{
		int R = r + dy[ i ] , C = c + dx[ i ];
		if ( R < 0 || C < 0 || R >= n || C >= n || vis[ R ][ C ] || maze[ R ][ C ] == '0' )
			continue;
		ret += dfs( R , C );
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio( false );
	while ( cin >> n >> m && n )
	{
		memset( vis , 0 , sizeof( vis ) );
		rep( i , 0 , n )rep( j , 0 , m )cin >> maze[ i ][ j ];
		map<int , int> sol;
		int nslick = 0;
		rep( i , 0 , n )rep( j , 0 , m )
			if ( maze[ i ][ j ] == '1' && !vis[ i ][ j ] )
				sol[ dfs( i , j ) ]++,++nslick;
		cout << nslick << "\n";
		for ( ii p : sol )
			cout << p.first << " " << p.second << "\n";
	}
	return 0;
}
