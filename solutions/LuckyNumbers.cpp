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
	int n;
	ii c;
	node( int n , ii c  )
	{
		this->n = n; this->c = c;
	}
};

node bfs( int x )
{
	queue<node> q;
	q.push( node( 6 % x , mp( 1 , 0 ) ) );
	q.push( node( 8 % x , mp( 0 , 1 )  ) ) ;
	bool vis[ 11500 ] = { 0 };
	while ( !q.empty() )
	{
		node aux = q.front();
		q.pop();
		if ( aux.n == 0 )return aux;
		int X = aux.c.first , Y = aux.c.second;
		if ( aux.c.first + aux.c.second > 200 )
			break;
		//if ( vis[ aux.n ] )continue;
		vis[ aux.n ] = true;
		if ( X )
			q.push( node( ( aux.n * 10 + 6 ) % x , mp( aux.c.first + 1 , aux.c.second )  ) );
		else
		{
			q.push( node( ( aux.n * 10 + 6 ) % x , mp( aux.c.first + 1 , aux.c.second )  ) );
			q.push( node( ( aux.n * 10 + 8 ) % x , mp( aux.c.first , aux.c.second + 1 )  ) );
		}
	}
	return node( 0 , mp( -1 , -1 ) );
}
int main()
{
	int t;
	cin >> t;
	till( t )
	{
		int x;
		cin >> x;
		node ret = bfs( x );
		rep( i , 0 , ret.c.second )cout << '8';
		rep( i , 0 , ret.c.first )cout << '6';
		if ( ret.c.first + ret.c.second == -2 )cout << "-1";
		cout << "\n";
	}
	return 0;
}