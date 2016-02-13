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
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf scanInt 
#define gc getchar_unlocked
#define MAX 10000000
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

int sum[ 30 ];
string s;
int dp( int x , int prevsum )
{
	if ( x == sz( s ) )
		return 1;
	int ret = 0 , sum=0;
	for ( int i = x ; i < sz( s ); ++i )
	{
		sum += ( s[ i ] - '0' );
		if ( sum >= prevsum )
			ret += dp( i + 1 , sum );
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio( false );
	int Z = 0;
	while ( true )
	{
		cin >> s;
		if ( s == "bye" )return 0;
		++Z;
		int sumt = 0;
		cout << "\n"<<Z<<". " << dp( 0 , 0 ) ;
	}

	return 0;
}