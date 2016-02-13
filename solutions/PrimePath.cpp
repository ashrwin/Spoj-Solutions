/**/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
bool check[ 10009 ];
void sieve()
{
	for ( int i = 2; i <= 100; i++ )
		if ( !check[ i ] )
			for ( int j = i*i; j <= 10000; j += i )
				check[ j ] = true;
}

int conv_number( int a[] )
{
	int temp = 0 , k = 0;
	while ( k<4 ){
		temp = temp * 10 + a[ k ];
		k++;
	}
	return temp;
}
void arr1( int a[] , int num )
{
	int w = 3;
	while ( num )
	{
		a[ w-- ] = num % 10;
		num /= 10;
	}
}

int bfs( const int &s , const int &d )
{
	queue<int> q;
	int dist[ 10002 ] = { false };
	memset( dist , -1 , sizeof( dist ) );
	q.push( s );
	bool found = false;
	dist[ s ] = 0;
	while ( !q.empty() )
	{
		int c = q.front();
		q.pop();
		int digit[ 4 ];
		for ( int k = 3; k >= 0; k-- )
		{
			arr1( digit , c );
			for ( int i = 0; i <= 9; i++ )
			{
				digit[ k ] = i;
				int temp = conv_number( digit );
				if ( !check[ temp ] && temp >= 1000 && dist[ temp ]==-1 )
				{
					dist[ temp ] =  dist[ c ] + 1;
					q.push( temp );
					if ( temp == d ) found = true;
				}
			}
				
		}
		if ( found )break;
	}
	return dist[ d ];
}






int main()
{
	sieve();
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	while ( t-- )
	{
		int x , y;
		cin >> x >> y;
		int sol = bfs( x , y );
		if ( sol == -1 ) cout << "\nImpossible.";
		else cout << "\n" << sol;
	}
	return 0;
}





