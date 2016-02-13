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
	//ios::sync_with_stdio( false );
	int n;
	sf( n );
	till( n )
	{
		int x;
		sf( x );
		if ( x & 1 )
			printf( "\n%d" , x );
		else
		{
			int lpos = (int)log2( x );
			int ret = 0;
			while ( lpos >= 0 )
			{
				ret += (int)pow( 2 , lpos )*( x & 1 );
				x >>= 1;
				--lpos;
			}
			printf( "\n%d" , ret );
		}
	}
	return 0;
}