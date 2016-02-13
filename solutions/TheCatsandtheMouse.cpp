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
//#include<tr1/unordered_set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanint(a) 
#define gc getchar
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

void scanint( int &x )
{
	register int c = gc();
	x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
}

const int SIZE = 101;
int mdist[ 101 ][ 101 ];
int cdist[ 101 ][ 101 ];
bool visited[ 101 ][ 101 ];
const int dx[] = { -1 , 0 , 1 , 0 };
const int dy[] = { 0 , 1 , 0 , -1 };
int N , M;
struct point
{
	int x , y;
	point( int x = 0 , int y = 0 )
	{
		this->x = x; this->y = y;
	}
};

void bfs( const vector<point> &s , int dist[ 101 ][ 101 ] )
{

	rep( i , 0 , SIZE )rep( j , 0 , SIZE ) dist[ i ][ j ] = 1000000;
	queue<point> q;
	rep( i , 0 , sz( s ) )
	{
		dist[ s[ i ].y ][ s[ i ].x ] = 0;
		dist[ s[ i ].y ][ s[ i ].x ] = 0;
		q.push( s[ i ] );
	}
	while ( !q.empty() )
	{
		point u = q.front();
		q.pop();
		//adj
		for ( int i = 0; i < 4; ++i )
		{
			int x = u.x + dx[ i ];
			int y = u.y + dy[ i ];
			point v = point( x , y );
			if ( y >= 0 && x >= 0 && x < M && y < N && dist[ v.y ][ v.x ] > dist[ u.y ][ u.x ] + 1 )
			{
				dist[ v.y ][ v.x ] = dist[ u.y ][ u.x ] + 1;
				q.push( v );
			}
		}
	}
}


string escape()
{
	rep( i , 0 , N )
		if ( mdist[ i ][ 0 ] < cdist[ i ][ 0 ] || mdist[ i ][ M - 1 ] < cdist[ i ][ M - 1 ] )
			return "YES";
	rep( i , 0 , M )
		if ( mdist[ 0 ][ i ] < cdist[ 0 ][ i ] || mdist[ N - 1 ][ i ] < cdist[ N - 1 ][ i ] )
			return "YES";
	return "NO";
}


int main()
{
	ios::sync_with_stdio( false );
	cin >> N >> M;
	int k;
	cin >> k;
	till( k )
	{
		point m , c1 , c2;
		cin >> m.y >> m.x >> c1.y >> c1.x >> c2.y >> c2.x;
		m.y -= 1; m.x -= 1; c1.y -= 1; c1.x -= 1; c2.y -= 1; c2.x -= 1;
		vector<point> S;
		S.push_back( m );
		bfs( S , mdist );
		S.clear();
		S.push_back( c1 ); S.push_back( c2 );
		bfs( S , cdist );
		cout << escape() << "\n";
	}
	return 0;
}