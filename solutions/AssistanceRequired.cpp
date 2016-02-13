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
#define MAX 35000
using namespace std;
typedef pair<int , int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;


int primemap[ MAX ] = { 0 };

void seive()
{
	int pos = 0;
	bool p[ MAX ] = { false };
	for ( int i = 2; i < MAX; ++i )
		p[ i ] = true;
	for ( int i = 2; i < MAX ; ++i )
	{
		if ( p[ i ] )
		{
			primemap[ pos++ ] = i;
			int mark = i;
			for ( int j = i + 1 , k = 0; j < MAX; j++ )
			{
				if ( !p[ j ] ) continue;
				else k++;
				if ( k == mark )
				{
					p[ j ] = false;
					k = 0;
				}
			}
		}
	}
}

int main()
{
	seive();
	ios::sync_with_stdio( false );
	int n;
	while ( cin >> n && n )
	{
		cout << "\n" << primemap[ n - 1 ];
	}
	
}