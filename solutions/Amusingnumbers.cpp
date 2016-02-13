#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
#define mp make_pair
#define pb push_back
#define MAX (1<<30)
using namespace std;
typedef pair<int , int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;


string anum( ull x )
{
	int n = (int)log2( x + 1 );
	string ret( n , '5' );
	ull p = x- (pow( 2 , n  )-1) ;
	int pos = n - 1;
	while ( p )
	{
		if ( p & 1 )
			ret[ pos ] = '6';
		p >>= 1;
		--pos;
	}
	return ret;
}



int main()
{
	ios::sync_with_stdio( false );
	int t;
	ull n;
	cin >> t;
	while ( t-- )
	{
		cin >> n;
		cout << "\n" << anum( n );
	}
	
}