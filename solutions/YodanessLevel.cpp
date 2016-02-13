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
#include<tr1/unordered_map>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define sf scanInt 
#define gc getchar
#define MAX 10000000
using namespace std;
using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
int bit[ 30001 ];
int arr[ 30001 ];
int n;
inline void update( int ind , int val )
{
	for ( int i = ind; i <= n; i += ( i&-i ) )
		bit[ i ] += val;
}

inline int read( int ind )
{
	int ret = 0;
	for ( int i = ind; i > 0; i -= ( i&-i ) )
		ret += bit[ i ];
	return ret;
}

unordered_map<string , int> m;
int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		m.clear();
		cin >> n;
		string t;
		rep( i , 0 , 30001 ){ bit[ i ] = 0; arr[ i ] = 0; }
		rep( i , 0 , n )
		{
			cin >> t;
			m[ t ] = i;
		}
		rep( i , 0 , n )
		{
			cin >> t;
			arr[ i+1 ] = m[ t ]+1;
		}
		int ret = 0;
		for ( int i = n; i >= 1; --i )
		{
			ret += read( arr[ i ] );
			update( arr[ i ] , 1 );
		}
		cout << "\n"<<ret;
	}
	return 0;
}