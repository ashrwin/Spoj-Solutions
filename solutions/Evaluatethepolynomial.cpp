#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define MAX (1<<30)
using namespace std;
typedef pair<int , int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int eval( const vi &v , const int &n , const int &x )
{
	int ret = 0;
	int xf = 1;
	for ( int i = n; i>=0; --i )
	{
		ret += ( v[ i ] * xf );
		xf *= x;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio( false );
	int n , k;
	int z = 1;
	while ( cin >> n && n != -1 )
	{
		vi co( n + 1 );
		for ( int i = 0; i <= n; ++i )
			cin >> co[ i ];
		cin >> k;
		cout << "\nCase "<<z<<":";
		++z;
		while ( k-- )
		{
			int x;
			cin >> x;
			cout << "\n" << eval( co , n ,x);
		}
	}


	return 0;
}