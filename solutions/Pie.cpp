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
#define sf(a) scanf("%d",&a) 
#define gc getchar_unlocked
#define MAX 10000000
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


long double pie[ 100000 ];
int N , F;
bool pred( long double val )
{
	int alloc = 0 ;
	for ( int i = 0; i < N; ++i )
	{
		alloc += (int)floor( pie[ i ] / val );
		if ( alloc >= F ) return true;
	}
	return ( alloc >= F );

}
long double binSearch( long double hi )
{
	long double lo = 0 ;// hi = pie[ N - 1 ];
	long double ret = 0;
	while ( hi - lo >= 1e-6 )
	{
		long double mid = ( lo + hi ) / 2.0;
		if ( pred( mid ) )
		{
			ret = mid;
			lo = mid + 0.00001;
		}
		else hi = mid - 0.00001;
	}
	return ret;
}


int main()
{
	int t;
	sf( t );
	till( t )
	{
		sf( N ); sf( F );
		++F;
		int temp;
		long double hi = 0;
		rep( i , 0 , N )
		{
			sf( temp );
			pie[ i ] = pi*temp*temp;
			hi = max( hi , pie[ i ] );
		}
		printf( "%.4Lf\n" , binSearch( hi ) );
	}
	return 0;
}