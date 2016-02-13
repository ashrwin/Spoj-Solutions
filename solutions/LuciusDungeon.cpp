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

struct room
{
	int x , y , time;
	bool operator<( const room &a )const
	{
		if ( a.time == time && a.x == x )return y < a.y;
		if ( a.time == time )return x < a.x;
		return time < a.time;
	}
	room( int x , int y , int time )
	{
		this->x = x; this->y = y; this->time = time;
	}
};

int m , n , a , b , t;
int tim[ 112 ][ 112 ];
const int dx[] = { -1 , 0 , 1 , 0 };
const int dy[] = { 0 , 1 , 0 , -1 };
int dijkstra()
{
	bool vis[ 112 ][ 112 ] = { false };
	set<room> pq;
	memset( vis , 0 , sizeof( vis ) );
	pq.insert( room( 0 , 0 , tim[ 0 ][ 0 ] ) );
	while ( !pq.empty() )
	{
		room aux = *pq.begin();
		pq.erase( pq.begin() );
		if ( aux.x == b && aux.y == a )return aux.time;
		if ( vis[ aux.x ][ aux.y ] )continue;
		vis[ aux.x ][ aux.y ] = true;
		//adj
		rep( i , 0 , 4 )
		{
			int X = aux.x + dx[ i ] , Y = aux.y + dy[ i ];
			if ( X < 0 || Y < 0 || X >= n || Y >= m )continue;
			int time2 = aux.time + tim[ Y ][ X ];
			if ( time2 <= t )
				pq.insert( room( X , Y , time2 ) );
		}
	}
	return -1;
}


int main()
{
	ios::sync_with_stdio( false );
	int z;
	cin >> z;
	till( z )
	{
		cin >> m >> n;
		rep( i , 0 , m )rep( j , 0 , n ) cin >> tim[ i ][ j ];
		cin >> a >> b >> t;
		--a , --b;
		int ans = dijkstra();
		if ( ans != -1 )
			cout << "YES\n" << t - ans ;
		else cout << "NO";
		cout << "\n";
	}

	return 0;
}