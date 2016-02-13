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

int w , h;
char maze[ 25 ][ 25 ];
map<ii , int> imap;
int fdist[ 25 ][ 25 ];
const int dx[] = { -1 , 0 , 1 , 0 };
const int dy[] = { 0 , 1 , 0 , -1 };
bool bfs( ii s )
{
	int ret = 0;
	bool vis[ 25 ][ 25 ] = { false };
	int dist[ 25 ][ 25 ] = { 0 };
	dist[ s.first ][ s.second ] = 0;
	queue<ii> q;
	q.push( s );
	while ( !q.empty() )
	{
		ii aux = q.front();
		q.pop();
		if ( vis[ aux.first ][ aux.second ] )continue;
		if ( maze[ aux.first ][ aux.second ] == '*' || ( maze[ aux.first ][ aux.second ] == 'o' ) )
			fdist[ imap[ s ] ][ imap[ aux ] ] = dist[ aux.first ][ aux.second ],++ret;
		vis[ aux.first ][ aux.second ] = true;
		rep( i , 0 , 4 )
		{
			int Y = aux.first + dy[ i ];
			int X = aux.second + dx[ i ];
			if ( X < 0 || Y < 0 || X >= w || Y >= h || maze[ Y ][ X ] == 'x' )continue;
			dist[ Y ][ X ] = dist[ aux.first ][ aux.second ] + 1;
			q.push( mp( Y , X ) );
		}

	}
	return ret == sz( imap );
}
int main()
{
	while ( cin >> w >> h && w )
	{
		int ind = 1;
		imap.clear();
		rep( i , 0 , h )rep( j , 0 , w ){
			cin >> maze[ i ][ j ];
			if ( maze[ i ][ j ] == 'o' )
				imap[ mp( i , j ) ] = 0;
			else if ( maze[ i ][ j ] == '*' )
				imap[ mp( i , j ) ] = ind++;
			fdist[ i ][ j ] = ( 1 << 30 );
		}
		bool flag = true;
		for ( pair<ii , int> p : imap )
			if ( !bfs( p.first ) )
			{
			flag = false; break;
			}
		if ( !flag ){
			cout << "-1\n"; continue;
		}
		vi perm( sz( imap ) );
		rep( i , 0 , sz( perm ) )perm[ i ] = i ;
		int ret = ( 1 << 25 ) , tmp = 0;
		do
		{
			tmp = 0;
			rep( i , 1 , sz( perm ) )
				tmp += fdist[ perm[ i - 1 ] ][ perm[ i ] ];
			ret = min( ret , tmp );
		} while ( next_permutation( perm.begin() + 1 , perm.end() ) ) ;
		cout << ret << "\n";
	}
	return 0;
}