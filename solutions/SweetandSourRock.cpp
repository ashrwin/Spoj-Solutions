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
int memo[ 1000 ];
int dp( const string &s , int x )
{
	int &ret = memo[ x ];
	if ( ret != -1 )
		return ret;
	if ( x >= sz(s) )return 0;
	if ( x == sz(s) - 1 )
		return (s[ x ] == '1') ? 1 : 0;
	int sweet = 0 , sour = 0;
	ret = -1;
	for ( int i = x; i < sz( s ); ++i )
	{
		if ( s[ i ] == '0' )
			sour++;
		else if ( s[ i ] == '1' )
			sweet++;
		int to = ( sweet>sour ) ? (sweet + sour)  : 0;
		ret = max( ret , dp( s , i+1 )+to );
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
		string rock;
		cin >> rock;
		memset( memo , -1 , 1000 );
		printf( "\n%d" , dp( rock , 0 ) );
	}
	return 0;
}