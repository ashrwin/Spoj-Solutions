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


string series( const int &a , const int &b , const int &c )
{
	stringstream ret;
	if ( b - a == c - b )
		ret << "AP " << c + ( b - a );
	else ret << "GP " << c*( b / a );
	return ret.str();
}
int main()
{
	int a,b,c;
	while (true )
	{
		cin >> a>>b>>c;
		if ( !a && !b && !c )	break;
		cout<<"\n"<<series( a , b , c );
	}
	return 0;
}

