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


int match( int n )
{
	vector<int> m( n ),f(n);
	int ret = 0,t;
	rep( i , 0 , n ){ cin >> t; m[i]=t; }
	rep( i , 0 , n ){ cin >> t; f[i]= t ; }
	sort( m.begin() , m.end() );
	sort( f.begin() , f.end() );
	rep( i , 0 , n ) ret += m[ i ] * f[ i ];
	return ret;
}




int main()
{
	int t,n;
	cin >> t;
	rep(i,0,t)
	{
		cin >> n;
		cout<<"\n"<<match( n );
	}
	return 0;
}

