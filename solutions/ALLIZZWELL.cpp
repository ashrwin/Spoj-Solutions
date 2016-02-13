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

int n , m;
char maze[ 105 ][ 105 ];
bool vis[ 105 ][ 105 ];
const string pat = "ALLIZZWELL";
bool dfs( int r , int c , int pos )
{
	vis[ r ][ c ] = true;
	if ( pos == sz( pat ) && maze[ r ][ c ] == 'L' )
		return true;
	rep( dx , -1 , 2 )rep( dy , -1 , 2 )
	{
		int R = r + dy , C = c + dx;
		if ( R < 0 || C < 0 || R >= n || C >= m || vis[ R ][ C ] || maze[ R ][ C ] != pat[ pos ] )
			continue;
		if ( dfs( R , C , pos + 1 ) )
			return true;
		else vis[ R ][ C ] = false;
	}
	return false;
}

int main()
{
ios::sync_with_stdio(false);	
	int t;
	cin >> t;
	till( t )
	{
		cin >> n >> m;
		rep( i , 0 , n )rep( j , 0 , m )
			cin >> maze[ i ][ j ];
		bool flag = false;
		rep( i , 0 , n )rep( j , 0 , m )
			if ( maze[ i ][ j ] == 'A' )
			{
			flag = false;
			memset( vis , 0 , sizeof vis );
			if ( dfs( i , j , 1 ) )
			{
				flag = true; i = n + 1; break;
			}
			}
		if ( flag )cout << "YES";
		else cout << "NO";
		cout << "\n";
	}
	return 0;
}


