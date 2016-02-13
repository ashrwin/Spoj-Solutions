#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i=a ; i < (int)n ; i++)
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
#define sz(v)  int(v.size())
#define sort(v) sort(all(v))

int N = sqrt(1000000000);
vi sprimes;

void init()
{
	
	vector<bool> seive( N + 1 , true );
	for ( int i = 2; i <= N ; ++i )
	{
		if ( seive[ i ] )
		{
			sprimes.push_back( i );
			int j = i + i;
			while ( j <= N )
			{
				seive[ j ] = false;
				j += i;
			}
		}
	}
}


void printPrimes( long a , long b )
{
	vector<bool> isprime( b - a + 1 , true );
	
	for ( int i = 0 ; i < sprimes.size(); i++ )
	{
		int cprime = sprimes[ i ];
		int cross = ceil( ( a*1.0 ) / cprime ) * cprime ;
		if ( cross == cprime ) cross += cprime;
		while ( cross <= b )
		{
			isprime[ cross-a ] = false;
			cross += cprime;
		}
		
	}
	for ( int i = 0 ; i < isprime.size() ; ++i )
		if ( isprime[ i ] && i+a>1 )
			cout << "\n " << i+a;
	cout << endl;
}






int main()
{
	int n;
	long a ,b;
	init();
	cin >> n;
	rep( i , 0 , n )
	{
		cin >> a >> b ;
		printPrimes( a , b );
	}

	return 0;
}


