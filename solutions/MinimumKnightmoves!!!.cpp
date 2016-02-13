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

struct cell
{
	int x , y , dist;
	cell( int x = 0 , int y = 0 , int dist = 0 )
	{
		this->x = x; this->y = y; this->dist = dist;
	}
};

cell source , dest;
const int dx[] = { -2 , -2 , 2 , 2 , -1 , -1 , 1 , 1 };
const int dy[] = { 1 , -1 , 1 , -1 , 2 , -2 , 2 , -2 };
int bfs()
{
	queue<cell> q;
	bool vis[ 10 ][ 10 ] = { 0 };
	q.push( source );
	while ( !q.empty() )
	{
		cell aux = q.front();
		q.pop();
		if ( vis[ aux.x ][ aux.y ] )continue;
		if ( aux.x == dest.x && aux.y == dest.y )return aux.dist;
		vis[ aux.x ][ aux.y ] = true;
		//adj
		rep( i , 0 , 8 )
		{
			int X = aux.x + dx[ i ] , Y = aux.y + dy[ i ];
			if ( X < 1 || Y < 1 || X>8 || Y>8 )continue;
			q.push( cell( X , Y , aux.dist + 1 ) );
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio( false );
	int z;
	cin >> z;
	till( z )
	{
		string a , b;
		cin >> a >> b;
		source = cell( a[ 0 ] - 'a' + 1 , a[ 1 ] - '0' , 0 );
		dest = cell( b[ 0 ] - 'a' + 1 , b[ 1 ] - '0' , 0 );
		cout << bfs() << "\n";
	}

	return 0;
}