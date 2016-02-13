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
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf(a) scanf("%d",&a) 
#define gc getchar
#define MAX 4000
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

inline int busy( const set<ii> &s )
{
	int ret = 0;
	int prev = -1;
	for ( set<ii>::const_iterator it = s.begin(); it != s.end(); ++it )
		if ( it->second >= prev )
		{
			ret++;
			prev = it->first;
		}
	return ret;
}


int main()
{
	//ios::sync_with_stdio( false );
	int t;
	sf( t );
	till( t )
	{
		int n;
		sf( n );
		set<ii> s;
		till( n )
		{
			int st , end;
			sf( st ); sf( end );
			s.insert( mp( end , st) );
		}
		printf( "\n%d" , busy( s ) );
	}
	return 0;
}