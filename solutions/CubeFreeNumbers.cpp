#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef long long ll;
#define MAX 1000001

int A[ MAX ] = { 0 };
void seive()
{
	int i , k , j;
	for ( i = 2; i <= 100; i++ )
	{
		if ( A[ i ] == 0 )
		{
			k = i*i*i;
			for ( j = k; j <= 1000000; j += k )
				A[ j ] = -1;
		}
	}
	k = 1;
	for ( i = 1; i <= 1000000; i++ )
		if ( A[ i ] == 0 )
			A[ i ] = k++;
}



int main()
{
	seive();
	int t , n;
	scanf( "%d" , &t );
	for ( int i = 1; i <= t; i++ )
	{
		scanf( "%d" , &n );
		if ( A[ n ] != -1 )
			printf( "Case %d: %d\n" , i , A[ n ] );
		else
			printf( "Case %d: Not Cube Free\n" , i );
	}
}