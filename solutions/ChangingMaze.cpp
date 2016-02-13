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

struct node
{
	int x , y , dist , time;
	bool operator<( const node &b )const
	{
		return b.dist < dist;
	}
	node( int y = 0 , int x = 0 , int dist = 0 , int time = 0 )
	{
		this->x = x; this->y = y; this->dist = dist; this->time = time;
	}
};

node src , dest;
const int dx[] = { -1 , 0 , 1 , 0 , 0 };
const int dy[] = { 0 , 1 , 0 , -1 , 0 };
char maze[ 22 ][ 22 ][ 12 ];
int n , m , t;
int dijk()
{
	bool vis[ 22 ][ 22 ][ 12 ] = { false };
	priority_queue<node> pq;
	pq.push( src );
	while ( !pq.empty() )
	{
		node aux = pq.top();
		pq.pop();
		if ( vis[ aux.x ][ aux.y ][ aux.time ] )continue;
		if ( dest.x == aux.x&& dest.y == aux.y )return aux.dist;
		vis[ aux.x ][ aux.y ][ aux.time ] = true;
		rep( i , 0 , 5 )
		{
			int X = aux.x + dx[ i ];
			int Y = aux.y + dy[ i ];
			int T = ( aux.time + 1 ) % t;
			if ( X < 0 || Y < 0 || X >= m || Y >= n || maze[ Y ][ X ][ T ] == '1' )continue;
			int C = aux.dist + 1;
			pq.push( node( Y , X , C , T ) );
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio( false );
	int Z = 0;
	while ( true )
	{
		++Z;
		cin >> n >> m >> t;
		if ( !n )break;
		src = node( 0 , 0 , 0 );
		dest = node( n - 1 , m - 1 , 0 );
		rep( k , 0 , t )rep( i , 0 , n )rep( j , 0 , m )cin >> maze[ i ][ j ][ k ];
		int ret = dijk();
		if ( ret == -1 )
			cout << "Case " << Z << ": Luke and Leia cannot escape.";
		else cout << "Case " << Z << ": Luke and Leia can escape in " << ret << " steps.";
		cout << "\n";
	}
	return 0;
}
