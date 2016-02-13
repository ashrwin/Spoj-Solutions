#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define mp make_pair
using namespace std;
typedef unsigned long long ull;
typedef pair<int , int> ii;
int hall( set<int> &in , set<int> &out )
{
	int ret = 0,c=0;
	for ( set<int>::iterator it = in.begin(); it != in.end(); ++it )
	{
		c++;
		while ( !out.empty() && *out.begin() <= *it )
		{
			c--;
			out.erase( out.begin() );
		}
		ret = max( ret , c );
	}

	return ret;

}

int main()
{
	
	int t;
	scanf( "%d" , &t );
	while ( t-- )
	{
		int n;
		scanf( "%d" , &n );
		set<int> in , out;
		while ( n-- )
		{
			int x , y;
			scanf( "%d%d" , &x,&y );
			in.insert( x );
			out.insert( y );
		}
		printf( "\n%d" , hall(in,out) );
	}
	return 0;
}