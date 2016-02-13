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



string decrypt( const string &s ,int n)
{
	string ret;
	int seg = s.size() / n,pos;
	rep( offset , 0 , n )
	{
		rep( i , 0 , seg )
		{
			int cseg = i*n;
			if ( i % 2 )
				pos = cseg + n-1 - offset;
			else pos = cseg+offset;
			ret.push_back( s[ pos ] );
		}
	}
	return ret;
}

int main()
{
	int n;
	string s;
	while (true )
	{
		cin >> n;
		if ( !n )	break;
		cin >> s;
		cout << "\n" << decrypt( s , n);
	}
	return 0;
}

