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
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

char getChild( ull n , ull k )
{
	if ( n == 0 || k == 0 )
		return 'M';
	char parent = getChild( n - 1 , k>>1 );
	if ( (k % 2)==0 )//lc
		return parent;
	else if ( parent == 'M' )
			return 'F';
	else return 'M';
	
}


int main()
{
	int t;
	sf( t );
	till( t )
	{
		ull n , k;
		cin >> n >> k;
		if ( getChild( n-1 , k-1 ) == 'M' )
			printf( "\nMale" );
		else printf( "\nFemale" );
	}

	return 0;
}