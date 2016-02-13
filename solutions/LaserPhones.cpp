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
	int y , x , turns , dir;
	node( int yy = 0 , int xx = 0 , int t = 0 , int d = 0 )
	{
		y = yy; x = xx; turns = t; dir = d;
	}
	bool operator<( const node &x )const
	{
		return turns > x.turns;
	}
};
int w , h;
char m[ 102 ][ 102 ];
pair<ii , int> dxy[] = { mp( mp( -1 , 0 ) , 1 ) , mp( mp( 0 , 1 ) , 0 ) ,
mp( mp( 0 , -1 ) , 2 ) , mp( mp( 1 , 0 ) , 3 ) };
bool vis[ 102 ][ 102 ][ 4 ];

node src( -1 ) , dest;

int bfs()
{
	priority_queue<node> q;
	int ret = ( 1 << 30 );
	for ( pair<ii , int> p : dxy )
	{
		int Y = src.y + p.first.second , X = src.x + p.first.first;
		if ( Y < 0 || X < 0 || Y >= h || X >= w || m[ Y ][ X ] == 'C' || m[ Y ][ X ] == '*' )
			continue;
		q.push( node( Y , X , 0 , p.second ) );
	}
	rep( i , 0 , 4 )vis[ src.y ][ src.x ][ i ] = true;
	while ( !q.empty() )
	{
		node aux = q.top();
		q.pop();
	//	cout << "\n AUX :" << aux.y << "  " << aux.x << endl;
		if ( vis[ aux.y ][ aux.x ][ aux.dir ] )
			continue;
		vis[ aux.y ][ aux.x ][ aux.dir ] = true;
		//if ( aux.y==6 && aux.x==1 )cout << "\n AUX " << aux.y <<"  "<<aux.x<< endl;
		if ( aux.y == dest.y && aux.x == dest.x )
			ret = min( aux.turns , ret );
		for ( pair<ii , int> p : dxy )
		{
			int Y = aux.y + p.first.second , X = aux.x + p.first.first;
			if ( Y < 0 || X < 0 || Y >= h || X >= w || m[ Y ][ X ] == '*' )
				continue;
			int turns = ( aux.dir == p.second ) ? aux.turns : aux.turns + 1;
			q.push( node( Y , X , turns , p.second ) );
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> w >> h;
	rep( i , 0 , h )rep( j , 0 , w ){
		cin >> m[ i ][ j ];
		if ( m[ i ][ j ] == 'C' )
		{
			if ( src.y == -1 )
				src = node( i , j , 0 , 0 );
			else dest = node( i , j , 0 , 0 );
		}
	}
	cout << bfs() << "\n";
	return 0;
}

