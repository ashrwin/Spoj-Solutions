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
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int main()
{
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	till( t )
	{
		set<string> win , los;
		set<string>::iterator it;
		string a , b;
		int x , y;
		rep( i , 0 , 16 )
		{
			cin >> a >> b >> x >> y;
			if ( x > y )
			{
				if ( los.find( a ) == los.end() )
					win.insert( a );
				los.insert( b );
				if ( ( it = win.find( b ) ) != win.end() )
					win.erase( it );

			}
			else
			{
				if ( los.find( b ) == los.end() )
					win.insert( b );
				los.insert( a );
				if ( ( it = win.find( a ) ) != win.end() )
					win.erase( it );
			}
		}
		cout << "\n"<<*win.begin();
	}
	return 0;
}