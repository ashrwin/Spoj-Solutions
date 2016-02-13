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

int change( string s , bool cfl )
{
	int ret = 0;
	if ( cfl )
	{
		if ( isupper( s[ 0 ] ) )
			s[ 0 ] = tolower( s[ 0 ] );
		else s[ 0 ] = toupper( s[ 0 ] );
		ret++;
	}
	for ( int i = 1; i < sz( s ); ++i )
		if ( isupper( s[ i ] ) && isupper( s[ i - 1 ] ) )
		{
		ret++;
		s[ i ] = tolower( s[ i ] );
		}
		else if ( islower( s[ i ] ) && islower( s[ i - 1 ] ) )
		{
			ret++;
			s[ i ] = toupper( s[ i ] );
		}

	return ret;
}

int main()
{
	ios::sync_with_stdio( false );
	string s;
	while ( cin >> s )
		cout << "\n" << min( change( s , false ) , change( s , true ) );

	return 0;
}