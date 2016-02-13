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

struct node
{
	int pos , toll , time;
	bool operator<( const node &a )const
	{
		if ( a.toll == toll && a.time == time )return pos < a.pos;
		if ( a.toll == toll )return time < a.time;
		return toll < a.toll;
	}
	node( int pos , int toll , int time )
	{
		this->pos = pos; this->toll = toll; this->time = time;
	}
};

int t , n;
int tim[ 52 ][ 52 ] , toll[ 52 ][ 52 ];
ii dijkstra()
{
	bool vis[ 55 ][ 2001 ] = { false };
	set<node> pq;
	memset( vis , 0 , sizeof( vis ) );
	pq.insert( node( 0 , 0 , 0 ) );
	while ( !pq.empty() )
	{
		node aux = *pq.begin();
		pq.erase( pq.begin() );
		if ( aux.pos == n - 1 )return mp( aux.toll , aux.time );
		if ( vis[ aux.pos ][ aux.time ] )continue;
		vis[ aux.pos ][ aux.time ] = true;
		//adj
		for ( int j = 0; j < n; ++j )
		{
			int pos2 = j;
			int toll2 = toll[ aux.pos ][ j ] + aux.toll;
			int time2 = tim[ aux.pos ][ j ] + aux.time;
			if ( time2 <= t )pq.insert( node( pos2 , toll2 , time2 ) );
		}
	}
	return mp( -1 , -1 );
}


int main()
{
	ios::sync_with_stdio( false );
	while ( cin >> n >> t && n )
	{
		rep( i , 0 , n )rep( j , 0 , n ) cin >> tim[ i ][ j ];
		rep( i , 0 , n )rep( j , 0 , n ) cin >> toll[ i ][ j ];
		ii ans = dijkstra();
		cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}