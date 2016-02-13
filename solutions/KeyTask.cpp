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

char maze[ 200 ][ 200 ];
int n , m;
set<ii> dests;
const int dx[] = { -1 , 0 , 1 , 0 } , dy[] = { 0 , 1 , 0 , -1 };
struct node
{
	int x , y , keys , steps;
	node( int _y = 0 , int _x = 0 , int m = 0 , int steps = 0 )
	{
		x = _x; y = _y; keys = m;
		this->steps = steps;
	}
};
node src , dest;
const string doors = "BYRG" , keys = "byrg";
int bfs()
{
	queue<node> q;
	bool vis[ 102 ][ 102 ][ 16 ] = { false };
	q.push( src );
	while ( !q.empty() )
	{
		node aux = q.front();
		q.pop();
		if ( dests.find( mp( aux.y , aux.x ) ) != dests.end() )
			return aux.steps;
		if ( vis[ aux.y ][ aux.x ][ aux.keys ] )continue;
		vis[ aux.y ][ aux.x ][ aux.keys ] = true;
		rep( i , 0 , 4 )
		{
			int Y = aux.y + dy[ i ] , X = aux.x + dx[ i ];
			if ( X < 0 || Y < 0 || X >= m || Y >= n || maze[ Y ][ X ] == '#' )
				continue;
			int pos;
			if ( ( pos = doors.find( maze[ Y ][ X ] ) ) != string::npos )
			{
				if ( aux.keys&( 1 << pos ) )
					q.push( node( Y , X , aux.keys , aux.steps + 1 ) );
			}
			else if ( ( pos = keys.find( maze[ Y ][ X ] ) ) != string::npos )
				q.push( node( Y , X , ( aux.keys | ( 1 << pos ) ) , aux.steps + 1 ) );
			else q.push( node( Y , X , aux.keys , aux.steps + 1 ) );
		}
	}
	return -1;
}


int main()
{
	while ( cin >> n >> m && n )
	{
		dests.clear();
		rep( i , 0 , n )rep( j , 0 , m ){
			cin >> maze[ i ][ j ];
			if ( maze[ i ][ j ] == '*' )src = node( i , j , 0 );
			if ( maze[ i ][ j ] == 'X' )dests.insert( mp( i , j ) );
		}
		int ret = bfs();
		if ( ret != -1 )
			cout << "Escape possible in " << ret << " steps.";
		else cout << "The poor student is trapped!";
		cout << "\n";

	}
	return 0;
}
