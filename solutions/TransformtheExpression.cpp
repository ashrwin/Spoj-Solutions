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

string rpn( const string &exp )
{
	stack<char> s;
	string ret;
	char c;
	string op = "+-*/^";
	rep( i , 0 , exp.size() )
	{
		c = exp[ i ];
		if ( c == '(' || op.find(c)!=string::npos)
			s.push( c );
		else if ( c == ')' )
		{
			while ( !s.empty() && s.top() != '(' )
			{
				ret.push_back( s.top() );
				s.pop();
			}
			if ( !s.empty() && s.top() == '(' ) s.pop();
		}
		else ret.push_back( c );
	}
	while ( !s.empty() ) { ret.push_back( s.top() ); s.pop(); };
	return ret;
}



int main()
{
	int n;
	cin >> n;
	string exp;
	rep( i , 0 , n )
	{
		cin >> exp;
		cout<<"\n"<<rpn( exp );
	}
	return 0;
}

