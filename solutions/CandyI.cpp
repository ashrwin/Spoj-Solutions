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


int smallestMoves( int n )
{
	vector<int> v;
	int temp,sum=0;
	rep( i , 0 , n )
	{
		cin >> temp;
		v.push_back( temp );
		sum += temp;
	}
	if ( (double)sum / n - sum / n )
		return -1;
	int avg = sum / n;
	sort( v.begin() , v.end() );
	int ret = 0;
	rep( i , 0 , n )
	{
		if ( v[ i ] >= avg )	break;
		ret += ( avg - v[ i ] );
	}
	return ret;
}




int main()
{
	int n;
	while (true )
	{
		cin >> n;
		if ( n==-1 )	break;
		cout << "\n" << smallestMoves( n ) << endl;
	}
	return 0;
}

