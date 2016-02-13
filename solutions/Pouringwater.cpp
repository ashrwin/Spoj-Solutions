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
	int a , b , steps;
	node( int a = 0 , int b = 0 , int steps = 0 )
	{
		this->a = a; this->b = b; this->steps = steps;
	}
};
node source;
int dest;
int bfs()
{
	queue<node> q;
	q.push( node() );
	set<ii> vis;
	while ( !q.empty() )
	{
		node aux = q.front();
		q.pop();
		if ( aux.a == dest || aux.b == dest )return aux.steps;
		if ( vis.find( mp( aux.a , aux.b ) ) != vis.end() )continue;
		vis.insert( mp( aux.a , aux.b ) );
		q.push( node( 0 , aux.b , aux.steps + 1 ) );
		q.push( node( aux.a , 0 , aux.steps + 1 ) );
		q.push( node( source.a , aux.b , aux.steps + 1 ) );
		q.push( node( aux.a , source.b , aux.steps + 1 ) );
		node t1;
		t1.b = min( aux.b + aux.a , source.b );
		t1.a = max( 0 , aux.a - ( t1.b - aux.b ) );
		t1.steps = aux.steps + 1;
		q.push( t1 );
		t1.a = min( aux.a + aux.b , source.a );
		t1.b = max( 0 , aux.b - ( t1.a - aux.a ) );
		t1.steps = aux.steps + 1;
		q.push( t1 );
	}
	return -1;
}

int main()
{
	int t;
	scanf( "%d" , &t );
	till( t )
	{
		int a , b ;
		scanf( "%d%d%d" , &a,&b,&dest );
		source = node( a , b );
		printf( "%d\n" , bfs() );
	}
	return 0;
}