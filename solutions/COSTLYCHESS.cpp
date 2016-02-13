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
	int x , y , cost;
	bool operator<( const node &b )const
	{
		return b.cost < cost;
	}
	node( int x = 0 , int y = 0 , int cost = 0 )
	{
		this->x = x; this->y = y; this->cost = cost;
	}
};

node src , dest;
const int dx[] = { 2 , 1 , -1 , -2 , -2 , -1 , 1 , 2 };
const int dy[] = { 1 , 2 , 2 , 1 , -1 , -2 , -2 , -1 };
int dijk()
{
	bool vis[ 10 ][ 10 ] = { false };
	priority_queue<node> pq;
	pq.push( src );
	while ( !pq.empty() )
	{
		node aux = pq.top();
		pq.pop();
		if ( vis[ aux.x ][ aux.y ] )continue;
		if ( dest.x == aux.x&& dest.y == aux.y )return aux.cost;
		vis[ aux.x ][ aux.y ] = true;
		rep( i , 0 , 8 )
		{
			int X = aux.x + dx[ i ];
			int Y = aux.y + dy[ i ];
			if ( X < 0 || Y < 0 || X >= 8 || Y >= 8 )continue;
			int C = aux.cost + aux.x*X + aux.y*Y;
			pq.push( node( X , Y , C ) );
		}
	}
	return -1;
}

int main()
{
	int a , b , c , d;
	ios::sync_with_stdio( false );
	while ( cin >> a >> b >> c >> d )
	{
		src = node( a , b , 0 );
		dest = node( c , d , 0 );
		cout << dijk() << "\n";
	}
	return 0;
}
