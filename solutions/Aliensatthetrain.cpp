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
#include <ctime>
#include<string.h>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<assert.h>
//#include<unordered_map>
//#include<tr1/unordered_set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar_unlocked
#define MAX 10000
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
inline int scanint()
{
	register int c = gc();
	register int x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	return x;
}

inline const ii &amax( const ii &a , const ii &b )
{
	if ( a.first>b.first )
		return a;
	else if ( a.first < b.first )
		return b;
	else if ( a.second < b.second ) return a;
	else return b;

}
int v[ 100002 ];
int n;
ii alien(  int lim )
{
	ii ret = mp( -1 , 10000001 );
	queue<int> q;
	int sum = 0 , c = 0;
	rep( i , 0 , n )
	{
		sum += v[ i ];
		++c;
		q.push( v[ i ] );
		while ( sum > lim )
		{
			sum -= q.front();
			--c;
			q.pop();
		}
		ret = amax( ret , mp( c , sum ) );
	}
	return ret;
}

int main()
{
	int t;
	t = SI;
	till( t )
	{
		n = SI;
		int lim = SI;
		rep( i , 0 , n )v[ i ] = SI;
		ii ans = alien( lim );
		printf( "%d %d\n" , ans.second,ans.first );
	}


	return 0;
}