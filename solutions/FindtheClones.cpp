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

int main()
{
	ios::sync_with_stdio( false );
	int n , m;
	while ( true )
	{
		cin >>n >> m;
		if ( !n && !m ) return 0;
		map<string , int> m1;
		string k;
		rep( i , 0 , n )
		{
			cin >> k;
			m1[ k ]++;
		}
		int m2[ 21001 ] = { 0 };
		for ( map<string , int>::iterator it = m1.begin(); it != m1.end(); ++it )
			m2[ it->second ]++;
		rep( i , 1 , n + 1 )
			cout << "\n" << m2[ i ];
	}
	return 0;
}