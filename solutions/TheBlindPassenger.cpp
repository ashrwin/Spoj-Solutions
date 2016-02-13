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
#define MAX 10000000
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
string blind( ll x )
{
	stringstream ss;
	if ( x == 1 )
		return "poor conductor";
	int row = (int)ceil( ( x - 1 ) / 5.0 );
	ss << row << " ";
	x = x - 5 * ( row - 1 );
	if ( ( row % 2 ) == 0 )
	{
		if ( x == 2 || x == 6 )
			ss << "W" << " ";
		else if ( x == 4 || x==5 )
			ss << "A" << " ";
		else ss << "M" << " ";
		if ( x < 5 ) ss << "R";
		else ss << "L";
	}
	else
	{
		if ( x == 2 || x == 6 )
			ss << "W" << " ";
		else if ( x == 3 || x == 4 )
			ss << "A" << " ";
		else ss << "M" << " ";
		if ( x < 4 ) ss << "L";
		else ss << "R";
	}
	return ss.str();
}

int main()
{
	int t;
	sf( t );
	till( t )
	{
		ll s;
		scanf( "%lld" , &s );
		printf( "\n%s" , blind( s ).c_str() );
	}
	return 0;
}