#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef unsigned long long ull;
typedef vector< vector<int> > vvi;
vvi v;

int bfs( const vvi &v , const int &start , int &len , bool findLength )
{
	bool visited[ 10002 ] = { false };
	int path[ 10002 ] = { 0 };
	int last = start,curr;
	len = 0;
	queue<int> q;
	q.push( start );
	while ( !q.empty() )
	{
		curr = q.front();
		visited[ curr ] = true;
		q.pop();
		last = curr;
		for ( vector<int>::const_iterator it = v[ curr ].begin(); it != v[ curr ].end(); ++it )
			if ( !visited[ *it ] )
			{
				q.push( *it );
				if ( findLength )
					path[ *it ] = curr;
			}
	}
		//cout << "\n PATH ->";
		for ( int i = last ; findLength&&  i != start ; i = path[ i ] )
		//{
			len++;
//			cout << " " << i;
	//	}
		//cout << " " << start;
		
		return last;
}



int main()
{
	int n,a,b,last,len;
	cin >> n;
	v = vvi( n+1 );
	for ( int i = 0; i < n - 1; ++i )
	{
		cin >> a >> b;
		v[ a ].push_back( b );
		v[ b ].push_back( a );
	}
	last = bfs( v , 1 , len,false );
	bfs( v , last , len,true );
	cout << "\n" << len<<endl;

	return 0;
}

