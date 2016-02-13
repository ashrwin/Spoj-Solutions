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
//#include<tr1/unordered_set>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=(a) ; i < (int)(n) ; i++)
#define sz(v) int(v.size())
#define mp make_pair
#define till(a) while(a--)
#define SI scanint() 
#define gc getchar
#define MAX 10000
#define pi 3.14159265358979323846264338327950
using namespace std;
//using namespace tr1;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
inline int scanint()
{
	register int c = gc();
	register int x = 0;
	for ( ; ( c < 48 || c>57 ); c = gc() );
	for ( ; c > 47 && c < 58; c = gc() ) { x = ( x << 1 ) + ( x << 3 ) + c - 48; }
	return x;
}
vector<int> v;

void generateSubsets( int start , int num , vector<int>& vect )
{
	int sum;
	for ( int mask = 0; mask < ( 1 << num ); mask++ )
	{
		sum = 0;
		for ( int item = 0; item < num; item++ )
			if ( mask & ( 1 << item ) )
				sum += v[ item + start ];
		vect.push_back( sum );
	}
}
int main()
{
	ios::sync_with_stdio( false );
	int n;
	int a , b;
	cin >> n >> a >> b;
	v = vi( n );
	rep( i , 0 , n )cin >> v[ i ];
	vi left , right;
	generateSubsets( 0 , n / 2 , left );
	generateSubsets( n / 2 , ( n & 1 ) ? n / 2 + 1 : n / 2 , right );
	sort( all( right ) );
	ull ans = 0;
	vector<int>::iterator low , high;
	for ( int i = 0; i < left.size(); i++ )
	{
		low = lower_bound( right.begin() , right.end() , a - left[ i ] );
		high = upper_bound( right.begin() , right.end() , b - left[ i ] );
		ans += ( high - right.begin() ) - ( low - right.begin() );
	}
	cout << "\n" << ans;
	return 0;
}