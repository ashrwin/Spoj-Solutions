#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

string mobile( vector<int> &v )
{
	stack<int> s;
	int cur = 1;
	for ( int i = 0; i < (int)v.size(); ++i )
	{
		while ( !s.empty() && s.top() == cur  )
		{
			s.pop();
			cur++;
		}
		if ( v[ i ] == cur )
			cur++;
		else if ( s.empty() || v[ i ] < s.top() )
			s.push( v[ i ] );
		else return "no";
	}
	return "yes";
}

int main()
{
	int n ;
	while ( 1 )
	{
		cin >> n;
		if ( !n )break;
		vector<int> v( n );
		for ( int i = 0; i < n; ++i )
			cin >> v[ i ];
		cout << "\n" << mobile( v );
	}
}
